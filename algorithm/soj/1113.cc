#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n && n != 0) {
    map<string, string> ip2id;
    map<string, string> result;
    for (int i = 0; i < n; ++i) {
      string ip, id;
      cin >> id >> ip;
      if (ip2id.find(ip) != ip2id.end())
        result[ip2id[ip]] = id;
      else
        ip2id[ip] = id;
    }

    map<string, string>::iterator it = result.begin();
    for (; it!= result.end(); it++) {
      cout << it->second << " is the MaJia of " << it->first << endl;
    }
    cout << endl;
  }
  return 0;
}
