// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iostream>

#include "array_util.h"

#define MAX 0x4f4f4f4f
#define SIZE 1000000
#define TEST_TIMES 100

int data[SIZE];
int left[SIZE];
int right[SIZE];

// |arr| is an array, and p, q, r are indices numbering elements of the array
// such that p <= q < r. The procedure assumes that the subarrays |arr[p..q]|
// and |arr[q..r]| are in sorted order. It merges them to form a single sorted
// subarray that replaces the current subarray |arr[p..r]|.
void Merge(int arr[], int p, int q, int r) {
  int n1 = q - p;
  int n2 = r - q;

  for (int i = 0; i < n1; i++)
    left[i] = arr[p + i];
  left[n1] = MAX;

  for (int i = 0; i < n2; i++)
    right[i] = arr[q + i];
  right[n2] = MAX;

  int i, j;
  i = j = 0;

  for (int k = p; k < r; k++)
    if (left[i] > right[j])
      arr[k] = right[j++];
    else
      arr[k] = left[i++];
} 

void MergeSort(int arr[], int p, int r) {
  if (p < r - 1) {
    int mid = (p + r) / 2;
    MergeSort(arr, p, mid);
    MergeSort(arr, mid, r);
    Merge(arr, p, mid, r);
  }
}

int main(int argc, char *argv[]) {
  for (int t = 0; t < TEST_TIMES; t++) {
    RandomInitArray(data, SIZE);

    clock_t begin = clock(); 
    MergeSort(data, 0, SIZE);
    clock_t end = clock(); 
    std::cout << "Pass: " << t << " Time: " << (end - begin) << std::endl; 

    assert(IsArraySorted(data, SIZE));
  }

  return 0;
}
