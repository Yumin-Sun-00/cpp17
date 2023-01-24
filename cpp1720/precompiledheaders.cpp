// Say we have a main.cpp file that only include vector
// so if it is not pre-compiled, then.. this is what will happen:

// as usual, preprocessor copy paste header files into this translation unit
// and of course, if there are includes inside vector, that parts are also copied.
// at the end, we have out main.cpp source code

// after the preprocessing is done, we compile everything.

// Here is the problem:
// 1. if the includes parts are already compiled, I do not need to compiled them again
// 2. I will only change the code written by me, i.e. the main.cpp source code
//    The includes parts are not changed, they do not need to be re-compiled.
// 3. Very likely, vector is included at many many many places.


// So... your compile time will be much longer, than it could be.
// ----> pre-compiled headers! binary format.

// When not to do it, or disadvantages:
// 1. you are working on these headers.
// 2. It hides what is being used (dependencies): modularity, code reuse

// How to make a precompiled header?
// 1. pch.h
// 2. gcc: simple, just compile pch.h
// 2. Visual Studio:  pch.cpp; right click on pch.cpp -> properties -> C/C++ -> precompiled headers -> Create
// 3. on the project -> properties -> C/C++ -> precompiled headers -> Use; File -> pch.h
#include "pch.h"
int main()
{


}
