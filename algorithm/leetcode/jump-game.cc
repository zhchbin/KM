// URL: http://oj.leetcode.com/problems/jump-game/
#include <algorithm>
#include <cassert>

class Solution {
 public:
  bool canJump(int A[], int n) {
    int reach = 1;
    for (int i = 0; i < reach && reach < n; ++i)
      reach = std::max(reach, A[i] + i + 1);

    return reach >= n;
  }
};

#define ARRAY_LENGTH(array) sizeof(array) / sizeof(array[0])

int main(int argc, char *argv[]) {
  Solution s;
  int A[] = {2, 3, 1, 1, 4};
  int B[] = {3, 2, 1, 0, 4};
  assert(s.canJump(A, ARRAY_LENGTH(A)));
  assert(!s.canJump(B, ARRAY_LENGTH(B)));
  return 0;
}
