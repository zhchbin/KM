// URL: http://oj.leetcode.com/problems/triangle/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define INIT_DATA(triangle, row) \
    triangle.push_back(vector<int>(data_ ## row, data_ ## row + row + 1))

class Solution {
 public:
  int minimumTotal(vector<vector<int> >& triangle) {
    int row_num = triangle.size();
    int minV[triangle[row_num - 1].size()];
    for (int i = 0; i < triangle[row_num - 1].size(); ++i)
      minV[i] = triangle[row_num - 1][i];

    for (int i = row_num - 2; i >= 0; --i)
      for (int j = 0; j < triangle[i].size(); ++j)
        minV[j] = min(minV[j], minV[j + 1]) + triangle[i][j];

    return minV[0];
  }
};

int main(int argc, char *argv[]) {
  int data_0[] = {2};
  int data_1[] = {3, 4};
  int data_2[] = {6, 5, 7};
  int data_3[] = {4, 1, 8, 3};

  Solution s;
  vector<vector<int> > triangle;
  INIT_DATA(triangle, 0);
  INIT_DATA(triangle, 1);
  INIT_DATA(triangle, 2);
  INIT_DATA(triangle, 3);

  cout << s.minimumTotal(triangle) << endl;
  return 0;
}
