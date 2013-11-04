// TODO(zhchbin): 这个代码完全看不懂的说。

#include <cassert>
#include <iostream>
using namespace std;

class SolutionTLE {
 public:
  bool isMatch(const char *s, const char *p) {
    if (*p == '*') {
      while (*p == '*')
        p++;
      if (*p == '\0')
        return true;
      while (*s != '\0' && !isMatch(s, p))
        s++;

      return *s != '\0';
    } else if (*p == '\0' || *s == '\0') {
      return *p == *s;
    } else if (*p == *s || *p == '?') {
      return isMatch(++s, ++p);
    } else {
      return false;
    }
  }
};

class Solution {
 public:
  bool isMatch(const char *s, const char *p) {
    const char* star_p = NULL, * star_s = NULL;

    while (*s != '\0') {
      if (*p == '?' || *p == *s) {
        p++;
        s++;
      } else if (*p == '*') {
        while (*p == '*')
          p++;
        if (*p == '\0')
          return true;
        star_p = p;
        star_s = s;
      } else if ((*p != '\0' || *p != *s) && star_p != NULL) {
        s = ++star_s;
        p = star_p;
      } else {
        return false;
      }
    }

    while (*p) {
      if (*p++ != '*')
        return false;
    }

    return true;
  }
};


struct TestInput {
  const char *s;
  const char *p;
  bool expected;
};

int main(int argc, char *argv[]) {
  TestInput input[] = {
    {"aa", "a", false},
    {"aa", "aa", true},
    {"aaa", "aa", false},
    {"aa", "*", true},
    {"aa", "a*", true},
    {"ab", "?*", true},
    {"aab", "c*a*b", false},
    {"aabb", "a*b", true},
  };

  Solution s;
  for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
    assert(s.isMatch(input[i].s, input[i].p) == input[i].expected);
  }

  return 0;
}
