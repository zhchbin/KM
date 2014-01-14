// URL: http://oj.leetcode.com/problems/trapping-rain-water/
//
// Problem: Given n non-negative integers representing an elevation map where
//          the width of each bar is 1, compute how much water it is able to
//          trap after raining.
//          For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
// Solution: O(n) solution. for each bar, find the max height bar on the left
//           and right. then for this bar it can hold
//           min(max_left, max_right) - height

#include <iostream>
using namespace std;

class Solution {
 public:
  int trap(int A[], int n) {
    int ans = 0;
    int* lmh = new int[n];
    lmh[0] = 0;
    int maxh = A[0];
    for (int i = 1; i < n; ++i) {
      lmh[i] = maxh;
      if (A[i] > maxh)
        maxh = A[i];
    }

    maxh = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      int t = (lmh[i] > maxh ? maxh : lmh[i]);
      if (t > A[i])
        ans += (t - A[i]);
      if (maxh < A[i])
        maxh = A[i];
    }

    delete []lmh;
    return ans;
  }
};

int main() {
  int A[] = {5, 4, 1, 2};
  Solution s;
  cout << s.trap(A, sizeof(A) / sizeof(A[0])) << endl;
  return 0;
}
