// URL: http://oj.leetcode.com/problems/count-and-say/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string str = "1";
    for (int i = 2; i <= n; ++i) {
      char c = str[0];
      int cnt = 0;
      string next_str;
      for (int j = 0; j <= str.size(); ++j) {
        if (j != str.size() && str[j] == c) {
          cnt++;
        } else {
          stringstream ss;
          ss << cnt;
          next_str += (ss.str() + c);
          cnt = 1;
          c = str[j];
        }
      }
      str = next_str;
    }

    return str;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.countAndSay(5) << endl;
  return 0;
}
