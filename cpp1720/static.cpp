// static inside class/struct
// share memeory across all instances, only one instance of that static variable exists
// same to the static method inside the class


// static outside class/struct
// the linkgage of that symbol you declared is static
// it going to be internal: visible only for that transition unit you have DEFINED in.

/*
one static, the other non-static: ok
the one defined as "static" will take precedence over the other one, meaning that the non-static variable will not be accessible.

two static (same name) in different cpp: ok

two static or non-static (same name) in the same cpp: redfinition, compile error

two non-static (same name) in different cpp: duplicate symbol, linker error
*/
#include <iostream>
int s_var = 5;

void out()
{
    std::cout << "static.cpp " <<s_var<<std::endl;
}
