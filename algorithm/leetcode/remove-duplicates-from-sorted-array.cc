// URL: http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
//
// Problem: Given a sorted array, remove the duplicates in place such that each
//          element appear only once and return the new length.

#include <iostream>
using namespace std;

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      int index = i + 1;
      while (index < n && A[index] == A[i])
        ++index;
      if (index == n) {
        n -= (index - i - 1);
        break;
      }

      n -= (index - i - 1);

      if (index != i + 1) {
        for (int j = i + 1; j < n; ++j)
          A[j] = A[index++];
      }
    }

    return n;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {1, 1, 1, 2, 2};
  Solution s;
  int n = s.removeDuplicates(A, 5);
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << A[i] << endl;
  }

  return 0;
}
