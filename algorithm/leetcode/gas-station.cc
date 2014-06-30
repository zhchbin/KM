// URL: https://oj.leetcode.com/problems/gas-station/

#include "common.h"
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<int> diff(gas.size());
    int total_left = 0;
    int start_node = 0;
    int sum = 0;

    for (int i = 0; i < diff.size(); ++i) {
      diff[i] = gas[i] - cost[i];
      total_left += diff[i];
      sum += diff[i];
      if (sum < 0) {
        start_node = i + 1;
        sum = 0;
      }
    }
    return total_left >= 0 ? start_node : -1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int gas_arr[] = {1, 2, 3, 4};
  int cost_arr[] = {4, 1, 4, 1};
  vector<int> gas(gas_arr, gas_arr + ARRAY_SIZE(gas_arr));
  vector<int> cost(cost_arr, cost_arr + ARRAY_SIZE(cost_arr));
  cout << s.canCompleteCircuit(gas, cost) << endl;

  return 0;
}
