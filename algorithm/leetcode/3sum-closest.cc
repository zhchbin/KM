// URL: http://oj.leetcode.com/problems/3sum-closest/
#include "common.h"

class Solution {
 public:
  int threeSumClosest(vector<int> &num, int target) {
    int closestSum = 0;
    int diff = 0x4f4f4f4f;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size() - 2; ++i) {
      int j = i + 1;
      int k = num.size() - 1;
      while (j < k) {
        int tmp = num[i] + num[j] + num[k];
        if (tmp == target)
          return tmp;

        if (abs(tmp - target) < diff) {
          diff = abs(tmp - target);
          closestSum = tmp;
        }

        tmp > target ? k-- : j++;
      }
    }
    return closestSum;
  }
};

int main(int argc, char *argv[]) {
  int data[] = {-1, 2, 1, 4};
  vector<int> num(data, data + ARRAY_SIZE(data));
  cout << Solution().threeSumClosest(num, 1) << endl;

  return 0;
}
