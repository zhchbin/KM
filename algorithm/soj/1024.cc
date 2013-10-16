#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

struct Road {
  int id;
  int dis;
  Road(int id_, int dis_) : id(id_), dis(dis_) {}
};

int n, k;
vector<Road> roads[10001];
int ans;
bool isVisited[10001];

void dfs(int p, int cur) {
  for (int i = 0; i < roads[p].size(); i++) {
    if (!isVisited[roads[p][i].id]) {
      isVisited[roads[p][i].id] = true;
      if (cur + roads[p][i].dis > ans)
        ans = cur + roads[p][i].dis;

      dfs(roads[p][i].id, cur + roads[p][i].dis);
      isVisited[roads[p][i].id] = false;
    }
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    scanf("%d", &k);
    ans = 0;
    memset(isVisited, 0, sizeof(isVisited));

    int b, e, c;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d%d", &b, &e, &c);
      roads[b].push_back(Road(e, c));
      roads[e].push_back(Road(b, c));
    }

    isVisited[k] = true;
    dfs(k, 0);
    cout << ans << endl;
    for (int i = 0; i <= n; i++)
      roads[i].clear();
  }
  return 0;
}
