// URL: http://oj.leetcode.com/problems/single-number-ii/
//
// Problem: Given an array of integers, every element appears three times except
//          for one. Find that single one.

#include <iostream>
using namespace std;

#define INT_SIZE 32

class Solution {
 public:
  int singleNumber(int A[], int n) {
    int num = 0;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
      if (A[i] < 0)
        ++counter;
    }

    for (int i = 0; i < INT_SIZE; ++i) {
      unsigned int mask = 1 << i;
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        unsigned int t = (A[j] >= 0 ? A[j] : -A[j]);
        if (t & mask)
          sum += 1;
      }
      cout << sum << endl;
      
      if (sum % 3)
        num += mask;
    }

    return counter % 3 == 0 ? num : -num;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {43, 16, 45, 89, 45, -2147483648, 45, 2147483646, -2147483647, 
             -2147483648, 43, 2147483647, -2147483646, -2147483648, 89,
             -2147483646, 89, -2147483646, -2147483647, 2147483646, -2147483647,
             16, 16, 2147483646, 43};
  Solution s;
  cout << s.singleNumber(A, sizeof(A) / sizeof(A[0])) << endl;

  return 0;
}
