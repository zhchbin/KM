// URL: https://oj.leetcode.com/problems/valid-palindrome/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty())
      return true;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
      while (ShouldIgnore(s.at(i)) && i < j)
        i++;
      while (ShouldIgnore(s.at(j)) && i < j)
        j--;
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }

    return true;
  }

  bool ShouldIgnore(char c) {
    if (c >= '0' && c <= '9')
      return false;
    if (c >= 'a' && c <= 'z')
      return false;

    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.isPalindrome("aba") << endl;
  cout << s.isPalindrome("abac") << endl;
  cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
  cout << s.isPalindrome("race a car") << endl;
  return 0;
}
