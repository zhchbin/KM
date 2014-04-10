// URL: http://oj.leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  typedef unordered_set<int> HashTable;

  int findLength(HashTable& table, int val) {
    if (table.find(val) == table.end())
      return 0;

    int l, r;
    l = r = 0;
    int t = val - 1;
    while (table.find(t) != table.end()) {
      l++;
      table.erase(t);
      t--;
    }
    t = val + 1;
    while (table.find(t) != table.end()) {
      r++;
      table.erase(t);
      t++;
    }

    return l + r + 1;
  }

  int longestConsecutive(vector<int>& nums) {
    HashTable table;
    for (int i = 0; i < nums.size(); ++i)
      table.insert(nums[i]);

    int longest = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int t = findLength(table, nums[i]);
      if (t > longest)
        longest = t;
    }

    return longest;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int data[] = {100, 1, 2, 3, 4, 99};
  vector<int> nums(data, data + sizeof(data) / sizeof(data[0]));
  cout << s.longestConsecutive(nums) << endl;
  return 0;
}
