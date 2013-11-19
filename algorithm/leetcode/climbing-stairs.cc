// URL: http://oj.leetcode.com/problems/climbing-stairs/
//
// Problem: You are climbing a stair case. It takes n steps to reach to the top.
//          Each time you can either climb 1 or 2 steps. In how many distinct
//          ways can you climb to the top?
//
// Solution: f(n) = f(n - 1) + f(n - 2), if n > 2
//           f(2) = 2
//           f(1) = 1
//
#include <cassert>

class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1 || n == 2)
      return n;

    int f_n1 = 2, f_n2 = 1;
    int fn;
    for (int i = 3; i <= n; i++) {
      fn = f_n1 + f_n2;
      f_n2 = f_n1;
      f_n1 = fn;
    }

    return fn;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(s.climbStairs(2) == 2);
  assert(s.climbStairs(4) == 5);
  assert(s.climbStairs(6) == 13);

  return 0;
}
