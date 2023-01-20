#include <iostream>

// static inside class/struct
// share memeory across all instances, only one instance of that static variable exists
// same to the static method inside the class


// static outside class/struct
// the linkgage of that symbol you declared is static
// it going to be internal: visible only for that transition unit you have defined in.
int s_var = 10;
int main()
{
    std::cout<<s_var;
    std::cin.get();
    return 0;
}

// one duplicate symbol
// linker command failed
