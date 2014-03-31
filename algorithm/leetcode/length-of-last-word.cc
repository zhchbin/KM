// URL: http://oj.leetcode.com/problems/length-of-last-word/

#include <cassert>
#include <iostream>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(const char* s) {
    const char* p = s;
    int length = 0;
    int lastLength = -1;
    while (*p != '\0') {
      if (*p == ' ') {
        if (length != 0)
          lastLength = length;
        length = 0;
      } else {
        length++;
      }

      p++;
    }

    // Case like: "Hello   ".
    if (length == 0 && lastLength != -1)
      return lastLength;

    return length;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(s.lengthOfLastWord("Hello World") == 5);
  assert(s.lengthOfLastWord("Hello  World") == 5);
  assert(s.lengthOfLastWord("Hello   ") == 5);
  assert(s.lengthOfLastWord("  ") == 0);
  assert(s.lengthOfLastWord("") == 0);
  assert(s.lengthOfLastWord("This is a test  ") == 4);

  return 0;
}
