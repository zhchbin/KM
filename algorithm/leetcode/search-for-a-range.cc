// URL: http://oj.leetcode.com/problems/search-for-a-range/

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(int A[], int n, int target) {
    vector<int> range(2);
    range[0] = lower_bound(A, n, target);
    range[1] = upper_bound(A, n, target);
    return range;
  }

  int lower_bound(int A[], int n, int target) {
    assert(n > 0);
    int l = 0;
    int h = n;
    while (l < h) {
      int mid = l + ((h - l) >> 1);
      if (A[mid] >= target)
        h = mid;
      else
        l = mid + 1;
    }

    return A[l] == target ? l : -1;
  }

  int upper_bound(int A[], int n, int target) {
    assert(n > 0);
    int l = 0;
    int h = n;
    while (l < h) {
      int mid = l + ((h - l) >> 1);
      if (A[mid] <= target)
        l = mid + 1;
      else
        h = mid;
    }

    return A[l - 1] == target ? l - 1 : -1;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {5, 7, 7, 8, 8, 10};
  Solution s;
  int n = sizeof(A) / sizeof(A[0]);
  vector<int> range = s.searchRange(A, n, 8);
  assert(range[0] == 3);
  assert(range[1] == 4);

  range = s.searchRange(A, n, 11);
  assert(range[0] == -1);
  assert(range[1] == -1);

  return 0;
}
