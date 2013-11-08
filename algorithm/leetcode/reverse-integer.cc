// URL: http://oj.leetcode.com/problems/reverse-integer/
//
// Problem: Reverse digits of an integer.
//          Example1: x = 123, return 321
//          Example2: x = -123, return -321
//
// Solution: ......
//

#include <cassert>

class Solution {
 public:
  int reverse(int x) {
    int r = 0;
    while (x != 0) {
      r *= 10;
      r += x % 10;
      x /= 10;
    }

    return r;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(s.reverse(1) == 1);
  assert(s.reverse(12) == 21);
  assert(s.reverse(-1) == -1);
  assert(s.reverse(10) == 1);
  assert(s.reverse(100) == 1);
  assert(s.reverse(-12) == -21);
  assert(s.reverse(-123) == -321);

  return 0;
}
