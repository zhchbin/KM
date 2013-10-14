#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

long target;
bool flag;
long ans;

void dfs(long num[], int size) {
  if (flag)
    return;

  if (num[0] <= target && num[0] > ans) {
    ans = num[0];
    if (ans == target) {
      flag = true;
      return;
    }
  }

  long arr[5];
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      // Move the num[i], num[j] out of the array.
      for (int k = 0, c = 1; k < size; ++k)
        if (i != k && j != k)
          arr[c++] = num[k];

      arr[0] = num[i] + num[j];
      dfs(arr, size - 1);

      arr[0] = num[i] - num[j];
      dfs(arr, size - 1);
      arr[0] = -arr[0];
      dfs(arr, size - 1);

      arr[0] = num[i] * num[j];
      dfs(arr, size - 1);

      int x = num[i], y = num[j];
      if (x < y)
        swap(x, y);
      if (y == 0 || x % y != 0)
        continue;

      arr[0] = x / y;
      dfs(arr, size - 1);
    }
  }
}

int main() {
  int t;
  long num[5];
  cin >> t;
  while (t--) {
    for (int i = 0; i < 5; i++)
      cin >> num[i];
    cin >> target;
    ans = -2000000000;
    flag = false;
    for (int i = 0; i < 5; i++)
      if (num[i] <= target && num[i] > ans)
        ans = num[i];

    dfs(num, 5);
    cout << ans << endl;
  }
}
