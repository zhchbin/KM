#include "common.h"

class Solution {
 public:
  vector<vector<int> > result;

  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    result.clear();
    if (num.empty())
      return result;

    vector<int> sol;
    sort(num.begin(), num.end());
    dfs(num, target, 0, sol);
    return result;
  }

  void dfs(vector<int>& nums, int n, int start, vector<int>& sol) {
    if (n == 0) {
      result.push_back(sol);
      return;
    }

    if (start >= nums.size() || n < 0)
      return;
    for (int i = start; i < nums.size(); ++i) {
      sol.push_back(nums[i]);
      dfs(nums, n - nums[i], i + 1, sol);
      sol.pop_back();
      while (i < nums.size() && nums[i] == nums[i + 1])
        ++i;
    }
  }

};

int main(int argc, char *argv[]) {
  int data[] = {10, 1, 2, 7, 6, 1, 5};
  vector<int> num(data, data + ARRAY_SIZE(data));
  Solution s;
  vector<vector<int> > result = s.combinationSum2(num, 8);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
}
