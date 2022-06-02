#include<iostream>
#include<mutex>
#include <shared_mutex>
#include <thread>

class ThreadSafeCounter {
 public:
  ThreadSafeCounter() = default;
 
  // Multiple threads/readers can read the counter's value at the same time.
  unsigned int get() const {
    std::shared_lock<std::shared_timed_mutex> lock(mutex_);
    return value_;
  }
 
  // Only one thread/writer can increment/write the counter's value.
  unsigned int increment() {
    std::unique_lock<std::shared_timed_mutex> lock(mutex_);
    return ++value_;
  }
 
  // Only one thread/writer can reset/write the counter's value.
  void reset() {
    std::unique_lock<std::shared_timed_mutex> lock(mutex_);
    value_ = 0;
  }
 
 private:
  mutable std::shared_timed_mutex mutex_;
  unsigned int value_ = 0;
};

int main0(int, char**) {

    ThreadSafeCounter counter;

    auto increment_and_print = [&counter]() {
    for (int i = 0; i < 3; i++) {
      std::cout << std::this_thread::get_id() << ' ' << counter.increment() << '\n';
 
      // Note: Writing to std::cout actually needs to be synchronized as well
      // by another std::mutex. This has been omitted to keep the example small.
    }
  };
    std::thread thread1(increment_and_print);
    std::thread thread2(increment_and_print);
    thread1.join();
    thread2.join();
    std::cout << "Hello, world!\n";
    return 0;
}
