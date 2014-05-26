#!/usr/bin/env python

import socket
import threading

host = '127.0.0.1'
port = 3500
timeout = 8
bufSize = 1024
testMeg = "Hello World"

class myThread(threading.Thread):
  def __init__(self, threadId):
    threading.Thread.__init__(self)
    self.threadId = threadId
  
  def run(self):
    try:
      s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      s.settimeout(None)
      s.connect((host, port))
      s.send(testMeg)
      recvMsg = s.recv(bufSize)
      if recvMsg != testMeg:
        print "Connection error occured."
    except Exception, e:
      print "Cannot connect to server: " + repr(e)
    
if __name__ == '__main__':
  threads = []
  for i in range(0, 400):
    threads.append(myThread(i))

  for t in threads:
    t.start()

  for t in threads:
    t.join()
