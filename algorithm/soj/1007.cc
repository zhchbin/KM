#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> vs;

string reverseString(const string& s) {
  string tmp(s);
  for (int i = 0; i < s.length(); ++i)
    tmp[i] = s[s.length() - i - 1];
  return tmp;
}

void solve(const string& str) {
  vs.clear();
  int i = 0;
  while (i < str.length() / n) {
    string tmp = str.substr(i * n, n);
    vs.push_back(i % 2 == 0 ? tmp : reverseString(tmp));
    i++;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < vs.size(); ++j)
      cout << vs[j].at(i);
  cout << endl;
}

int main(int argc, char *argv[]) {
  string str;
  ios_base::sync_with_stdio(false);
  while (cin >> n && n != 0) {
    cin >> str;
    solve(str);
  }
  return 0;
}
