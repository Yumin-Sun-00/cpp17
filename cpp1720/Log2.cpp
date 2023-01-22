#include "Log2.h"
#include <iostream>

#if 0
//! 5 linker error: duplicate symbol
void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//!5
#endif

//!6 TWO duplicate symbols, linker error.
//! because we define log() in the header Log.h
//duplicate symbol 'log(char const*)' in:
//  CMakeFiles/cpp1720.dir/main_linker.cpp.o
//  CMakeFiles/cpp1720.dir/Log.cpp.o

//duplicate symbol 'log(char const*)' in:
//   CMakeFiles/cpp1720.dir/main_linker.cpp.o
//   CMakeFiles/cpp1720.dir/Log2.cpp.o
//! 6
