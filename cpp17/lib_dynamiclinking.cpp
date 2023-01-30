// dynamic linking happens on runtime

// static linking happens on compile time
// when you compile a static libray, you then link it into either
// an exe/application/dynamic library.
// You just take the contents of that static library and you put it into black with the rest of the binary
// that is actually in your exe or dynamic library
// Good: optimization, performances

#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
    int a = glfwInit();
    std::cout<<a<<std::endl;
    std::cin.get();
}


// If you use lib + dll，you don't need __declspec(dllimport)
// because all the functions or variables you want to import have defined in lib as pointer;

// but if you use LoadLibary API to import dll,
// with __declspec(dllimport) you can tell the compiler which function or variable you want to import,
// it will reduce the import time
