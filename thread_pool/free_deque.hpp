#pragma once
#include <stdint.h>
#include <iostream>
#include <atomic>
template <typename T, size_t N>
class LockFreeQueue {
public:
    static_assert((N & (N - 1)) == 0, "N must be power of two");

    LockFreeQueue() {
        for (size_t i = 0; i < N; ++i)
            buffer_[i].seq.store(i, std::memory_order_relaxed);
    }

    bool enqueue(T v) {
        Cell* cell;
        size_t pos = tail_.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buffer_[pos & mask_];
            size_t seq = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = (intptr_t)seq - (intptr_t)pos;

            if (diff == 0) {
                if (tail_.compare_exchange_weak(
                        pos, pos + 1, std::memory_order_relaxed))
                    break;
            } else if (diff < 0) {
                return false; // full
            } else {
                pos = tail_.load(std::memory_order_relaxed);
            }
        }

        cell->data = std::move(v);
        cell->seq.store(pos + 1, std::memory_order_release);
        return true;
    }

    bool dequeue(T& v) {
        Cell* cell;
        size_t pos = head_.load(std::memory_order_relaxed);

        for (;;) {
            cell = &buffer_[pos & mask_];
            size_t seq = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = (intptr_t)seq - (intptr_t)(pos + 1);

            if (diff == 0) {
                if (head_.compare_exchange_weak(
                        pos, pos + 1, std::memory_order_relaxed))
                    break;
            } else if (diff < 0) {
                return false; // empty
            } else {
                pos = head_.load(std::memory_order_relaxed);
            }
        }

        v = std::move(cell->data);
        cell->seq.store(pos + N, std::memory_order_release);
        return true;
    }

private:
    struct Cell {
        std::atomic<size_t> seq;
        T data;
    };

    static constexpr size_t mask_ = N - 1;
    alignas(64) std::atomic<size_t> head_{0};
    alignas(64) std::atomic<size_t> tail_{0};
    Cell buffer_[N];
};
