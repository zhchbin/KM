// URL: http://oj.leetcode.com/problems/candy/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1])
        candies[i] = candies[i - 1] + 1;
    }

    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
        candies[i] = candies[i + 1] + 1;
    }

    int sum = 0;
    for (int i = 0; i < candies.size(); ++i)
      sum += candies[i];
    return sum;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  //int data[] = {4, 1, 3, 1, 1, 0, 9, 3, 2};
  int data[] = {1, 2, 4};
  vector<int> ratings(data, data + sizeof(data) / sizeof(data[0]));
  cout << s.candy(ratings) << endl;

  return 0;
}
