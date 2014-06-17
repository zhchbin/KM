// URL: https://oj.leetcode.com/problems/edit-distance/

#include "common.h"

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int kMaxLength = 502;
    int dis[kMaxLength][kMaxLength] = {0};
    for (int i = 0; i <= word1.length(); ++i)
      dis[0][i] = i;
    for (int i = 0; i <= word2.length(); ++i)
      dis[i][0] = i;

    for (int i = 0; i < word1.length(); ++i) {
      for (int j = 0; j < word2.length(); ++j) {
        dis[j + 1][i + 1] = std::min(dis[j][i] + (word1[i] != word2[j]),
                                     std::min(dis[j][i + 1] + 1,
                                              dis[j + 1][i] + 1));
      }
    }

    return dis[word2.length()][word1.length()];
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.minDistance("ad", "ad") << endl;
  cout << s.minDistance("adc", "adb") << endl;
  cout << s.minDistance("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab"
                        "cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd"
                        "efghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef"
                        "ghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh"
                        "ijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
                        "klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
                        "mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
                        "opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
                        "qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
                        "stuvwxyzabcdef",
                        "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabc"
                        "defghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcde"
                        "fghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg"
                        "hijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghi"
                        "jklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk"
                        "lmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"
                        "nopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmno"
                        "pqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopq"
                        "rstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrs"
                        "tuvwxyzabcdefg") << endl;
  return 0;
}
