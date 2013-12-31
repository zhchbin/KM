// URL: http://oj.leetcode.com/problems/search-in-rotated-sorted-array/
//
// Problem: Suppose a sorted array is rotated at some pivot unknown to you
//          beforehand.
//          (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//          You are given a target value to search. If found in the array return
//          its index, otherwise return -1.
//          You may assume no duplicate exists in the array.

#include <cassert>
#include <iostream>
using namespace std;

class Solution {
 public:
  int search(int A[], int n, int target) {
    int index;
    // O(n), sign...
    for (index = 0; index < n - 1; ++index) {
      if (A[index] > A[index + 1])
        break;
    }

    int r = n - index - 1;
    int hd = 0;
    int tl = n - 1;
    while (hd <= tl) {
      int mid = hd + ((tl - hd) >> 1);
      int realMid = mid - r >= 0 ? mid - r : mid - r + n;
      if (A[realMid] == target)
        return realMid;
      else if (A[realMid] > target)
        tl = mid - 1;
      else
        hd = mid + 1;
    }

    return -1;
  }
};

class BetterSolution {
 public:
  int search(int A[], int n, int target) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (A[mid] == target)
        return mid;

      if (A[l] <= A[mid]) {
        if (A[l] <= target && target < A[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else {
        if (A[mid] < target && target <= A[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {4, 5, 6, 7, 0, 1, 2};
  Solution s;
  BetterSolution s1;
  assert(1 == s.search(A, sizeof(A) / sizeof(A[0]), 5));
  assert(6 == s.search(A, sizeof(A) / sizeof(A[0]), 2));
  assert(-1 == s.search(A, sizeof(A) / sizeof(A[0]), 10));
  assert(-1 == s.search(A, sizeof(A) / sizeof(A[0]), -1));
  assert(1 == s1.search(A, sizeof(A) / sizeof(A[0]), 5));
  assert(6 == s1.search(A, sizeof(A) / sizeof(A[0]), 2));
  assert(-1 == s1.search(A, sizeof(A) / sizeof(A[0]), 10));
  assert(-1 == s1.search(A, sizeof(A) / sizeof(A[0]), -1));

  return 0;
}
