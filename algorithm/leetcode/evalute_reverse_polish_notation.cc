// URL: https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
#include "common.h"

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    int num1, num2;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i] == "+" ||
          tokens[i] == "-" ||
          tokens[i] == "*" ||
          tokens[i] == "/") {
        PopTwoOperand(st, num1, num2);
        if (tokens[i] == "+")
          st.push(num1 + num2);
        else if (tokens[i] == "-")
          st.push(num2 - num1);
        else if (tokens[i] == "*")
          st.push(num1 * num2);
        else if (tokens[i] == "/")
          st.push(num2 / num1);
      } else {
        st.push(StringToInt(tokens[i]));
      }
    }

    return st.top();
  }

  int StringToInt(const string& str) {
    assert(!str.empty());
    bool negative = false;
    int i = 0;

    if (str[0] == '-') {
      ++i;
      negative = true;
    } else if (str[0] == '+') {
      ++i;
    }

    int num = 0;
    for (; i < str.size(); ++i) {
      num *= 10;
      num += (str[i] - '0');
    }

    return negative ? -num : num;
  }

  bool PopTwoOperand(stack<int>& st, int& val1, int& val2) {
    if (st.empty())
      return false;
    val1 = st.top();
    st.pop();
    if (st.empty())
      return false;
    val2 = st.top();
    st.pop();
    return true;
  }
};

int main(int argc, char *argv[]) {
  string strs[] = {"3","-4","+"};
  vector<string> tokens(strs, strs + ARRAY_SIZE(strs));
  Solution s;
  cout << s.evalRPN(tokens) << endl;
  return 0;
}
