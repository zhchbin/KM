#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct Job {
  int pri;
  int pos;
  bool operator!=(const Job& rhs) {
    return pri != rhs.pri || pos != rhs.pos;
  }
  bool operator==(const Job& rhs) {
    return pri == rhs.pri && pos == rhs.pos;
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, pos;
    cin >> n >> pos;
    Job tmp;
    list<Job> jobs;
    for (int i = 0; i < n; i++) {
      cin >> tmp.pri;
      tmp.pos = i;
      jobs.push_back(tmp);
    }

    int ans = 0;
    while (!jobs.empty()) {
      tmp = *jobs.begin();
      jobs.pop_front();
      Job max = tmp;
      for (list<Job>::iterator it = jobs.begin(); it != jobs.end(); it++) {
        if (max.pri < it->pri)
          max = *it;
      }

      if (max != tmp) {
        jobs.push_back(tmp);
      } else {
        if (tmp.pos == pos) {
          cout << (ans + 1) << endl;
          break;
        }
        ans++;
      }
    }
  }

  return 0;
}
