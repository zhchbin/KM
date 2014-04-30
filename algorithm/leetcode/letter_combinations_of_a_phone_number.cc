// URL: http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "common.h"

string digitToLettersMap[] = {"abc", "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    string path;
    letterCombinationsRecursive(digits, 0, path, combinations);
    return combinations;
  }

  void letterCombinationsRecursive(const string& digits, int pos, string& path,
                                   vector<string>& combinations) {
    if (pos == digits.size()) {
      combinations.push_back(path);
      return;
    }

    int current_digit = digits[pos] - '0' - 2;
    const string& letters = digitToLettersMap[current_digit];
    for (int i = 0; i < letters.size(); ++i) {
      path.push_back(letters[i]);
      letterCombinationsRecursive(digits, pos + 1, path, combinations);
      path.pop_back();
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> combinations = s.letterCombinations("23");
  for (int i = 0; i < combinations.size(); ++i)
    cout << combinations[i] << endl;

  return 0;
}
