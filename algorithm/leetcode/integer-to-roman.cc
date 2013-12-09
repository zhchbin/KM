// URL: http://oj.leetcode.com/problems/integer-to-roman/
//
// Problem: Given an integer, convert it to a roman numeral.
//          Input is guaranteed to be within the range from 1 to 3999.

#include <string>
#include <iostream>
using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int scale = 1000;
    string roman;
    for (int i = 6; i >= 0; i -= 2) {
      int digit = num / scale;
      num %= scale;
      scale /= 10;
      if (digit == 0)
        continue;

      if (digit <= 3)
        roman.append(digit, symbol[i]); 
      else if (digit == 4)
        roman.append(1, symbol[i]).append(1, symbol[i + 1]);
      else if (digit <= 8)
        roman.append(1, symbol[i + 1]).append(digit - 5, symbol[i]);
      else
        roman.append(1, symbol[i]).append(1, symbol[i + 2]);
    }

    return roman;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.intToRoman(1940) << endl;
  cout << s.intToRoman(2940) << endl;
  return 0;
}
