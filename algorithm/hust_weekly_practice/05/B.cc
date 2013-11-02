#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reserve(vector<int>& nums, int size) {
  for (int i = 0; i < size / 2; i++) {
    int t = nums[i];
    nums[i] = nums[size - i - 1];
    nums[size - i - 1] = t;
  }
}

void dfs(vector<int>& nums, int size) {
  if (size == 0) {
    cout << 0 << endl;
    return;
  }
  int max = nums[0];
  int maxIndex = 0;
  for (int i = 1; i < size; i++) {
    if (max < nums[i]) {
      maxIndex = i;
      max = nums[i];
    }
  }
  if (maxIndex != size - 1) {
    if (maxIndex != 0) {
      cout << nums.size() - maxIndex << " ";
      reserve(nums, maxIndex + 1);
    }

    cout << nums.size() - size + 1 << " ";
    reserve(nums, size);
  }

  dfs(nums, size - 1);
}

void solve(const string& str) {
  vector<int> vs;
  int v = -1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != ' ') {
      if (v == -1)
        v = (str[i] - '0');
      else {
        v *= 10;
        v += (str[i] - '0');
      }
    } else {
      vs.push_back(v);
      v = -1;
    }
  }
  vs.push_back(v);
  dfs(vs, vs.size());
}

int main(int argc, char *argv[]) {
  string str;
  while (getline(cin, str)) {
    cout << str << endl;
    solve(str);
  }
  return 0;
}
