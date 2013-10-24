// 题目：http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
//
// 题意：给定一个数组A，求出数组中A[i]- A[j]最大，i < j。
//
// 解法：一开始我是用一个单调递增的堆，虽然完成了，但是代码丑的很。其实只要一次
//      遍历，记住当前找到的最小值的位置，跟后面的作比较即可。算法复杂度为O(n)。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min = 0;
    int ans = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < prices[min])
        min = i;
      int t = prices[i] - prices[min];
      if (t > ans) {
        ans = t;
      }
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int arr[] = {2, 2, 5, 5, 0, 100};
  vector<int> prices(arr, arr + 6);
  cout << s.maxProfit(prices) << endl;
  return 0;
}
