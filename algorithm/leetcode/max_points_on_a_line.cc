// URL: https://oj.leetcode.com/problems/max-points-on-a-line/
#include "common.h"

#include <climits>
#include <unordered_map>

class Solution {
 public:
  int maxPoints(vector<Point> &points) {
    int res = 0;
    std::unordered_map<float, int> counter;

    for (int i = 0; i < points.size(); ++i) {
      counter.clear();
      counter[INT_MIN] = 0;
      int dup = 1;
      for (int j = 0; j < points.size(); ++j) {
        if (j == i)
          continue;

        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          ++dup;
          continue;
        }
        int diff_x = points[i].x - points[j].x;
        int diff_y = points[i].y - points[j].y;
        if (diff_x == 0)
          counter[INT_MIN]++;
        else
          counter[(float)diff_y / diff_x]++;
      }

      for (auto it = counter.begin(); it != counter.end(); ++it) {
        if (it->second + dup > res)
          res = it->second + dup;
      }
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  Point points[] = {{84, 250}, {0, 0}, {1, 0}, {0, -70}, {0, -70}, {1, -1},
                    {21, 10}, {42, 90}, {-42, -230}};
  std::vector<Point> ps(points, points + ARRAY_SIZE(points));
  Solution s;
  std::cout << s.maxPoints(ps) << std::endl;

  return 0;
}
