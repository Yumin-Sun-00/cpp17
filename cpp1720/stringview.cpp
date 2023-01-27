#include <vector>
#include <string>
#include <iostream>

// c++17: string view. A window.

// overwrite new to debug
void *operator new(size_t size)
{
    static uint32_t s_Allocations = 0;
    s_Allocations++;
    std::cout<<"Nr."<<s_Allocations<<" allocation" << ", current allocate "<<size<<" bytes\n";
    return malloc(size);
}

//#define STRING
#ifdef STRING
void Print(const std::string& str)
{
    std::cout << str << std::endl;
}
#else
void Print(std::string_view strView)
{
    std::cout << strView << std::endl;
}
void Print(const char* cstr)
{
    std::cout << cstr << std::endl;
}
#endif

int main()
{
    // 2. How many heap allocations happen?
    std::cout<<"This heap allocate....\n";
    std::string str("YuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYumin");

#ifdef STRING

    std::cout<<"This ALSO heap allocate...\n";
    Print("YuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYumin");

    std::cout<<"substr: This ALSO heap allocate...\n";
    std::string first = str.substr(0,23); // creating a new string
    std::string last = str.substr(24, 23); // creating a new string
#else
    std::cout<<"string view...\n";
    std::string_view first(str.c_str(), 23); // no new string created
    std::string_view last(str.c_str()+23, 23); // no new string created
    Print(first);
    Print(last);

    std::cout<<"let us try to avoid all allocations....\n";

    //making std::string to c string: const char*
    const char* cstr("YuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYuminYumin");
    std::string_view first2(cstr, 23); // no new string created
    std::string_view last2(cstr+23, 23); // no new string created
    Print(first2);
    Print(last2);

#endif
}
