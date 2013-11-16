#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
  vector<string> vs;
  string str;
  int maxL = 0;
  while (cin >> str && str != "#") {
    vs.push_back(str);
    if (str.length() > maxL)
      maxL = str.length();
  }

  bool has_output[26];
  memset(has_output, false, sizeof(has_output));
  for (int i = 0; i < maxL; i++) {
    for (int j = 0; j < vs.size(); ++j) {
      if (i >= vs[j].length())
        continue;

      char c = vs[j][i];
      if (has_output[c - 'A'])
        continue;
      cout << c;
      has_output[c - 'A'] = true;
    }
  }
  cout << endl;

  return 0;
}
