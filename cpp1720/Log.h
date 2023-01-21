#pragma once
#include <iostream> // used for 4 only

#if 0
//! 1 and 2
void log(const char* message);
//! 1 and 2

//! 3
// if only declared, no definition in header, but define in cpp
// warning: function has internal linkage but is not defined
static void log(const char* message);
//! 3
#endif

//! 4
// if declared and defined in header
static void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 4
