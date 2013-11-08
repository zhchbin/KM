// URL: http://oj.leetcode.com/problems/single-number/
//
// Problem: Given an array of integers, every element appears twice except for
//          one. Find that single one.
//
// Solution: 123 ^ 123 = 0, 0 ^ 123 = 123.
//

#include <iostream>
using namespace std;

class Solution {
 public:
  int singleNumber(int A[], int n) {
    int val = A[0];
    for (int i = 1; i < n; i++)
      val ^= A[i];

    return val;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int A[] = {2, 2, 3};
  cout << s.singleNumber(A, 3) << endl;
  return 0;
}
