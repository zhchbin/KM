// URL: http://oj.leetcode.com/problems/first-missing-positive/
//
// Problem: Given an unsorted integer array, find the first missing positive
//          integer.
//
// Solution: Learn from others.

#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(int A[], int n) {
    for (int i = 0; i < n; ++i) {
      if (A[i] != i + 1 && A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i]) {
        std::swap(A[i], A[A[i] - 1]);
        --i;
      }
    }

    for (int i = 0; i < n; i++) {
      if (A[i] != i + 1)
        return i + 1;
    }

    return n + 1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int arr[] = {3, 4, -1, 1};
  cout << s.firstMissingPositive(arr, 4);

  return 0;
}
