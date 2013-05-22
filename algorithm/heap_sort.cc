// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

#include "array_util.h"

#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)
#define SIZE 1000000

int arr[SIZE]; 

void MaxHeapify(int arr[], int size, int i) {
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest = i;
  if (l < size && arr[l] > arr[largest])
    largest = l;
  if (r < size && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    std::swap(arr[i], arr[largest]);
    MaxHeapify(arr, size, largest);
  }
}

void BuildMaxHeap(int arr[], int size) {
  for (int i = size / 2; i >= 0; i--) {
    MaxHeapify(arr, size, i);
  }
}

void HeapSort(int arr[], int size) {
  BuildMaxHeap(arr, size);
  for (int i = size - 1; i > 0; --i) {
    std::swap(arr[i], arr[0]);
    MaxHeapify(arr, i, 0); 
  }
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 100; i++) {
    RandomInitArray(arr, SIZE);

    clock_t begin = clock(); 
    HeapSort(arr, SIZE);
    clock_t end = clock();

    assert(IsArraySorted(arr, SIZE));
    std::cout << "Pass: " << i << " Time: " << (end - begin) << std::endl; 
  }

  return 0;
}
