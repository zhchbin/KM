#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#include "tcp_server.h"
#include "thread_pool.h"

int main(int argc, char *argv[]) {
  short port = 3500;
  short num_of_threads = 4;
  int opt;

  while ((opt = getopt(argc, argv, "p:n:")) != -1) {
    switch(opt) {
      case 'p':
        port = atoi(optarg);
        break;
      case 'n':
        num_of_threads = atoi(optarg);
        break;
      default:
        fprintf(stderr, "Unkonw options: %c\n.", opt);
        return 1;
    }
  }

  if (port == 0 || num_of_threads == 0) {
    fprintf(stderr, "Invalid options.\n");
    return 1;
  }
  fprintf(stdout,
          "Configurations: Port: %d, Num of Threads: %d\n",
          port,
          num_of_threads);

  echo_server::TcpServer tcp_server(port);
  echo_server::ThreadPool thread_pool(num_of_threads); 
  tcp_server.Run(thread_pool);

  return 0;
}
