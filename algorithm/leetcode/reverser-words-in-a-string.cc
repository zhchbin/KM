// URL: http://oj.leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  void reverseWords(string& s) {
    int last = 0;
    int size = s.size();
    vector<string> words;

    for (int i = 0; i <= size; ++i) {
      if (i == size || s[i] == ' ') {
        string tmp = s.substr(last, i - last);
        TrimWhiteSpace(tmp);

        if (!tmp.empty())
          words.push_back(tmp);
        last = i + 1;
      }
    }

    s = "";
    if (words.empty())
      return;

    int i = words.size() - 1;
    for (; i > 0; --i)
      s += (words[i] + ' ');
    s += words[i];
  }

  void TrimWhiteSpace(string& str) {
    size_t first_good_char = str.find_first_not_of(' ');
    size_t last_good_char = str.find_last_not_of(' ');
    if (first_good_char == string::npos || last_good_char == string::npos)
      str = "";
    else
      str = str.substr(first_good_char, last_good_char - first_good_char + 1);
  }
};

int main(int argc, char *argv[]) {
  string s = "the sky is blue";
  Solution solution;
  solution.reverseWords(s);
  cout << "|" << s << "|" << endl;

  s = " the    ";
  solution.reverseWords(s);
  cout << "|" << s << "|" << endl;

  s = "  ";
  solution.reverseWords(s);
  cout << "|" << s << "|" << endl;

  return 0;
}
