// URL: http://oj.leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty())
      return "";

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i)
      prefix = longestCommonPrefix(prefix, strs[i]);

    return prefix;
  }

  string longestCommonPrefix(const string& str1, const string& str2) {
    int length = 0;
    for (int i = 0; i < str1.size() && i < str2.size(); ++i) {
      if (str1[i] == str2[i])
        length++;
      else
        break;
    }
    if (length == 0)
      return "";

    return str1.substr(0, length);
  }
};

int main(int argc, char *argv[]) {
  vector<string> strs;
  strs.push_back("abc");
  strs.push_back("abcde");
  strs.push_back("abcdfa");
  strs.push_back("abceadf");
  strs.push_back("abcasdfasd");

  Solution s;
  cout << s.longestCommonPrefix(strs) << endl;
  return 0;
}
