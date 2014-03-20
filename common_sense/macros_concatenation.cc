// Refrence: http://gcc.gnu.org/onlinedocs/cpp/Concatenation.html
//
// Use: `g++ -E macros_concatenation.cc` to get the preprocessing result.

#define COMMAND(NAME)  { #NAME, NAME ## _command }

struct command {
  char *name;
  void (*function) (void);
};

int main(int argc, char *argv[]) {
  struct command commands[] = {
    COMMAND(quit),
    COMMAND(help),
  };

  return 0;
}
