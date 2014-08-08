// URL: https://oj.leetcode.com/problems/word-break/

#include "common.h"
#include <unordered_set>

class Solution {
 public:
  bool wordBreak(string s, unordered_set<string>& dict) {
    vector<bool> can_seg(s.size() + 1, false);
    can_seg[0] = true;
    for (int i = 0; i < s.size(); ++i) {
      if (!can_seg[i])
        continue;
      for (string word : dict) {
        if (s.substr(i, word.size()) == word)
          can_seg[i + word.size()] = true;
      }
    }

    return can_seg[s.size()];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  unordered_set<string> dict = {"leet", "code"};
  cout << s.wordBreak("leetCode", dict) << endl;
  cout << s.wordBreak("leetcode", dict) << endl;
  return 0;
}
