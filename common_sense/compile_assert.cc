// Note that compile_assert<false> will be a incomplete type.
template <bool assertion> struct compile_assert;
template <> struct compile_assert<true> {};

int main(int argc, char *argv[]) {
  compile_assert<100 == 100>();
  compile_assert<100 != 100>();         // Here will be a compile error.
  return 0;
}
