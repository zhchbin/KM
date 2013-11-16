#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


struct classcomp {
  bool operator()(const string& str1, const string& str2) const {
    for (int i = 0; i < str1.size(); i++) {
      if (str1[i] == str2[i])
        continue;

      if (tolower(str1[i]) == tolower(str2[i])) {
        return str1[i] < str2[i];
      } else {
        return tolower(str1[i]) < tolower(str2[i]);
      }
    }

    // Should never reach here.
    return 0;
  }
};

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    set<string, classcomp> s;
    sort(str.begin(), str.end());
    do {
      s.insert(str);
    } while(std::next_permutation(str.begin(), str.end()));

    for (set<string>::iterator it = s.begin(); it != s.end(); ++it) {
      cout << *it << endl;
    }
  }

  return 0;
}
