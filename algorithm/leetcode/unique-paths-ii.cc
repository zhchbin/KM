// URL: http://oj.leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int grid[102][102] = {0};

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    grid[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (obstacleGrid[i][j] == 1)
          grid[i][j] = 0;
        else
          grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
      }
    }

    return grid[0][0];
  }
};

int main(int argc, char *argv[]) {
  int data[3][3] = {0};
  data[1][0] = 1;
  vector<vector<int> > obstacleGrid;
  for (int i = 0; i < 3; ++i)
    obstacleGrid.push_back(vector<int>(data[i], data[i] + 3));
  Solution s;
  cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
  return 0;
}
