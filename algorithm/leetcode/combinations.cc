// URL: http://oj.leetcode.com/problems/combinations/
//
// Problem: Given two integers n and k, return all possible combinations of k
//          numbers out of 1 ... n.
//          For example,
//          If n = 4 and k = 2, a solution is:
//
//          [
//            [2,4],
//            [3,4],
//            [2,3],
//            [1,2],
//            [1,3],
//            [1,4],
//          ]
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
 public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > combinations;
    vector<int> com;
    memset(has_visited, false, sizeof(has_visited));
    dfs(n, k, 1, com, combinations);

    return combinations;
  }

  void dfs(int n, int k, int d, vector<int>& com,
           vector<vector<int> >& combinations) {
    if (com.size() == k) {
      combinations.push_back(com);
      return;
    }

    for (int i = d; i <= n; ++i) {
      if (has_visited[i])
        continue;

      com.push_back(i);
      has_visited[i] = true;
      dfs(n, k, i, com, combinations);
      com.pop_back();
      has_visited[i] = false;
    }
  }

  bool has_visited[50000];
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > combinations = s.combine(4, 3);
  for (int i = 0; i < combinations.size(); ++i) {
    for (int j = 0; j < combinations[i].size(); ++j)
      cout << combinations[i][j] << " ";
    cout << endl;
  }

  return 0;
}
