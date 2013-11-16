#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string multipy(const string& a, const string& b) {
  if (a == "0" || b == "0")
    return "0";
  int l = a.size() + b.size();

  int *res = new int[l];
  memset(res, 0, sizeof(int) * l);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j)
      res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
  }

  string ans(l, '0');
  for (int i = l - 1; i > 0; --i) {
    if (res[i] > 9)
      res[i - 1] += (res[i] / 10);

    ans[i] += res[i] % 10;
  }
  ans[0] += res[0] % 10;

  delete []res;
  return ans[0] == '0' ? string(ans.begin() + 1, ans.end()) : ans;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    cout << multipy(a, b) << endl;
  }
  return 0;
}
