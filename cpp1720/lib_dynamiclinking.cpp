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
