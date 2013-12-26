// URL: http://oj.leetcode.com/problems/sort-colors/
//
// Problem: Given an array with n objects colored red, white or blue, sort them
//          so that objects of the same color are adjacent, with the colors in
//          the order red, white and blue.
//          Here, we will use the integers 0, 1, and 2 to represent the color
//          red, white, and blue respectively.
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
 public:
  void sortColors(int A[], int n) {
    int count[3];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; ++i)
      count[A[i]] += 1;

    int j = 0;
    for (int i = 0; i < 3; ++i) {
      while (count[i] != 0) {
        A[j++] = i;
        count[i] -= 1;
      }
    }
  }
};

class BetterSolution {
 public:
  void sortColors(int A[], int n) {
    int i = -1;
    int j = n;
    for (int k = 0; k < j; ++k) {
      if (A[k] == 0)
        std::swap(A[k], A[++i]);
      else if (A[k] == 2)
        std::swap(A[k--], A[--j]);
    }
  }
};

int main(int argc, char *argv[]) {
  int colors[] = {0, 2, 0, 1, 2, 1, 1};
  int n = sizeof(colors) / sizeof(int);
  BetterSolution s;
  s.sortColors(colors, n);
  for (int i = 0; i < n; ++i)
    cout << colors[i] << " ";
  cout << endl;

  return 0;
}
