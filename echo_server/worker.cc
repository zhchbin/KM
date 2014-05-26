#include "worker.h"

#include <condition_variable>
#include <mutex>

#include "thread_pool.h"

namespace echo_server {

Worker::Worker(ThreadPool& pool) : thread_pool_(pool) {}

void Worker::operator()() {
  ThreadPool::Task task;
  while (true) {
    {
      std::unique_lock<std::mutex> lock(thread_pool_.task_queue_mutex_);
      while (!thread_pool_.stop_ && thread_pool_.task_queue_.empty())
        thread_pool_.condition_.wait(lock);

      if (thread_pool_.stop_)
        break;
      task = thread_pool_.task_queue_.front();
      thread_pool_.task_queue_.pop_front();
    } 

    task();
  }
}

}  // namespace echo_server
