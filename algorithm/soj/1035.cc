#include <iostream>
#include <string>
#include <set>

using namespace std;

string Correspond(const string& strand) {
  string result;

  for (int i = 0; i < strand.length(); ++i) {
    switch (strand.at(i)) {
      case 'A':
        result.append("T");
        break;
      case 'T':
        result.append("A");
        break;
      case 'C':
        result.append1035.cc
        1035.cc
      case 'G':
        result.append("C");
        break;
      default:
        break;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string tmp;
    set<string> strands;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      string pair = Correspond(tmp);
      if (strands.find(pair) != strands.end()) {
        strands.erase(pair);
        counter++;
      } else {
        strands.insert(tmp);
      }
    }
    cout << counter << endl;
  }
  return 0;
}
