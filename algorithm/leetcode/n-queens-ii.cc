// URL: http://oj.leetcode.com/problems/n-queens-ii/
#include <cstring>
#include <iostream>

using namespace std;

#define SIZE 1000

class Solution {
 public:
  int totalNQueens(int n) {
    memset(grid, false, sizeof(grid[0][0]) * SIZE * SIZE);
    cnt = 0;
    dfs(0, n);

    return cnt;
  }

  void dfs(int r, int n) {
    if (r == n) {
      cnt++;
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (isValid(r, i, n)) {
        grid[r][i] = true;
        dfs(r + 1, n);
        grid[r][i] = false;
      }
    }
  }

  bool isValid(int r, int c, int n) {
    int i = r, j = c;
    for (; i >= 0; --i)
      if (grid[i][j])
        return false;

    i = r, j = c;
    for (; i >= 0 && j >= 0; --i, --j)
      if (grid[i][j])
        return false;

    i = r, j = c;
    for (; i >= 0 && j < n; --i, ++j)
      if (grid[i][j])
        return false;

    return true;
  }

  bool grid[SIZE][SIZE];
  int cnt;
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.totalNQueens(4) << endl;
  return 0;
}
