// Refrence: http://www.parashift.com/c++-faq/placement-new.html

#include <iostream>
using namespace std;

class Foo {
 public:
  Foo() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  ~Foo() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

char memory[sizeof(Foo)];

int main(int argc, char *argv[]) {
  Foo* f = new(memory) Foo();
  
  // Call the destructor explicitly. DO NOT delete.
  f->~Foo();
  return 0;
}
