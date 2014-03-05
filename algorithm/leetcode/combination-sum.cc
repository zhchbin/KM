// URL: http://oj.leetcode.com/problems/combination-sum/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Nums;

class Solution {
 public:
  vector<Nums> results;

  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    results.clear();
    Nums sol;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, sol, 0);

    return results;
  }

  void dfs(vector<int>& candidates, int n, Nums& sol, int start) {
    if (n == 0) {
      results.push_back(sol);
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      if (n - candidates[i] < 0)
        return;

      sol.push_back(candidates[i]);
      dfs(candidates, n - candidates[i], sol, i);
      sol.pop_back();
    }
  }
};

int main(int argc, char *argv[]) {
  int data[] = {2, 3, 4, 6, 7};
  Solution s;
  Nums candidates(data, data + sizeof(data) / sizeof(data[0]));

  vector<Nums> results = s.combinationSum(candidates, 7);
  for (int i = 0; i < results.size(); ++i) {
    for (int j = 0; j < results[i].size(); ++j)
      cout << results[i][j] << " ";
    cout << endl;
  }
  return 0;
}
