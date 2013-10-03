#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int quaters[301];

struct Node {
  int f;
  int l;
  double aver;
};

int cmp(const Node& lhs, const Node& rhs) {
  if (lhs.aver != rhs.aver)
    return lhs.aver > rhs.aver;
  else if ((lhs.l - lhs.f) != (rhs.l - rhs.f))
    return lhs.l - lhs.f > rhs.l - rhs.f;
  else
    return lhs.l < rhs.l;
}

int main() {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int k = 0; k < N; k++) {
    int q, best, mini;
    cin >> q >> best >> mini;
    for (int i = 0; i < q; ++i) {
      cin >> quaters[i];
    }

    vector<Node> vs;

    for (int i = 0; i < q; ++i) {
      int p = mini;
      while (p < q - i + 1) {
        int j;
        int sum = 0;
        for (j = i; j < i + p; ++j)
          sum += quaters[j];

        Node node;
        node.f = i + 1;
        node.l = j;
        node.aver = (double)sum / p;

        vs.push_back(node);
        p++;
      }
    }

    sort(vs.begin(), vs.end(), cmp);
    cout << "Result for run " << k + 1 << ":" << endl;
    for (int i = 0; i < best && i < vs.size(); ++i) {
      cout << vs[i].f << "-" << vs[i].l << endl;
    }

  }
  return 0;
}
