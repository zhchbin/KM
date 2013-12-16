// URL: http://oj.leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    string str;
    vector<string> vs;
    stack<char> s;
    solve(vs, n, n, s, str);

    return vs;
  }

  void solve(vector<string>& vs, int leftN, int rightN, stack<char>& s, string str) {
    if (leftN == 0 && rightN == 0) {
      vs.push_back(str);
      return;
    }

    if (leftN != 0) {
      s.push('(');
      solve(vs, leftN - 1, rightN, s, str + "(");
      s.pop();
    }

    // A better solution, do not use the stack and change to:
    // if (rightN > leftN)
    if (rightN != 0) {
      if (s.empty())
        return;
      s.pop();
      solve(vs, leftN, rightN - 1, s, str + ")");
      str = str.substr(0, str.size() - 1);
      s.push('(');
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> vs = s.generateParenthesis(10);
  for (int i = 0; i < vs.size(); ++i)
    cout << vs[i] << endl;

  return 0;
}
