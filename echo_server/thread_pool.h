#ifndef  THREAD_POOL_H_
#define  THREAD_POOL_H_

#include <condition_variable>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include "common.h"

namespace echo_server {

class Worker;

class ThreadPool {
 public:
  typedef std::function<void()> Task;

  ThreadPool(size_t num_of_threads);
  virtual ~ThreadPool();
  
  void enqueue(Task task);

 private:
  friend class Worker;

  typedef std::vector<std::thread> WorkerThreads;
  WorkerThreads worker_threads_;

  std::deque<Task> task_queue_;

  std::mutex task_queue_mutex_;
  std::condition_variable condition_;

  bool stop_;

  DISALLOW_COPY_AND_ASSIGN(ThreadPool);
};

} // namespace echo_server

#endif  // THREAD_POOL_H_
