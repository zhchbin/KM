// URL: http://oj.leetcode.com/problems/n-queens/

#include <cstring>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string> > solveNQueens(int n) {
    memset(board, false, sizeof(board));
    result.clear();
    dfs(0, n);

    return result;
  }

  void dfs(int r, int n) {
    if (r == n) {
      vector<string> sol;
      for (int i = 0; i < n; ++i) {
        string temp(n, '.');
        for (int j = 0; j < n; ++j) {
          if (board[i][j]) {
            temp[j] = 'Q';
            break;
          }
        }
        sol.push_back(temp);
      }
      result.push_back(sol);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (isValid(r, i, n)) {
        board[r][i] = true;
        dfs(r + 1, n);
        board[r][i] = false;
      }
    }
  }

  bool isValid(int x, int y, int n) {
    int i, j;
    for (i = 0; i < x; ++i) {
      if (board[i][y])
        return false;
    }

    i = x; j = y;
    while (i >= 0 && j >= 0) {
      if (board[i--][j--])
        return false;
    }

    i = x; j = y;
    while (i >= 0 && j < n) {
      if (board[i--][j++])
        return false;
    }

    return true;
  }

  bool board[1000][1000];
  vector<vector<string> > result;
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<string> > solutions = s.solveNQueens(8);
  for (int i = 0; i < solutions.size(); ++i) {
    for (int j = 0; j < solutions[i].size(); ++j)
      cout << solutions[i][j] << endl;
    cout << endl;
  }

  return 0;
}
