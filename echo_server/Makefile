CC=g++
CFLAGS=-c -Wall --std=c++11 -O2
LD_LIBRARY=-lpthread

all: echo_server

echo_server: thread_pool.o worker.o main.o tcp_server.o
	$(CC) thread_pool.o worker.o tcp_server.o main.o -o echo_server $(LD_LIBRARY)

thread_pool.o: thread_pool.cc
	$(CC) $(CFLAGS) thread_pool.cc -o thread_pool.o

worker.o: worker.cc
	$(CC) $(CFLAGS) worker.cc -o worker.o

tcp_server.o: tcp_server.cc
	$(CC) $(CFLAGS) tcp_server.cc -o tcp_server.o

main.o: main.cc
	$(CC) $(CFLAGS) main.cc -o main.o

clean:
	rm *.o echo_server
