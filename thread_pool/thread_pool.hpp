#pragma once
#include <thread>
#include <functional>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <unistd.h>
#include <deque>
#include <vector>

using func = std::function<void(int i)>;

class ThreadPool{
  public:
    ThreadPool(long core_num);
    ThreadPool();
    ~ThreadPool();
    void AddTask(func);
    void Start();
  private:
    long core_num_;
    std::mutex lock_;
    std::condition_variable cv_;
    std::vector<std::thread> th_;
    std::deque<func> task_;
    bool is_running_;
};
