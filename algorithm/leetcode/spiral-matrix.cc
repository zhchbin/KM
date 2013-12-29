// URL: http://oj.leetcode.com/problems/spiral-matrix/
// Problem: Given a matrix of m x n elements (m rows, n columns), return all
//          elements of the matrix in spiral order.
//          For example,
//          Given the following matrix:
//            [
//             [ 1, 2, 3 ],
//             [ 4, 5, 6 ],
//             [ 7, 8, 9 ]
//            ]
//          You should return [1,2,3,6,9,8,7,4,5].

#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int m = matrix.size();
    if (m == 0)
      return vector<int>();

    int n = matrix[0].size();
    vector<int> orders;
    solve(0, m - 1, 0, n - 1, matrix, orders);

    return orders;
  }

  void solve(int m1, int m2, int n1, int n2, const vector<vector<int> >& matrix,
             vector<int>& orders) {
    if (m1 > m2 || n1 > n2)
      return;
    if (m1 == m2) {
      for (int k = n1; k <= n2; ++k)
        orders.push_back(matrix[m1][k]);

      return;
    }

    if (n1 == n2) {
      for (int k = m1; k <= m2; ++k)
        orders.push_back(matrix[k][n1]);

      return;
    }


    int i = m1;
    int j = n1;
    for (;j < n2; ++j)
      orders.push_back(matrix[i][j]);
    for (;i < m2; ++i)
      orders.push_back(matrix[i][j]);
    for (; j > n1; --j)
      orders.push_back(matrix[i][j]);
    for (; i > m1; --i)
      orders.push_back(matrix[i][j]);

    solve(m1 + 1, m2 - 1, n1 + 1, n2 - 1, matrix, orders);
  }
};

int main(int argc, char *argv[]) {
  int data[][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  vector<vector<int> > matrix;
  for (int i = 0; i < 4; ++i)
    matrix.push_back(vector<int>(data[i], data[i] + 1));

  vector<int> orders = Solution().spiralOrder(matrix);
  for (int i = 0; i < orders.size(); ++i)
    cout << orders[i] << " ";
  cout << endl;

  return 0;
}
