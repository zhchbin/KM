// 题目：http://soj.me/1063
//
// 大意：有一堆员工，员工的上司是所有工资比该员工高的人中最少工资，且身高比其高
//       或者相等的那一位。输入员工的ID，工资，身高，及多个查询，对每个查询输出
//       其老板，及其下属人数。
//
// 解法：先对员工的工资作排序，对每个员工向上搜索自己的老板。同时注意更新老板的
//       下属人数即可。
//
// 遇到的问题：1）输入输出一开始用了cin, cout超时。
//             2）一开始没有注意到一个员工的身高能与其直接上司的一样，WA。
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

struct Emp {
  int id;
  int s;
  int h;
  int p;
  int sum;
};

Emp emps[30001];

int cmp(const Emp& lhs, const Emp& rhs) {
  return lhs.s < rhs.s;
}

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    map<int, int> ms;
    int m, q;
    scanf("%d %d", &m, &q);
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &(emps[i].id), &(emps[i].s), &(emps[i].h));
      emps[i].p = emps[i].sum = 0;
    }

    sort(emps, emps + m, cmp);
    for (int i = 0; i < m; i++) {
      ms[emps[i].id] = i;
      for (int j = i + 1; j < m; j++) {
        if (emps[j].h >= emps[i].h) {
          emps[i].p = emps[j].id;
          emps[j].sum += (emps[i].sum + 1);
          break;
        }
      }
    }

    int id;
    for (int i = 0; i < q; i++) {
      scanf("%d", &id);
      printf("%d %d\n", emps[ms[id]].p, emps[ms[id]].sum);
    }
  }
  return 0;
}
