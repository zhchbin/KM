// Compiler: g++(GCC) 4.7.0
// http://gcc.gnu.org/onlinedocs/gcc/Name-lookup.html
// Line 1 & 2 will cause compilation error.
//   In member function 'int Derived<T>::getBar()': error: there are note
//   arguments to 'foo' that depend on a template parameter, so a declaration
//   of 'foo' must be available [-fpermissive]
//   error: 'bar' was not declared in this scope

#include <iostream>

template<typename T>
class Base {
 protected:
  int bar;
  void foo() {}
};

template<typename T>
class Derived : public Base<T> {
 public:
  int getBar() {
    foo();              // 1, Correct: this->foo(); or Base<T>::foo();
    return bar;         // 2, Correct: this->bar; or Base<T>::bar;
  }
};

int main(int argc, char *argv[]) {
  Derived<int> d;
  return 0;
}
