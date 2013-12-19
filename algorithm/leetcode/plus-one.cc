// URL: http://oj.leetcode.com/problems/plus-one/
//
// Problem: Given a number represented as an array of digits, plus one to the
//          number.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 0;
    int tmp;
    vector<int> result;
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (i == digits.size() - 1)
        tmp = digits[i] + 1 + carry;
      else
        tmp = digits[i] + carry;

      result.push_back(tmp % 10);
      carry = tmp / 10;
    }

    if (carry != 0)
      result.push_back(carry);
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main(int argc, char *argv[]) {
  int arr[] = {9, 9 ,9};
  vector<int> digits(arr, arr + sizeof(arr) / sizeof(arr[0]));
  Solution s;
  vector<int> result = s.plusOne(digits);
  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << " ";
  cout << endl;

  return 0;
}
