#include <iostream>
#include <string>
using namespace std;

int b[103];

int mod(const string& x, int v) {
  int tmp = 0;
  for (int i = 0; i < x.length(); ++i) {
    tmp *= 10;
    tmp += (x.at(i) - '0');
    tmp %= v;
  }

  return tmp;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  while (t--) {
    int n;
    string x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    cin >> x;
    cout << "(";
    for (int i = 0; i < n; ++i) {
      cout << mod(x, b[i]);
      cout << (i != n - 1 ? "," : "");
    }
    cout << ")" << endl;
  }
  return 0;
}
