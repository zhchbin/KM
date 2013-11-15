#include <iostream>
using namespace std;

class Solution {
 public:
  int removeElement(int A[], int n, int elem) {
    int last = n - 1;
    while (last >= 0 && A[last] == elem)
      last--;

    for (int i = 0; i < last; i++) {
      if (A[i] == elem) {
        A[i] = A[last];

        do {
          last--;
        } while (last >= 0 && A[last] == elem);
      }
    }

    return last + 1;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  int A[] = {1, 1, 1, 1, 10};
  int l = s.removeElement(A, 5, 10);
  for (int i = 0; i < l; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}
