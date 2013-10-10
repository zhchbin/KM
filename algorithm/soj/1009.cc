#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;
LL factors[10];
int count;
int p[10] = {11, 23, 29, 37, 41, 43, 47, 53, 59};
int flag = 0;

void getFactors(LL v) {
  flag = 0;
  count = 0;
  LL j = 2;
  for (LL i = 2; i * i <= v; i++) {
    if (v % i == 0) {
      flag = 1;
      factors[count++] = i;
      v /= i;
      i--;
    }
  }

  if (flag)
    factors[count++] = v;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= 8 && p[i] <= n; ++i) {
    LL tmp = (long long)pow(2.0, p[i]) - 1;
    getFactors(tmp);
    if (flag) {
      for (int j = 0; j < count; j++)
        cout << factors[j] << ((j == count - 1) ? " = " : " * ");

      cout << tmp;
      cout << " = ( 2 ^ " << p[i] <<" ) - 1";
      cout << endl;
    }
  }

  return 0;
}
