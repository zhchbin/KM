#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 1000000000

int primes[SIZE / 5];
int count = 0;

bool isUglyNum[SIZE];

int main(int argc, char *argv[]) {
  //cout << "The 1500'th ugly number is " << 859963392 << "." << endl;
  memset(isUglyNum, true, sizeof(isUglyNum));

  for (int i = 2; i < SIZE; i++) {
    if (isUglyNum[i]) {
      primes[count++] = i;
      for (int j = i + i; j < SIZE; j += i) {
        isUglyNum[j] = false;
      }
    }
  }

  cout << count << endl;
  memset(isUglyNum, true, sizeof(isUglyNum));

  for (int i = 3; i < count; i++) {
    int p = primes[i];
    for (int j = p; j < SIZE; j += p) {
      isUglyNum[j] = false;
    }
  }

  int cnt = 0;
  for (int i = 1; i < SIZE; i++) {
    if (isUglyNum[i]) {
      cnt++;
    }

    if (cnt == 1500) {
      cout << i << endl;
      break;
    }
  }

  cout << cnt << endl;

  return 0;
}
