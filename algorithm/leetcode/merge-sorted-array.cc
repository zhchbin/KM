// URL: http://oj.leetcode.com/problems/merge-sorted-array/
//
// Problem: Given two sorted integer arrays A and B, merge B into A as one
//          sorted array.

#include <iostream>
using namespace std;

class Solution {
 public:
  void merge(int A[], int m, int B[], int n) {
    int i = m - 1;
    int j = n - 1;
    while (i >= 0 && j >= 0) {
      if (A[i] > B[j])
        A[i + j + 1] = A[i--];
      else
        A[i + j + 1] = B[j--];
    }

    while (j >= 0)
      A[j] = B[j--];
  }
};

int main(int argc, char *argv[]) {
  int A[6] = {1, 3, 4, 10};
  int B[] = {2, 100};

  Solution s;
  s.merge(A, 4, B, 2);
  for (int i = 0; i < 6; i++)
    cout << A[i] << endl;

  return 0;
}
