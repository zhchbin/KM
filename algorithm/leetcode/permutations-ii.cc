// URL: http://oj.leetcode.com/problems/permutations-ii/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
 public:
  vector<vector<int> > permuteUnique(vector<int>& num) {
    vector<vector<int> > result;
    permuteRecursive(0, result, num);

    return result;
  }

  bool ShouldSwap(int k, int i, vector<int>& num) {
    for (int j = k; j < i; ++j) {
      if (num[j] == num[i])
        return false;
    }

    return true;
  }

  void permuteRecursive(int k, vector<vector<int> >& result, vector<int>& num) {
    if (k == num.size()) {
      result.push_back(num);
      return;
    }

    for (int i = k; i < num.size(); ++i) {
      if (ShouldSwap(k, i, num)) {
        std::swap(num[k], num[i]);
        permuteRecursive(k + 1, result, num);
        std::swap(num[k], num[i]);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  int data[] = {1, 1, 3};
  vector<int> num(data, data + 3);
  vector<vector<int> > permutations = Solution().permuteUnique(num);
  for (int i = 0; i < permutations.size(); ++i) {
    for (int j = 0; j < permutations[i].size(); ++j)
      cout << permutations[i][j] << " ";
    cout << endl;
  }

  return 0;
}
