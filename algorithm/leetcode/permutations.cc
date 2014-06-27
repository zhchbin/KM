// URL: http://oj.leetcode.com/problems/permutations/
//
// Problem: Given a collection of numbers, return all possible permutations.
//  For example,
//    [1,2,3] have the following permutations:
//      [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
 public:
  vector<vector<int> > permute(vector<int> &num) {
    memset(hasUsed, 0, sizeof(hasUsed));
    vector<vector<int> > result;
    vector<int> path;
    permuteRecursive(0, num, path, result);

    return result;
  }

  void permuteRecursive(int index,
                        vector<int> &num,
                        vector<int> &path,
                        vector<vector<int> >& result) {
    if (index == num.size()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < num.size(); i++) {
      if (hasUsed[i])
        continue;

      hasUsed[i] = true;
      path.push_back(num[i]);
      permuteRecursive(index + 1, num, path, result);
      path.pop_back();
      hasUsed[i] = false;
    }
  }

  bool hasUsed[100];
};

class Answer {
 public:
  vector<vector<int> > permute(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int> > permutations;
    do {
      permutations.push_back(num);
    } while (std::next_permutation(num.begin(), num.end()));

    return permutations;
  }
};

class AnotherSolution {
 public:
  vector<vector<int> > permute(vector<int>& num) {
    vector<vector<int> > result;
    permuteRecursive(0, result, num);

    return result;
  }

  void permuteRecursive(int k, vector<vector<int> >& result, vector<int>& num) {
    if (k == num.size()) {
      result.push_back(num);
      return;
    }

    for (int i = k; i < num.size(); ++i) {
      std::swap(num[k], num[i]);
      permuteRecursive(k + 1, result, num);
      std::swap(num[k], num[i]);
    }
  }
};

int main(int argc, char *argv[]) {
  int data[] = {1, 2, 3};
  vector<int> num(data, data + 3);
  vector<vector<int> > permutations = AnotherSolution().permute(num);
  for (int i = 0; i < permutations.size(); ++i) {
    for (int j = 0; j < permutations[i].size(); ++j)
      cout << permutations[i][j] << " ";
    cout << endl;
  }

  return 0;
}
