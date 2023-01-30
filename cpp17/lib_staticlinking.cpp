// I hate package manager...

//#include "Dependencies/glfw/include/GLFW/glfw3.h"
//#include <GLFW/glfw3.h>
// if it is not compiled within this solution, it is totally extertnal, I use <>

// instead of include the whole header, we can also just declare the function we actually used
// linker will find for us the definition
extern "C" int glfwInit();

// because C/C++ name mangling, use extern "C" means the C version should be ignored
// otherwise this will still results in linker error
//int glfwInit();

// if you keep both declaration available, the C version is ignored, because extern "C" let it be ignored.

#include <iostream>

int main()
{
    int a = glfwInit(); // you get linker error, if you have not linked your actual library
    std::cout<<a<<std::endl; // should be 1
    std::cin.get();
}
