// URL: http://oj.leetcode.com/problems/valid-sudoku/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char> >& board) {
    bool row[10];
    bool col[10];

    for (int i = 0; i < 9; ++i) {
      memset(row, false, sizeof(row));
      memset(col, false, sizeof(col));

      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          short cur = board[i][j] - '0';
          if (row[cur])
            return false;

          row[cur] = true;
        }

        if (board[j][i] != '.') {
          short cur = board[j][i] - '0';
          if (col[cur])
            return false;

          col[cur] = true;
        }
      }
    }

    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        memset(row, false, sizeof(row));
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            if (board[i + k][j + l] != '.') {
              short cur = board[i + k][j + l] - '0';
              if (row[cur])
                return false;

              row[cur] = true;
            }
          }
        }
      }
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  char data[][9] = {
                     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
                   };
  vector<vector<char> > board;
  for (int i = 0; i < 9; ++i)
    board.push_back(vector<char>(data[i], data[i] + 9));
  Solution s;
  cout << s.isValidSudoku(board) << endl;

  return 0;
}
