// Compiler: g++(GCC) 4.7.0
//    g++ lambda_of_cpp.cc --std=c++11
//
// Reference: http://www.cprogramming.com/c++11/c++11-lambda-closures.html

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Foo {
 public:
  explicit Foo(int value) : value_(value) {}
  void test() {
    // Pass pointer to the lambda, a very silly demo, but illustrative way.
    [this]() {
      std::cout << value_ << std::endl;
    }();
  }

 private:
  int value_;
};

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 4};
  std::vector<int> v(arr, arr + 4);
  // Simple demo use like function object.
  for_each(v.begin(), v.end(), [](int value) {
    std::cout << value << " ";
  });
  std::cout << std::endl;

  // Return type 'int' explicitly.
  auto func = [&](int value) -> int { return value + 1; };
  std::cout << func(100) << std::endl;

  //[]	Capture nothing (or, a scorched earth strategy?)
  //[&]	Capture any referenced variable by reference
  //[=]	Capture any referenced variable by making a copy
  //[=, &foo]	Capture any referenced variable by making a copy, but Capture
  //          variable foo by reference
  //[bar]	Capture bar by making a copy; don't copy anything else
  //[this]	Capture the this pointer of the enclosing class
  std::string s1 = "1234";
  std::string s2 = "abd";
  std::cout << &s1 << std::endl;
  std::cout << &s2 << std::endl;
  auto goo = [=, &s1](const std::string& str) -> const std::string {
    std::cout << &s1 << std::endl;        // Use "s1" by reference.
    std::cout << &s2 << std::endl;        // Use "s2" by copy.
    return str;
  };
  std::cout << goo("abc") << std::endl;

  Foo(100).test();

  return 0;
}
