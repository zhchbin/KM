// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

#ifndef  ARRAY_UTIL_H_
#define  ARRAY_UTIL_H_

typedef unsigned int uint32;

void RandomInitArray(int arr[], uint32 size);

// Returns true if the |arr| is sorted from small to large.
bool IsArraySorted(int arr[], uint32 size);

#endif  // ARRAY_UTIL_H_
