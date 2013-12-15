// Reference:  http://www.parashift.com/c%2B%2B-faq-lite/calling-virtuals-from-ctors.html

#include <iostream>
using namespace std;

class Base {
 public:
  Base() {
    // This call of polymorphic will be Base::foo(), because while exectuting
    // Base::Base(), the |this| object is not yet of type |Derive|. What's more,
    // if it invokes the override Derive::foo(), it will cause no end of grief
    // and havoc. Overrides can (and often do!) access non-static data members
    // declared in the Derived class, but since the non-static data members
    // declared in Derived are not initialized during the call to foo(), any use
    // of them within Derived::foo() would be a "use before initialized" error.
    // Bang, you're dead. So, C++ is protecting you from the danger.
    foo();
  }

  virtual ~Base() {}

  virtual void foo() {
    cout << "Base::foo()" << endl;
  }
};

class Derive : public Base {
 public:
  Derive() {}
  virtual ~Derive() {}

  virtual void foo() {
    cout << "Derive::foo()" << endl;
  }
};

int main(int argc, char *argv[]) {
  Base* b = new Derive();
  delete b;

  return 0;
}
