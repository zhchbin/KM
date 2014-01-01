// URL: http://oj.leetcode.com/problems/spiral-matrix-ii/
//
// Problem: Given an integer n, generate a square matrix filled with elements
//          from 1 to n2 in spiral order.
//          For example, Given n = 3, you should return the following matrix:
//          [
//           [ 1, 2, 3 ],
//           [ 8, 9, 4 ],
//           [ 7, 6, 5 ]
//          ]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > matrix;
    for (int i = 0; i < n; ++i)
      matrix.push_back(vector<int>(n));
    if (n == 1) {
      matrix[0][0] = 1;
      return matrix;
    }

    int x, y;
    int level = 0;
    int cnt = 1;
    while (cnt < n * n) {
      x = y = level;
      for (; y < n - level - 1; ++y)
        matrix[x][y] = cnt++;
      for (; x < n - level -1; ++x)
        matrix[x][y] = cnt++;
      for (; y > level; --y)
        matrix[x][y] = cnt++;
      for (; x > level; --x)
        matrix[x][y] = cnt++;
      level++;
    }
    if (n % 2 != 0)
      matrix[level][level] = n * n;

    return matrix;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > matrix = s.generateMatrix(4);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  return 0;
}
