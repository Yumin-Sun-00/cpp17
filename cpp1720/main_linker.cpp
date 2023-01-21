// recap: compiler
// source file -> object file
// 1. preprocessor statement evaluation
// 2. build abstract syntax tree
//          ...constant data, instructions..
// 3. machine code generation

// Linker jobs:
// find where each symbol is, and link them together
// each file is compiled a seperate object file as a translation unit
// they have no relationship to each other

// about error
// C2143: syntax error. C for compiler
// LNK1561: entry point must be defined. LNK for linker

// about entry point
// If we do not have main() function, no entry point is defined
// but compiler does not care this
// if you just compile it, it will not complain, and you will have the obj file generated.
// however if you build it, linker will work, and it will fail.

// configuration: if you select type as application (.exe), every exe should contain an entry point.
// you can also use the linker settings -> entry point -> customized
// i.e. An entry point does not necessary to be main() function.



#if 0
//! 1 multiple declarations is ok
#include <iostream>

void log(const char* message);
void log(const char* message);

void log(const char* message)
{
    std::cout<<message<<std::endl;
    return;
}

int main()
{
    log("hello");
}
//! 1


//! 2 undefined symbol
#include <iostream>

void log(const char* message);

int main()
{
    log("hello");
}
//! 2

//! 3: log() not used, no linker error
#include <iostream>

void log(const char* message);

int main()
{
}
//! 3

//! 4: log() not defined and not used, no linker error, because linker does not need to resolve the symbol.
#include <iostream>

void log(const char* message);

int add(int a, int b)
{
    //log("add");
    return a+b;
}

int main()
{
}
//! 4

//! 5: log() not defined, add() not used, but still get linker error, because we could use add somewhere else.
#include <iostream>

void log(const char* message);

int add(int a, int b)
{
    log("add");
    return a+b;
}

int main()
{
}
//! 5


//! 5: make add static, so it is internal for this translation unit, then we do not get linker error
#include <iostream>

void log(const char* message);

static int add(int a, int b)
{
    log("add");
    return a+b;
}

int main()
{
}
//! 5
#endif

#include "Log.h"

static int add(int a, int b)
{
    log("add");
    return a+b;
}

int main()
{
    add(2,3);
}
//! 5
