#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getDistance(const string& lhs, const string& rhs) {
  int sum = 0;
  int m[5];
  for (int i = 0; i < lhs.length(); i++)
    m[lhs[i] - 'A'] = i;

  int result = 0;
  for (int i = 0; i < rhs.length(); i++) {
    for (int j = i + 1; j < rhs.length(); j++)
      if (m[rhs[i] - 'A'] > m [rhs[j] - 'A'])
        result++;
  }

  return result;
}

int main(int argc, char *argv[]) {
  vector<string> vs;
  string strs[101];
  string chars = "ABCDE";
  string ans;
  do {
    vs.push_back(chars);
  } while (next_permutation(chars.begin(), chars.end()));

  int n;
  while (cin >> n && n != 0) {
    for (int i = 0; i < n; i++)
      cin >> strs[i];

    int min = 0x3fffffff;
    for (int i = 0; i < vs.size(); i++) {
      int sum = 0;
      for (int j = 0; j < n; j++)
        sum += getDistance(vs[i], strs[j]);

      if (min > sum) {
        min = sum;
        ans = vs[i];
      }
    }
    cout << ans << " is the median ranking with value " << min << "." << endl;
  }

  return 0;
}
