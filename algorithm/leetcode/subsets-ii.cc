// URL: http://oj.leetcode.com/problems/subsets-ii/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > result;
    vector<int> path;
    generateSubsets(S, 0, path, result);

    return result;
  }

  void generateSubsets(vector<int>& S,
                       int begin,
                       vector<int>& path,
                       vector<vector<int> >& result) {
    result.push_back(path);

    for (int i = begin; i < S.size(); ++i) {
      if (i != begin && S[i] == S[i - 1])
        continue;

      path.push_back(S[i]);
      generateSubsets(S, i + 1, path, result);
      path.pop_back();
    }
  }
};

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

int main(int argc, char *argv[]) {
  int test_data[] = {1, 2, 2, 3};
  vector<int> S(test_data, test_data + ARRAY_SIZE(test_data));
  Solution s;
  vector<vector<int> > result = s.subsetsWithDup(S);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  return 0;
}
