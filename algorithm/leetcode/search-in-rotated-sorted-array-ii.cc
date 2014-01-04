// URL: http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
//
// Problem: Follow up for "Search in Rotated Sorted Array":
//          What if duplicates are allowed?
//          Would this affect the run-time complexity? How and why?
//          Write a function to determine if a given target is in the array.

#include <cassert>

class Solution {
 public:
  bool search(int A[], int n, int target) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (A[mid] == target)
        return true;

      if (A[l] < A[mid]) {
        if (target >= A[l] && target < A[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else if (A[l] > A[mid]) {
        if (target > A[mid] && target <= A[r])
          l = mid + 1;
        else
          r = mid - 1;
      } else {
        l++;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {1, 3, 1, 1, 1};
  int B[] = {5, 1, 3};
  Solution s;
  assert(s.search(A, sizeof(A) / sizeof(A[0]), 3));
  assert(s.search(A, sizeof(A) / sizeof(A[0]), 1));
  assert(!s.search(A, sizeof(A) / sizeof(A[0]), 5));
  assert(!s.search(A, sizeof(A) / sizeof(A[0]), -1));
  assert(s.search(B,  sizeof(B) / sizeof(B[0]), 3));
  return 0;
}
