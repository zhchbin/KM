// URL: http://oj.leetcode.com/problems/longest-valid-parentheses/
//
// Problem: Given a string containing just the characters '(' and ')', find the
//          length of the longest valid (well-formed) parentheses substring.
//          For "(()", the longest valid parentheses substring is "()", which
//          has length = 2. Another example is ")()())", where the longest valid
//          parentheses substring is "()()", which has length = 4.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    const char* p = s.c_str();
    stack<const char*> stk;
    int length = 0;
    while (*p != '\0') {
      if (*p == '(') {
        stk.push(p);
      } else {
        if (!stk.empty() && *stk.top() != ')') {
          stk.pop();
          length = max(length, p - (stk.empty() ? s.c_str() - 1 : stk.top()));
        } else {
          stk.push(p);
        }
      }
      p++;
    }

    return length;
  }
};

int main() {
  Solution s;
  cout << s.longestValidParentheses("()()()))") << endl;
  cout << s.longestValidParentheses(")()())") << endl;
  cout << s.longestValidParentheses("()(()()())") << endl;

  return 0;
}
