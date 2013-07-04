// Copyright (c) 2013 The zhchbin Authors. All rights reserved.
//
// From: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html

#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

int FindMajority(int arr[], int length) {
  assert(length >= 1);
  int candidate = INT_MIN;
  int counter = 0;
  for (int i = 0; i < length; ++i) {
    if (candidate == INT_MIN) {
      candidate = arr[i];
      counter++;
    } else {
      candidate == arr[i] ? counter++ : counter--;
      if (counter == 0)
        candidate = INT_MIN;
    }
  }

  assert(counter > 0);
  return candidate;
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 2, 3, 2, 2, 3};
  cout << FindMajority(arr, sizeof(arr) / sizeof(arr[0])) << endl;

  int arr_2[10000];
  for (int i = 0; i < 10000; i++) {
    i % 2 ? arr_2[i] = 10 : arr_2[i] = i;
  }
  arr_2[10000 - 2] = 9;
  cout << FindMajority(arr_2, sizeof(arr_2) / sizeof(arr_2[0])) << endl;

  return 0;
}
