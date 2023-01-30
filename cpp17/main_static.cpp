#include <iostream>

// static inside class/struct
// share memeory across all instances, only one instance of that static variable exists
// same to the static method inside the class


// static outside class/struct
// the linkgage of that symbol you declared is static
// it going to be internal: visible only for that transition unit you have defined in.

static int s_var = 100;
void out();
int main()
{
    std::cout<<"main.cpp "<< s_var <<std::endl;
    out();
    std::cin.get();
    return 0;
}
