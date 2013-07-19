// warn_unused_result
// Found in versions: 3.3 3.4
// Description:
//     The `warn_unused_result' attribute causes a warning to be emitted
//     if a caller of the function with this attribute does not use its
//     return value.  This is useful for functions where not checking the
//     result is either a security problem or always a bug, such as
//     `realloc'.
//
//          int fn () __attribute__ ((warn_unused_result));
//          int foo ()
//          {
//            if (fn () < 0) return -1;
//            fn ();
//            return 0;
//          }
//
//     results in warning on line 5.

int fn() __attribute__ ((warn_unused_result));

int fn() {
  return 1;
}

int foo() {
  if (fn() < 0)
    return -1;
  fn();           // Warning: ignoring return value of ‘fn’. 
  return 0;
}

int main(int argc, char *argv[]) {
  foo();
  return 0;
}
