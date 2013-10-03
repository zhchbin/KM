#include <iostream>
using namespace std;

int data[1002];
int table[1002][1002];

int dp(int hd, int tl) {
  if (hd > tl)
    return 0;

  if (table[hd][tl] != 0)
    return table[hd][tl];

  int left, right;
  if (data[hd + 1] >= data[tl])
    left = dp(hd + 2, tl) + data[hd] - data[hd + 1];
  else
    left = dp(hd + 1, tl - 1) + data[hd] - data[tl];

  if (data[hd] >= data[tl - 1])
    right = dp(hd + 1, tl - 1) + data[tl] - data[hd];
  else
    right = dp(hd, tl - 2) + data[tl] - data[tl - 1];

  table[hd][tl] = std::max(left, right);

  return table[hd][tl];
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  int n;
  int counter = 1;
  while (cin >> n && n != 0) {
    for (int i = 0; i < n; ++i) {
      cin >> data[i];
    }

    for (int i = 0; i < 1002; ++i)
      for (int j = 0; j < 1002; ++j)
        table[i][j] = 0;

    cout << "In game " << counter++
         << ", the greedy strategy might lose by as many as "
         << dp(0, n - 1) << " points."
         << endl;
  }

  return 0;
}
