#ifndef  COMMON_H_
#define  COMMON_H_

#include <iostream>
#include <stdlib.h>

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#ifndef NDEBUG
#define ASSERT(condition, message)                                         \
    do {                                                                   \
      if (!(condition)) {                                                  \
        std::cerr << "Assertion `" #condition "` failed in " << __FILE__   \
                  << " line " << __LINE__ << ": " << message << std::endl; \
        std::exit(EXIT_FAILURE);                                           \
      }                                                                    \
    } while (false)
#else
#define ASSERT(condition, message) do {} while (false)
#endif

#endif  // COMMON_H_
