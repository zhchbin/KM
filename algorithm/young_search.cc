// Copyright (c) 2013 The zhchbin Authors. All rights reserved.

// Corresponding blog : http://blog.csdn.net/v_july_v/article/details/7085669

#include <cassert>

#define ROW 4
#define COL 4

bool YoungSearch(int arr[][COL], int key) {
  int i = 0, j = COL - 1;
  int var = arr[i][j];
  while (true) {
    if (var == key)
      return true;
    else if (key > var && i < ROW - 1)
      var = arr[++i][j];
    else if (key < var && j > 0)
      var = arr[i][--j];
    else
      return false;
  }
}

int main(int argc, char *argv[]) {
  int arr[ROW][COL] = {
    {1, 2, 8, 9}, 
    {2, 4, 9, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}
  };

  assert(YoungSearch(arr, 6));
  assert(YoungSearch(arr, 15));
  assert(!YoungSearch(arr, 16));
  assert(!YoungSearch(arr, 3));

  return 0;
}
