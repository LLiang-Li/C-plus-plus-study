#include <iostream>
#include "thread_pool.hpp"

ThreadPool::ThreadPool() : is_running_(true){
  this->core_num_ = sysconf(_SC_NPROCESSORS_ONLN);
  if(this->core_num_ < 1) this->core_num_ = 1;
}

ThreadPool::ThreadPool(long core_num):core_num_(core_num), is_running_(true){}

ThreadPool::~ThreadPool(){
  
  int a = 0;
  while(task_.size()) {
    if(a < 10)
      std::cout << "size is" << task_.size() << '\n';
    a = a >10 ? 11 : a + 1;
    
  };
  is_running_ = false;
  std::cout << "~ThreadPool\n";
  {
    std::unique_lock lock{lock_};
    task_.clear();
  }
  cv_.notify_all();
  int index = 0;
  for(auto & th : th_){
    if(th.joinable()){
      
      std::cout << index << " join start\n";
      th.join();
      //std::cout << index << " join end\n";
      index++;
    }
  }
}

void ThreadPool::Start(){
  for(uint8_t i = 0; i < core_num_; i++){
    auto task = std::thread([this,i](){
      func run_task;
      while(is_running_){
        {
          std::unique_lock lock{lock_};
          cv_.wait(lock, [this](){ return (task_.size() > 0)||(!is_running_);});
        // }
        // {
        //   std::lock_guard lock{lock_};
          if(task_.size() <= 0) continue;
          run_task = task_.front();
          task_.pop_front();
        }
        run_task(static_cast<int>(i));
        //std::cout << "**task:" << static_cast<int>(i) << "**\n";
      }
    });
    // th_.emplace_back(std::move(task));
    th_.push_back(std::move(task));
  }
  std::cout << "Pool Init Complete!\n"  << "core num is " << core_num_ << '\n';
}




void ThreadPool::AddTask(func cb){
  {
    std::lock_guard lk{lock_};
    task_.push_back(cb);
  }
  cv_.notify_one();
}
