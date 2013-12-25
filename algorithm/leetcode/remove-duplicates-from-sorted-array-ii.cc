// URL: http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
//
// Problem: Follow up for "Remove Duplicates":
//          What if duplicates are allowed at most twice?
//
//          For example,
//          Given sorted array A = [1,1,1,2,2,3],
//          
//          Your function should return length = 5, and A is now [1,1,2,2,3].
#include <iostream>
using namespace std;

class Solution {
 public:
  // This function is inefficient. My personal idea.
  int removeDuplicates(int A[], int n) {
    for (int i = 0; i < n - 2; i++) {
      int index = i + 2;
      while (index < n && A[index] == A[i])
        index++;
      if (index != i + 2) {
        for (int j = index; j < n; ++j)
          A[i + 2 + j - index] = A[j];
        n -= (index - i - 2);
      }
    }

    return n;
  }
};

class BetterSolution {
 public:
  int removeDuplicates(int A[], int n) {
    if (n <= 2)
      return n;

    int cur = 1;
    for (int i = 2; i < n; ++i) {
      if (A[i] != A[cur] || A[i] != A[cur - 1])
          A[++cur] = A[i];
    }

    return cur + 1;
  }
};

int main(int argc, char *argv[]) {
  int A[] = {1, 1, 1, 2, 2, 3};
  BetterSolution s;
  int n = s.removeDuplicates(A, 3);
  cout << n << endl;
  for (int i = 0; i < n; i++)
    cout << A[i] << endl;

  return 0;
}
