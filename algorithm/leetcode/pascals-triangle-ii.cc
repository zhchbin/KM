// URL: http://oj.leetcode.com/problems/pascals-triangle-ii/
//
// Problem: Given an index k, return the kth row of the Pascal's triangle.
//          For example, given k = 3, Return [1,3,3,1].
//          Note:
//            Could you optimize your algorithm to use only O(k) extra space?
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    for (int i = 0; i <= rowIndex; ++i) {
      for (int j = i - 1; j > 0; --j)
        result[j] = result[j] + result[j - 1];
      result.push_back(1);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = Solution().getRow(3);
  for (int i = 0; i < result.size(); ++i)
    cout << result[i] << endl;

  return 0;
}
