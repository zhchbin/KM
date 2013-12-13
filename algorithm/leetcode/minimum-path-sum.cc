// URL: http://oj.leetcode.com/problems/minimum-path-sum/
//
// Problem: Given a m x n grid filled with non-negative numbers, find a path
//          from top left to bottom right which minimizes the sum of all numbers
//          along its path.
//
//          Note: You can only move either down or right at any point in time.
//
// Solution: DP, dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j].

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int> > &grid) {
    if (grid.empty())
      return 0;

    static const int kMaxM = 200;
    static const int kMaxN = 200;

    int dp[kMaxM][kMaxN] = {0};
    int m = grid.size();
    int n = grid[0].size();
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int i = m - 2; i >= 0; --i)
      dp[i][n - 1] = grid[i][n - 1] + dp[i + 1][n - 1];
    for (int i = n - 2; i >= 0; --i)
      dp[m - 1][i] = grid[m - 1][i] + dp[m - 1][i + 1];

    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j)
        dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
    }

    return dp[0][0];
  }
};

int main(int argc, char *argv[]) {
  int arr[3][3] = {
                  {1, 2, 1},
                  {1, 0, 1},
                  {2, 2, 1}
                };
  vector<vector<int> > grid;
  for (int i = 0; i < 3; ++i) {
    vector<int> v(arr[i], arr[i] + 3);
    grid.push_back(v);
  }
  Solution s;
  cout << s.minPathSum(grid) << endl;

  return 0;
}
