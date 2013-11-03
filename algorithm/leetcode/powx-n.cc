// URL: http://oj.leetcode.com/problems/powx-n/
//
// Problem: Implement pow(x, n);
//
// Solution: 快速幂，推导公式然后二分法递归实现。
//
// 公式：http://latex.codecogs.com/svg.latex?x%5En%3D%5Cbegin%7Bcases%7D1.0%26%5Ctext%7Bif%20%7D%20n%3D0%2C%5C%5C%20x%5E%7Bn/2%7D%5Ccdot%20x%5E%7Bn/2%7D%26%5Ctext%7Bif%20%7Dn%5Cne0%5Ctext%7B%20and%20%7Dn%5Ctext%7B%20is%20even%2C%7D%5C%5C%20x%5E%7B%5Clfloor%20n/2%5Crfloor%7D%5Ccdot%20x%5E%7B%5Clfloor%20n/2%5Crfloor%7D%5Ccdot%20x%26%5Ctext%7Bif%20%7Dn%3E0%5Ctext%7B%20and%20%7Dn%5Ctext%7B%20is%20odd%2C%7D%5C%5C%20x%5E%7B%5Clceil%20n/2%5Crceil%7D%5Ccdot%20x%5E%7B%5Clceil%20n/2%5Crceil%7D%5Ccdot%20x%5E%7B-1%7D%26%20%5Ctext%7Bif%20%7Dn%3C0%5Ctext%7B%20and%20%7Dn%5Ctext%7B%20is%20odd.%7D%5Cend%7Bcases%7D
//
//

#include <cmath>
#include <cassert>

class Solution {
 public:
  double pow(double x, int n) {
    if (n == 0)
      return 1.0;

    double half = pow(x, n / 2);
    if (n % 2 == 0)
      return half * half;
    else if (n > 0)
      return half * half * x;
    else
      return half * half / x;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(std::fabs(std::pow(1, 20) - s.pow(1, 20)) < 1.0e-6);
  assert(std::fabs(std::pow(3, 20) - s.pow(3, 20)) < 1.0e-6);
  assert(std::fabs(std::pow(-2, 2) - s.pow(-2, 2)) < 1.0e-6);
  assert(std::fabs(std::pow(3, -100) - s.pow(3, -100)) < 1.0e-6);
  assert(std::fabs(std::pow(10, 0) - s.pow(10, 0)) < 1.0e-6);

  return 0;
}
