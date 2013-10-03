#include <iostream>
#include <stack>

using namespace std;

int couple[200005];

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n && n != 0) {

    for (int i = 0; i < n; i++) {
      int t1, t2;
      cin >> t1 >> t2;
      couple[t1] = couple[t2] = i;
    }

    stack<int> s;
    for (int i = 1; i <= 2 * n; ++i) {
      if (s.empty()) {
        s.push(i);
        continue;
      }

      couple[s.top()] == couple[i] ? s.pop() : s.push(i);
    }
    cout << (s.empty() ? "Yes" : "No") << endl;
  }

  return 0;
}
