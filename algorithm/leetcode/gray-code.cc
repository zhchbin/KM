// URL: http://oj.leetcode.com/problems/gray-code/
//
// Problem: The gray code is a binary numeral system where two successive values
//          differ in only one bit.
//          Given a non-negative integer n representing the total number of bits
//          in the code, print the sequence of gray code. A gray code sequence
//          must begin with 0.
//          For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//            00 - 0
//            01 - 1
//            11 - 3
//            10 - 2

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> codes;
    if (n == 0) {
      codes.push_back(0);
      return codes;
    }

    // The key point: convert binary value to reflected gray code. From
    // wikipedia: http://en.wikipedia.org/wiki/Gray_code.
    for (int i = 0; i < (2 << (n - 1)); i++)
      codes.push_back((i >> 1) ^ i);

    return codes;
  }
};

int main(int argc, char *argv[]) {
  vector<int> codes = Solution().grayCode(10);
  for (int i = 0; i < codes.size(); i++)
    cout << codes[i] << " ";
  cout << endl;

  return 0;
}
