// URL: http://oj.leetcode.com/problems/search-insert-position/
//
// Problem: Given a sorted array and a target value, return the index if the
// target is found. If not, return the index where it would be if it were
// inserted in order.
//
// Solution: Binary search.
//
#include <cassert>
using namespace std;

class Solution {
 public:
  int searchInsert(int A[], int n, int target) {
    return binarySearch(A, 0, n - 1, target);
  }

  int binarySearch(int A[], int hd, int tl, int target) {
    if (hd > tl)
      return hd;

    int mid = (hd + tl) >> 1;
    if (A[mid] == target) {
      return mid;
    } else if (A[mid] > target) {
      return binarySearch(A, hd, mid - 1, target);
    } else {
      return binarySearch(A, mid + 1, tl, target);
    }
  }
};

int main(int argc, char *argv[]) {
  int arr[] = {1, 3, 5, 6};
  Solution s;
  assert(s.searchInsert(arr, 4, 5) == 2);
  assert(s.searchInsert(arr, 4, 2) == 1);
  assert(s.searchInsert(arr, 4, 7) == 4);
  assert(s.searchInsert(arr, 4, 0) == 0);

  return 0;
}
