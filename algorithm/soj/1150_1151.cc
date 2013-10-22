#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;

void opA(string& state, string& result) {
  result[0] = state[4];
  result[1] = state[5];
  result[2] = state[6];
  result[3] = state[7];
  result[4] = state[0];
  result[5] = state[1];
  result[6] = state[2];
  result[7] = state[3];
}

void opB(string& state, string& result) {
  result[0] = state[3];
  result[1] = state[0];
  result[2] = state[1];
  result[3] = state[2];
  result[4] = state[7];
  result[5] = state[4];
  result[6] = state[5];
  result[7] = state[6];
}

void opC(string& state, string& result) {
  result[0] = state[0];
  result[1] = state[5];
  result[2] = state[1];
  result[3] = state[3];
  result[4] = state[4];
  result[5] = state[6];
  result[6] = state[2];
  result[7] = state[7];
}

void bfs(map<string, string>& m) {
  bool flag = false;
  queue<string> q;
  q.push("12348765");
  m["12348765"] = "";
  string t, state = "12348765";

  while (!q.empty()) {
    t = q.front();
    q.pop();

    opA(t, state);
    if (m.find(state) == m.end()) {
      q.push(state);
      m[state] = m[t] + 'A';
    }

    opB(t, state);
    if (m.find(state) == m.end()) {
      q.push(state);
      m[state] = m[t] + 'B';
    }

    opC(t, state);
    if (m.find(state) == m.end()) {
      q.push(state);
      m[state] = m[t] + 'C';
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  map<string, string> m;
  bfs(m);

  while (scanf("%d", &n) && n != -1) {
    int tmp;
    string state = "12348765";
    for (int i = 0; i < 8; i++) {
      scanf("%d", &tmp);
      state[i] = tmp + '0';
    }
    if (m.find(state) != m.end() && m[state].size() <= n)
      printf("%d %s\n", m[state].size(), m[state].c_str());
    else
      printf("-1\n");
  }
  return 0;
}
