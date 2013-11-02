#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

string names[11];
int money[11];

int main(int argc, char *argv[]) {
  int n;
  bool flag = false;

  while (scanf("%d", &n) != EOF) {
    if (flag == true)
      cout << endl;
    map<string, int> ms;
    memset(money, 0, sizeof(money));
    for (int i = 0; i < n; i++) {
      cin >> names[i];
      ms[names[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      string name;
      cin >> name;
      int amount;
      int nums;
      cin >> amount >> nums;
      if (nums != 0)
        money[ms[name]] -= (amount - amount % nums);
      int t = 0;
      if (nums != 0)
        t = amount / nums;

      for (int i = 0; i < nums; i++) {
        cin >> name;
        money[ms[name]] += t;
      }
    }

    for (int i = 0; i < n; i++)
      cout << names[i] << " " << money[i] << endl;
    flag = true;
  }
  return 0;
}
