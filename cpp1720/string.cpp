#include <iostream>
#include <string>

int main()
{
    // Immutable, fix allocated, you can not extend that memory, you can not shrink
    // it is NOT allocated on heap.
    // You do NOT do delete.
    // NULL terminated automatically
    const char* name = "Yumin";

    // Warning: ISO C++11 does not allow conversion from string literal to char*
    char* first = "Yumin";

    // So ...do not declare as non-const!

    // This will cause CRASH on my macos, but for other machine, and maybe elder standards, this could work.
    //first[2] = 'a';


    // char array
    // manually, then you need CARE the NULL
    // "" double quotes, by default it is a char*
    char lastNoNull[3] = {'S','u','n'};
    char lastWithNull[4] = {'S','u','n', 0}; // or '\0'

    std::cout<<name<<std::endl;
    std::cout<<lastNoNull<<std::endl; // print till meet 0
    std::cout<<lastWithNull<<std::endl;

    std::cout<<"basic_string..."<<std::endl;

    // basic_string -> std::string is template based on char type
    std::string yumin("yumin");
    std::cout<<yumin<<std::endl;

    // append with operator +
    //const char* + const char*   -> NOT OK!
    //std::string yumin2 = "yumin" + "hello";
    // You need to make at least one part as a std::string

    std::cin.get();

    return 0;
}
