// URL: https://oj.leetcode.com/problems/add-binary/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    int t;
    for (; i >= 0 || j >= 0; --i, --j) {
      t = carry;
      if (i >= 0)
        t += (a[i] - '0');
      if (j >= 0)
        t += (b[j]- '0');
      carry = t / 2;
      result += (t % 2 ? '1' : '0');
    }
    if (carry != 0)
      result += '1';

    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.addBinary("11", "1") << endl;
  return 0;
}
