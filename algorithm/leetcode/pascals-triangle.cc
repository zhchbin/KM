// URL: http://oj.leetcode.com/problems/pascals-triangle/
//
// Problem: Given numRows, generate the first numRows of Pascal's triangle.
//          For example, given numRows = 5,
//          Return
//
//          [
//               [1],
//              [1,1],
//             [1,2,1],
//            [1,3,3,1],
//           [1,4,6,4,1]
//          ]
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > triangle;
    if (numRows == 0)
      return triangle;

    triangle.resize(numRows);
    triangle[0].push_back(1);
    for (int i = 1; i < numRows; ++i) {
      triangle[i].push_back(1);
      for (int j = 0; j < triangle[i - 1].size() - 1; ++j)
        triangle[i].push_back(triangle[i - 1][j] + triangle[i - 1][j + 1]); 
      triangle[i].push_back(1);
    }

    return triangle;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > triangle = s.generate(10);
  for (int i = 0; i < triangle.size(); ++i) {
    for (int j = 0; j < triangle[i].size(); ++j)
      cout << triangle[i][j] << " ";
    cout << endl;
  }

  return 0;
}
