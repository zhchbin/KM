// URL: http://oj.leetcode.com/problems/maximum-subarray/
//
// Problem: Find the contiguous subarray within an array (containing at least
//          one number) which has the largest sum.
//
// Solution: DP. dp[i] = max(dp[i - 1] + A[i], A[i]);
//

#include <cassert>

class Solution {
 public:
  int maxSubArray(int A[], int n) {
    int* dp = new int[n];
    dp[0] = A[0];
    int max = A[0];

    for (int i = 1; i < n; i++) {
      if (A[i] < dp[i - 1] + A[i])
        dp[i] = dp[i - 1] + A[i];
      else
        dp[i] = A[i];

      if (dp[i] > max)
        max = dp[i];
    }

    delete []dp;
    return max;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution s;
  assert(6 == s.maxSubArray(A, sizeof(A) / sizeof(int)));

  return 0;
}
