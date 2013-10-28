#include <cassert>
#include <iostream>

bool isPowerOfTwo(unsigned int x) {
  return x && !(x & (x - 1));
}

int main(int argc, char *argv[]) {
  bool test_data[10] = {false, true, true, false, true,
                        false, false, false, true, false};
  for (int i = 0; i < 10; i++)
    assert(test_data[i] == isPowerOfTwo(i));

  return 0;
}
