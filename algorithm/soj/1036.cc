#include <iostream>
#include <string>
using namespace std;

char plain[100][100];

int main(int argc, char *argv[]) {
  string keyword;
  string text;
  while (cin >> keyword && keyword != "THEEND") {
    int counter = 0;
    cin >> text;
    char c = 'A';
    int rows = text.length() / keyword.length();
    size_t pos = keyword.find(c);

    while (c <= 'Z') {
      if (pos == string::npos) {
        c++;
      } else {
        for (int i = 0; i < rows; i++)
          plain[i][pos] = text.at(counter * rows + i);
        counter++;
      }

      pos = keyword.find(c, pos + 1);
    }

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < keyword.length(); j++)
        cout << plain[i][j];
    cout << endl;
  }

  return 0;
}
