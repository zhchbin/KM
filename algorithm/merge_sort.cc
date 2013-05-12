// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include <ctime>
#include <cstdlib>
#include <cassert>
#include <iostream>

#define MAX 0x4f4f4f4f
#define SIZE 1000000
#define TEST_TIMES 100

int data[SIZE];
int left[SIZE];
int right[SIZE];

void check(int arr[], int l) {
  for (int i = 0; i < l - 1; ++i) {
    assert(arr[i] <= arr[i + 1]);
  }
}

// |arr| is an array, and p, q, r are indices numbering elements of the array
// such that p <= q < r. The procedure assumes that the subarrays |arr[p..q]|
// and |arr[q..r]| are in sorted order. It merges them to form a single sorted
// subarray that replaces the current subarray |arr[p..r]|.
void merge(int arr[], int p, int q, int r) {
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

void mergesort(int arr[], int p, int r) {
  if (p < r - 1) {
    int mid = (p + r) / 2;
    mergesort(arr, p, mid);
    mergesort(arr, mid, r);
    merge(arr, p, mid, r);
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));

  for (int t = 0; t < TEST_TIMES; t++) {
    for (int i = 0; i < SIZE; ++i) {
      data[i] = rand() % (2 * SIZE);
    }
    int n = sizeof(data) / sizeof(data[0]);

    clock_t begin = clock(); 
    mergesort(data, 0, n);
    clock_t end = clock(); 

    check(data, n);
    std::cout << "Pass: " << t << " Time: " << (end - begin) << std::endl; 
  }

  return 0;
}
