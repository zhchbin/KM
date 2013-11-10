// URL: http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//
// Problem: Say you have an array for which the ith element is the price of a
//          given stock on day i.
//          Design an algorithm to find the maximum profit. You may complete as
//          many transactions as you like (ie, buy one and sell one share of the
//          stock multiple times). However, you may not engage in multiple
//          transactions at the same time (ie, you must sell the stock before
//          you buy again).
// 
// Solution: Note that for a part of given prices like: 1, 2, 0, 3, 4, you can
//           get the max profit by:
//           1) buy 1, sell 2, buy 0, sell 4
//           2) buy 1, sell 2, buy 0, sell 3, buy 3, sell 4.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1])
        profit += prices[i] - prices[i - 1];
    }

    return profit;
  }
};

int main(int argc, char *argv[]) {
  int arr[] = {6, 7, 9, 10, 1};
  vector<int> prices(arr, arr + 5);
  Solution s;
  cout << s.maxProfit(prices) << endl;
  return 0;
}
