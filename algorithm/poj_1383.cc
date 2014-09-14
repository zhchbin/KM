// URL: http://poj.org/problem?id=1383
//
// 题目描述：在一个迷宫里找到任两个节点'.'中最长路径的长度，其中迷宫有如下限制：
//           The labyrinth is designed in such a way that there is exactly one
//           path between any two free blocks.

#include <cstdio>
#include <queue>
using namespace std;

int r, c;
char labyrinth[1002][1002];
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

struct Point {
  int x;
  int y;
  int l;
  Point(int xx, int yy, int ll = 0) : x(xx), y(yy), l(ll) {}
};

Point BFS(const Point& start) {
  Point max_point(-1, -1, -1);
  queue<Point> q;
  q.push(start);

  while (!q.empty()) {
    Point t = q.front();
    q.pop();

    if (max_point.l < t.l)
      max_point = t;

    for (int i = 0; i < 4; ++i) {
      int x = t.x + dir_x[i];
      int y = t.y + dir_y[i];
      if (x < 0 || x >= r || y < 0 || y >= c)
        continue;
      if (labyrinth[x][y] != '.')
        continue;

      q.push(Point(x, y, t.l + 1));
      labyrinth[x][y] = '*';
    }
  }

  return max_point;
}

void reset() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (labyrinth[i][j] == '*')
        labyrinth[i][j] = '.';
    }
  }
}

int solve() {
  int max_length = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (labyrinth[i][j] == '.') {
        Point p = BFS(Point(i, j, 0));
        reset();
        p.l = 0;
        p = BFS(p);
        if (p.l > max_length)
          max_length = p.l;
      }
    }
  }

  return max_length;
}

int main(int argc, char *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &c, &r);
    for (int i = 0; i < r; ++i)
      scanf("%s", labyrinth[i]);
    printf("Maximum rope length is %d.\n", solve());
  }

  return 0;
}
