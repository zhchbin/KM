#ifndef  TCP_SERVER_H_
#define  TCP_SERVER_H_

#include "common.h"

namespace echo_server {

class ThreadPool;

class TcpServer {
 public:
  TcpServer(unsigned short port);
  virtual ~TcpServer();

  void Run(ThreadPool& thread_pool);

 private:
  static void TaskOnThreadPool(int fd);

  int socket_fd_;
  DISALLOW_COPY_AND_ASSIGN(TcpServer);
};

}  // namespace echo_server

#endif  // TCP_SERVER_H_
