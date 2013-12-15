// URL: http://oj.leetcode.com/problems/unique-binary-search-trees/
//
// Problem: Given n, how many structurally unique BST's (binary search trees)
//          that store values 1...n?
//
// Solution: Catalan number. C(0) = C(1) = 1,
//           C(n) = C(0) * C(n - 1) + C(1) * C(n - 2) + ... + C(n-1) * C(0);

#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  int numTrees(int n) {
    vector<int> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < i; ++j)
        catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    return catalan[n];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(s.numTrees(2) == 2);
  assert(s.numTrees(3) == 5);
  assert(s.numTrees(4) == 14);
  return 0;
}
