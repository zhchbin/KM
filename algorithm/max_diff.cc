// Copyright (c) 2013 The zhchbin Authors. All rights reserved.
//
//题目：在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。
//      例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5
//      的结果。

#include <iostream>
#include <climits>

#define SIZE 8

int main(int argc, char *argv[]) {
  int arr[SIZE] = {2, 4, 1, 16, 7, 5, 11, 9};
  int m[SIZE];
  m[0] = arr[0];

  int result = INT_MIN;
  for (int i = 1; i < SIZE; i++) {
    m[i] = m[i - 1] < arr[i] ? m[i - 1] : arr[i];
    if (arr[i] - m[i - 1] > result) 
      result = arr[i] - m[i - 1];
  }

  std::cout << result << std::endl;
  return 0;
}
