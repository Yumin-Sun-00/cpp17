#include <iostream>

#include "Log.h"

#if 0
//! 1
// trivial case: if header does not declare static
void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 1

//! 2
// if header declare non-static
// static declaration of log follows non-static declaration
static void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 2

//! 3
// if header declares static, defined in cpp, then that declaration will be included everwhere
// however the definition is only local for the place it is defined
static void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 3

//! 4
// if header declares and defines as static, then this definition will be included in every translation unit(if include)
// but they are all internal linkage to that translation unit
//! 4


//! 5 add Log2.h, Log2.cpp
//! linker error: duplicate symbol
void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 5
#endif

//!6 move definition to header
