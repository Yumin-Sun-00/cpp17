
#include <iostream>
#include <string>

// c++ macro
// C++ pre-processor helps us to automate
// during the preprocessing stage, it will replace the text
// it can be written everywhere

#define WAIT std::cin.get() // this is an example for a STUPID macro!!!
//because if WAIT is defined else where, you will just see WAIT in this scope
#define OPEN_CURLY { // this is an example for a STUPID macro!!!

// debug & release
#ifdef PR_DEBUG // I miss visual studio so much....
//#if PR_DEBUG == 1
#define LOG(x) std::cout<<x <<std::endl
#elif defined(PR_RELEASE)
#define LOG(X)
#else
#define LOG(X)
#endif

#if 0
#define PR_DEBUG
#define PR_DEBUG 1

// more example using backslash, make sure no space after the backslash
#define MAIN int main()\
{\
    std::cin.get();\
}
#endif

int main()
OPEN_CURLY
    WAIT;
    LOG("hello");
}

//todo: opengl + macro, memory allocation
