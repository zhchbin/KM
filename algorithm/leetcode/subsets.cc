// URL: http://oj.leetcode.com/problems/subsets/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int> > subsets(vector<int>& S) {
    sort(S.begin(), S.end());
    result.clear();
    vector<int> cur;
    dfs(S, 0, cur);

    return result;
  }

  void dfs(vector<int>& S, int index, vector<int>& cur) {
    if (index == S.size()) {
      result.push_back(cur);
      return;
    }

    dfs(S, index + 1, cur);

    cur.push_back(S[index]);
    dfs(S, index + 1, cur);
    cur.pop_back();
  }

  vector<vector<int> > result;
};

int main(int argc, char *argv[]) {
  int data[] = {1, 2, 3, 4};
  vector<int> S(data, data + sizeof(data) / sizeof(data[0]));
  Solution sol;
  vector<vector<int> > result = sol.subsets(S);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  return 0;
}
