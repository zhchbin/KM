#ifndef  WORKER_H_
#define  WORKER_H_

#include "common.h"

namespace echo_server {

class ThreadPool;

class Worker {
 public:
  Worker(ThreadPool& pool);
  void operator()();

 private:
  ThreadPool& thread_pool_; 
};

}  // namespace echo_server

#endif  // WORKER_H_
