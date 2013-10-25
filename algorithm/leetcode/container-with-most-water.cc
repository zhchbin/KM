// 题目：http://oj.leetcode.com/problems/container-with-most-water/
//
// 题意：在数组A中，找到一个数对，使得min(A[i], A[j]) * abs(j - i)最大。
//
// 解法：假设A[i], A[j], 其中A[i] < A[j], 则i + 1, i + 2, ......, j - 1中找不到
//       比min(A[i], A[j]) * abs(j - i)更大的数对，因为A[i]是短板。利用这个性质，
//       使用头尾两个指针hd和tl，构成数对，计算，然后去掉短板继续即可。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int maxArea(vector<int> &height) {
    int ans = 0;
    int hd = 0, tl = height.size() - 1;
    while (hd < tl) {
      int tmp = (tl - hd) * min(height[hd], height[tl]);
      height[hd] < height[tl] ? hd++ : tl--;
      ans = max(ans, tmp);
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int arr[] = {3, 2, 1, 3};
  vector<int> heights(arr, arr + sizeof(arr) / sizeof(int));
  cout << s.maxArea(heights) << endl;
  return 0;
}
