#include <iostream>

// static inside class/struct
// share memeory across all instances, only one instance of that static variable exists
// same to the static method inside the class


// static outside class/struct
// the linkgage of that symbol you declared is static
// it going to be internal: visible only for that transition unit you have defined in.


// duplicate symbol, linker command failed
// because in main.cpp we also define s_var
// and here s_var in this cpp is not static, so it is visible to other translation unit(main.cpp)
//int s_var = 5;

// but if you define it as static, everything works well
static int s_var = 5;
