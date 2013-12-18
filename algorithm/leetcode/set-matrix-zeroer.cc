// URL: http://oj.leetcode.com/problems/set-matrix-zeroes/
//
// Problem: Given a m x n matrix, if an element is 0, set its entire row and
//          column to 0. Do it in place.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    int row = matrix.size();
    int column = matrix[0].size();
    bool first_row_has_zero = false;
    bool first_column_has_zero = false;
    for (int i = 0; i < column; ++i) {
      if (matrix[0][i] == 0) {
        first_row_has_zero = true;
        break;
      }
    }

    for (int i = 0; i < row; ++i) {
      if (matrix[i][0] == 0) {
        first_column_has_zero = true;
        break;
      }
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < column; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < column; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (first_row_has_zero) {
      for (int i = 0; i < column; ++i)
        matrix[0][i] = 0;
    }

    if (first_column_has_zero) {
      for (int i = 0; i < row; ++i)
        matrix[i][0] = 0;
    }
  }
};

int main(int argc, char *argv[]) {
  int arr[][3] = {{0, 2, 3},
                  {2, 1, 1},
                  {1, 2, 1}};
  Solution s;
  vector<vector<int> > matrix;
  for (int i = 0; i < 3; ++i)
    matrix.push_back(vector<int>(arr[i], arr[i] + 3));
  s.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  return 0;
}
