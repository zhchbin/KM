// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iostream>

#include "array_util.h"

#define MAX 0x4f4f4f4f
#define SIZE 1000000
#define TEST_TIMES 100

int Partition(int data[], int hd, int tl) {
  int pivot = data[tl];
  int i = hd - 1;
  for (int j = hd; j < tl; ++j) {
    if (data[j] < pivot) {
      i++;
      std::swap(data[i], data[j]);
    }
  }
  std::swap(data[i + 1], data[tl]);

  return i + 1;
}

void QuickSort(int data[], int hd, int tl) {
  if (hd < tl) {
    int p = Partition(data, hd, tl);
    QuickSort(data, hd, p - 1);
    QuickSort(data, p + 1, tl);
  }
}

int main(int argc, char *argv[]) {
  int data[SIZE];

  for (int t = 0; t < TEST_TIMES; t++) {
    RandomInitArray(data, SIZE);

    clock_t begin = clock();
    QuickSort(data, 0, SIZE - 1);
    clock_t end = clock();
    std::cout << "Pass: " << t << " Time: " << (end - begin) << std::endl;

    assert(IsArraySorted(data, SIZE));
  }

  return 0;
}
