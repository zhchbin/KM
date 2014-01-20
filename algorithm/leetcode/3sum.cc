// URL: http://oj.leetcode.com/problems/3sum/
//
// Problem: Given an array S of n integers, are there elements a, b, c in S such
//          that a + b + c = 0? Find all unique triplets in the array which
//          gives the sum of zero.
// Note: Elements in a triplet (a,b,c) must be in non-descending order.
//        (ie, a ≤ b ≤ c)
//       The solution set must not contain duplicate triplets.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<int> v;
    vector<vector<int> > result;
    if (num.size() < 2)
      return result;

    sort(num.begin(), num.end());
    int start, end;
    for (int i = 0; i < num.size() - 2; ++i) {
      int t = 0 - num[i];
      start = i + 1;
      end = num.size() - 1;
      while (start < end) {
        if (num[start] + num[end] > t) {
          --end;
        } else if (num[start] + num[end] < t) {
          ++start;
        } else {
          v.push_back(num[i]);
          v.push_back(num[start]);
          v.push_back(num[end]);
          result.push_back(v);
          v.clear();
          do {
            ++start;
          } while (start < end && num[start] == num[start - 1]);
          do {
            --end;
          } while (start < end && num[end] == num[end + 1]);
        }
      }

      while (i < num.size() - 1 && num[i] == num[i + 1])
        i++;
    }

    return result;
  }
};

int main() {
  int data[] = {-1, 0, 1, 2, -1, -4};
  //int data[] = {0};
  vector<int> num(data, data + sizeof(data) / sizeof(data[0]));
  vector<vector<int> > sums = Solution().threeSum(num);
  for (int i = 0; i < sums.size(); ++i) {
    for (int j = 0; j < sums[i].size(); ++j)
      cout << sums[i][j] << " ";
    cout << endl;
  }
  return 0;
}
