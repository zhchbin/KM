// URL: http://oj.leetcode.com/problems/unique-paths/
//
// Problem: A robot is located at the top-left corner of a m x n grid (marked
//          'Start' in the diagram below). The robot can only move either down
//          or right at any point in time. The robot is trying to reach the
//          bottom-right corner of the grid (marked 'Finish' in the diagram
//          below).
//
//          How many possible unique paths are there?
//
// Reference : http://leetcode.com/2010/11/unique-paths.html

#include <iostream>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    const int kMaxM = 102;
    const int kMaxN = 102;
    int mat[kMaxM][kMaxN] = {0};
    mat[m][n + 1] = 1;
    for (int i = m; i >= 1; --i) {
      for (int j = n; j >= 1; --j)
        mat[i][j] = mat[i + 1][j] + mat[i][j + 1];
    }

    return mat[1][1];
  }
};

int main(int argc, char *argv[]) {
  cout << Solution().uniquePaths(3, 6) << endl;

  return 0;
}
