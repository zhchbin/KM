// URL: http://oj.leetcode.com/problems/valid-parentheses/

#include <cassert>

#include <map>
#include <stack>
#include <string>

using std::map;
using std::stack;
using std::string;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';

    int i = 0;
    while (i < s.size()) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stk.push(s[i]);
      } else if (!stk.empty() && stk.top() == m[s[i]]) {
        stk.pop();
      } else {
        return false;
      }

      ++i;
    }

    return stk.empty();
  }
};

int main() {
  Solution s;
  assert(!s.isValid("())]"));
  assert(s.isValid("()"));
  assert(!s.isValid("[((}))]"));

  return 0;
}
#include <cassert>

#include <map>
#include <stack>
#include <string>

using std::map;
using std::stack;
using std::string;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    map<char, char> m;
    m[')'] = '(';
    m[']'] = '[';
    m['}'] = '{';

    int i = 0;
    while (i < s.size()) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        stk.push(s[i]);
      } else if (!stk.empty() && stk.top() == m[s[i]]) {
        stk.pop();
      } else {
        return false;
      }

      ++i;
    }

    return stk.empty();
  }
};

int main() {
  Solution s;
  assert(!s.isValid("())]"));
  assert(s.isValid("()"));
  assert(!s.isValid("[((}))]"));

  return 0;
}
