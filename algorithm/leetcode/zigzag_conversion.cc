// URL: https://oj.leetcode.com/problems/zigzag-conversion/
#include <cassert>
#include <string>

using std::string;

//   00          08           16          24
//   01       07 09        15 17       23
//   02    06    10    14     18    22
//   03 05       11 13        19 21
//   04          12           20
//
class Solution {
 public:
  string convert(string s, int rows) {
    if (rows == 1 || s.empty())
      return s;

    string res;
    int period = (rows - 1) * 2;
    for (int i = 0; i < rows; ++i) {
      for (int j = i; j < s.length(); j += period) {
        res += s[j];
        if (i != 0 && i != rows - 1 && (j + period - 2 * i) < s.length())
          res += s[j + period - 2 * i];
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
  assert(s.convert("PAYPALISHIRING", 1) == "PAYPALISHIRING");
  return 0;
}
