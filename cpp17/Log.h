#pragma once
#include <iostream> // used for 4 only

#if 0
//! 1 and 2: test function signature with static
void log(const char* message);
//! 1 and 2

//! 3
// if declared in header, defined in cpp
// it makes no sense to do so, because static is only visible at where it is defined.
static void log(const char* message);
//! 3


//! 4
// if static declared and defined in header: it will be copied to all files include it, and they are all visible only internally
static void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//! 4


//! 5 add Log2.h, Log2.cpp
void log(const char* message);
//! 5

#endif
//!6 move definition in header, include in Log2.h
void log(const char* message)
{
    std::cout<<message<<std::endl;
}
//!6
