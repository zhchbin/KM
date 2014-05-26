#include "thread_pool.h"

#include "worker.h"

namespace echo_server {

ThreadPool::ThreadPool(size_t num_of_threads) : stop_(false) {
  for (size_t i = 0; i < num_of_threads; ++i)
    worker_threads_.push_back(std::thread(Worker(*this)));
}

ThreadPool::~ThreadPool() {
  stop_ = true;
  condition_.notify_all();
  for (size_t i = 0; i < worker_threads_.size(); ++i)
    worker_threads_[i].join();
}

void ThreadPool::enqueue(Task task) {
  {
    std::unique_lock<std::mutex> lock(task_queue_mutex_);
    task_queue_.push_back(task);
  }

  condition_.notify_one();
}

}  // namespace echo_server
