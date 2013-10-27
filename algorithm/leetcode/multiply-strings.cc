// 题目：http://oj.leetcode.com/problems/multiply-strings/
//
// 题意：实现一个高精度乘法。
//
// 解法：直接模拟笔算。
//
// 遇到的问题：第一：在实现加法的时候忽略了最后进位的问题；
//             第二：没有考虑乘数为0的情况；
//             第三：有更精简更高效的做法，待研究。
#include <string>
#include <iostream>
using namespace std;

class Solution {
 public:
  // TODO(zhchbin): Rewrite the code using a more simple and efficient way.
  string multiply(string num1, string num2) {
    string result;
    for (int j = num2.size() - 1; j >= 0; j--) {
      string tmp;
      int carryBit = 0;
      for (int i = num1.size() - 1; i >= 0; i--) {
        int t = (num1[i] - '0') * (num2[j] - '0');
        t += carryBit;
        tmp.push_back(t % 10 + '0');
        carryBit = t / 10;
      }

      if (carryBit != 0)
        tmp.push_back(carryBit + '0');

      reverseString(tmp);
      for (int k = 0; k < num2.size() - j - 1; k++)
        tmp.push_back('0');

      if (result.size() == 0)
        result = tmp;
      else
        result = add(result, tmp);
    }
    bool flag = false;
    for (int i = 0; i < result.size(); i++) {
      if (result[i] != '0')
        flag = true;
    }
    if (!flag)
      return "0";

    return result;
  }

  string add(const string& num1, const string& num2) {
    string result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carryBit = 0;
    while (i >= 0 && j >= 0) {
      int t = num1[i--] - '0' + num2[j--] - '0' + carryBit;
      result.push_back(t % 10 + '0');
      carryBit = t / 10;
    }

    while (i >= 0) {
      int t = num1[i--] - '0' + carryBit;
      result.push_back(t % 10 + '0');
      carryBit = t / 10;
    }

    while (j >= 0) {
      int t = num2[j--] - '0' + carryBit;
      result.push_back(t % 10 + '0');
      carryBit = t / 10;
    }
    if (carryBit != 0)
      result.push_back(carryBit + '0');
    reverseString(result);

    return result;
  }

  void reverseString(string& str) {
    int l = str.size();
    for (int i = 0; i < l / 2; i++) {
      char c = str[i];
      str[i] = str[l - i - 1];
      str[l - i - 1] = c;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  string num1 = "123456789";
  string num2 = "987654321";
  cout << s.multiply(num1, num2) << endl;
  return 0;
}
