#include <vector>
#include <string>
#include <iostream>

// overwrite new to debug
void *operator new(size_t size)
{
    static uint32_t s_Allocations = 0;
    s_Allocations++;
    std::cout<<"Nr."<<s_Allocations<<" allocation" << ", current allocate "<<size<<" bytes\n";
    return malloc(size);
}

// small string optimization
// std::string has a small buffer to save heap allocation
// buffer size varies across implementations.
// clang++: Allows up to 22 bytes with no allocation
// visual studio 19: 15 characters for release mode. If it is debug mode, you still get heap allocation for small string.
// So...if you have something less than 16 chars, no need of using const char* or something more complicated...

// std::string: 3 fields
// pointer 8 bytes on 64 bits machine
// size of str: 8 bytes
// size of allocated memory: 8 bytes

int main()
{
    // 1. When happens small string optimization?

    std::cout<<"pointer size:" << sizeof(void*)<<std::endl; // 8bytes
    std::cout<<"size_t size:" << sizeof(size_t)<<std::endl; // 8bytes
    std::cout<<"empty std::string size:" << sizeof(std::string)<<std::endl; // 24 bytes: 8+8+8bytes

    std::cout<<"clang++: 22 chars creation....\n";
    std::string strStack("YuminYuminYuminYuminYu"); // 22chars, stack allocated

    std::cout<<"clang++: 23 chars creation....\n";
    std::string strHeap("YuminYuminYuminYuminYum"); //23 chars, heap allocated, 32byte

    std::cout<<"strStack size:" << sizeof(strStack)<<std::endl; // 24 bytes
    std::cout<<"strHeap size:" << sizeof(strHeap)<<std::endl; // 24 bytes

    std::cout<<"create vector of 5 short string\n";
    std::vector<std::string> vec(5, "Yumin Sun");
}
