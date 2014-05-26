#include "tcp_server.h"

#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "thread_pool.h"

namespace echo_server {

static const int kBufSize = 1024;
  
TcpServer::TcpServer(unsigned short port) {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  ASSERT(socket_fd >= 0, "Error on opening socket.");

  int option = 1;
  setsockopt(
      socket_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&option, sizeof(int));

  sockaddr_in serveraddr;
  bzero((char *)&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(port);
  int res = bind(socket_fd, (sockaddr *) &serveraddr, sizeof(serveraddr));
  ASSERT(res >= 0, "Error on binding.");

  res = listen(socket_fd, 10);
  ASSERT(res >= 0, "Error on listening.");

  socket_fd_ = socket_fd;
}

TcpServer::~TcpServer() {
  close(socket_fd_);
}
  
void TcpServer::Run(ThreadPool& thread_pool) {
  while (true) {
    int client_socket_fd = accept(socket_fd_, NULL, NULL);
    if (client_socket_fd < 0) {
      fprintf(stderr, "Error: accept.\n");
      continue;
    } 

    thread_pool.enqueue(
        std::bind(TcpServer::TaskOnThreadPool, client_socket_fd));
  }
}

// static
void TcpServer::TaskOnThreadPool(int fd) {
  char buf[kBufSize];
  bzero(buf, kBufSize);
  int n = read(fd, buf, kBufSize);
  if (n < 0)
    fprintf(stderr, "Error: read.\n");
  n = write(fd, buf, strlen(buf));
  if (n < 0)
    fprintf(stderr, "Error: write.\n");

  close(fd);
}

}  // namespace echo_server
