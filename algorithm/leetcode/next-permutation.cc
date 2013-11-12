// URL: http://oj.leetcode.com/problems/next-permutation/
//
// Problem: Implement next permutation, which rearranges numbers into the
//          lexicographically next greater permutation of numbers.
//
// Solution: http://blog.bjrn.se/2008/04/lexicographic-permutations-using.html
//

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &num) {
    int lastIndex = -1;
    for (int i = num.size() - 2; i >= 0; i--) {
      if (num[i] < num[i + 1]) {
        lastIndex = i;
        break;
      }
    }

    if (lastIndex == -1) {
      reverse(num.begin(), num.end());
    } else {
      int j;
      for (j = num.size() - 1; j >= 0; j--) {
        if (num[j] > num[lastIndex])
          break;
      }
      swap(num[lastIndex], num[j]);
      reverse(num.begin() + lastIndex + 1, num.end());
    }
  }
};

bool cmpArray(vector<int>& nums, int expected[]) {
  for (int i = 0; i < nums.size(); i++)
    if (nums[i] != expected[i])
      return false;

  return true;
}

int main(int argc, char *argv[]) {
  int testData1[] = {1, 2, 3};
  int expected1[] = {1, 3, 2};
  vector<int> num1(testData1, testData1 + 3);
  Solution s;
  s.nextPermutation(num1);
  assert(cmpArray(num1, expected1));

  int testData2[] = {3, 2, 1};
  int expected2[] = {1, 2, 3};
  vector<int> num2(testData2, testData2 + 3);
  s.nextPermutation(num2);
  assert(cmpArray(num2, expected2));

  int testData3[] = {1, 1, 5};
  int expected3[] = {1, 5, 1};
  vector<int> num3(testData3, testData3 + 3);
  s.nextPermutation(num3);
  assert(cmpArray(num3, expected3));
  
  return 0;
}
