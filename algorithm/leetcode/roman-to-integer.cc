// 题目：http://oj.leetcode.com/problems/roman-to-integer/
//
// 题意：将罗马数字转换成为整数（范围在：1 - 3999）
//
// 解法：从左到右遍历，如果出现前面的数字小于后面的数字的情况，则减去该值；否则
//       加上该值即可。因为会存在：IV = 4，IX = 9, XL = 40, XC = 90, CD = 400,
//       CM = 900的情况。
//
// 遇到的问题：不知道罗马数字是怎么表示的，
//
// Reference:
//    WIKIPEDIA: http://en.wikipedia.org/wiki/Roman_numerals
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    int ans = 0;
    map<char, int> symbols;
    symbols['I'] = 1;
    symbols['V'] = 5;
    symbols['X'] = 10;
    symbols['L'] = 50;
    symbols['C'] = 100;
    symbols['D'] = 500;
    symbols['M'] = 1000;

    for (int i = 0; i < s.length(); i++) {
      if (i != s.length() - 1 && symbols[s[i]] < symbols[s[i + 1]]) {
        ans -= symbols[s[i]];
      } else {
        ans += symbols[s[i]];
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.romanToInt("MLXVI") << endl;
  cout << s.romanToInt("MCMXCVI") << endl;

  return 0;
}
