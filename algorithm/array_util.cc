// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#include "array_util.h"

#include <cstdlib>
#include <ctime>

static bool IsSranded = false;

void RandomInitArray(int arr[], uint32 size) {
  if (!IsSranded) {
    srand((unsigned int)time(NULL));
    IsSranded = true;
  }

  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % size;
  }
}

// Returns true if the |arr| is sorted from small to large.
bool IsArraySorted(int arr[], uint32 size) {
  for (int i = 1; i < size; ++i)
    if (arr[i - 1] > arr[i])
      return false;

  return true;
}
