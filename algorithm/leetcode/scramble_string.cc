// URL: https://oj.leetcode.com/problems/scramble-string/
#include "common.h"

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    return isScrambleRecursive(s1, s2);
  }

  bool isScrambleRecursive(const string& s1, const string& s2) {
    if (s1.size() != s2.size())
      return false;
    if (s1 == s2)
      return true;
    int c[26] = {0};
    for (int i = 0; i < s1.size(); ++i) {
      c[s1[i] - 'a']++;
      c[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (c[i])
        return false;
    }

    for (int i = 1; i < s1.size(); ++i) {
      string s11 = s1.substr(0, i);
      string s12 = s1.substr(i);
      string s21 = s2.substr(0, i);
      string s22 = s2.substr(i);
      if (isScrambleRecursive(s11, s21) && isScrambleRecursive(s12, s22))
        return true;
      s21 = s2.substr(0, s2.size() - i);
      s22 = s2.substr(s2.size() - i);
      if (isScrambleRecursive(s11, s22) && isScrambleRecursive(s12, s21))
        return true;
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isScramble("rgtae", "great") << endl;
  return 0;
}
