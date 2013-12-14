// URL: http://oj.leetcode.com/problems/rotate-image/
//
// Problem: You are given an n x n 2D matrix representing an image.
//          Rotate the image by 90 degrees (clockwise).
//          Follow up: Could you do this in-place?
//
// Solution: [0, 0], [0, 1], [0, 2] ← [0, 3], [1, 3], [2, 3]
//                      ↓                          ↑
//           [3, 0], [2, 0], [1, 0] → [3, 3], [3, 2], [3, 1]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int layer = 0; layer < n / 2; ++layer) {
      int first = layer;
      int last = n - 1 -layer;
      for (int i = first; i < last; ++i) {
        int offset = i - first;
        int top = matrix[layer][i];
        matrix[first][i] = matrix[last - offset][first];
        matrix[last - offset][first] = matrix[last][last - offset];
        matrix[last][last - offset] = matrix[i][last];
        matrix[i][last] = top;
      }
    }
  }
};

#define N 4

int main(int argc, char *argv[]) {
  int arr[N][N] = {
                    {1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}
                  };
  vector<vector<int> > matrix;
  for (int i = 0; i < N; ++i) {
    vector<int> t(arr[i], arr[i] + N);
    matrix.push_back(t);
  }
  Solution s;
  s.rotate(matrix);
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  return 0;
}
