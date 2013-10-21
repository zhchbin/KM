// 题目：http://oj.leetcode.com/problems/two-sum/
//
// 题意：给定一个数组和值target，返回数组中两个数之和等于target的数组下标。
//
// 解法：O(n ^ 2) 的遍历。应该可以多加个map稍微做点点优化。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
      int t = target - numbers[i];
      for (int j = i + 1; j < numbers.size(); j++) {
        if (t == numbers[j]) {
          result.push_back(i + 1);
          result.push_back(j + 1);
          return result;
        }
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  int arr[4] = {2, 7, 11, 15};
  vector<int> numbers(arr, arr + 4);
  Solution s;
  vector<int> result = s.twoSum(numbers, 9);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
