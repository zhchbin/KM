// URL: http://oj.leetcode.com/problems/palindrome-partitioning/
#include "common.h"

class Solution {
 public:
  vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    vector<string> part;
    PartitionHelper(s, 0, part, result);

    return result;
  }

  void PartitionHelper(const string& s, int start, vector<string>& part,
                       vector<vector<string> >& result) {
    if (start == s.length()) {
      result.push_back(part);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      if (IsPalindrome(s, start, i)) {
        part.push_back(s.substr(start, i - start + 1));
        PartitionHelper(s, i + 1, part, result);
        part.pop_back();
      }
    }
  }

  bool IsPalindrome(const string& s, int start, int end) {
    if (start == end)
      return true;
    while (start < end) {
      if (s[start] != s[end])
        return false;
      ++start;
      --end;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<string> > result = s.partition("aab");
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  return 0;
}
