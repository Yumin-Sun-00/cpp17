#include <iostream>
//#include <span> //c++20
#include <string>
//#include <gsl/>
using namespace std;

// according to the Core Guidlines regarding the statically type safe
// problem areas are: unions, casts, array decay, range errors, narrowing conversions
// Alternatives for them:
// unions -> variant c++17
// casts -> min their use, templates can help
// array decay, range error -> span (gsl)
// narrowing conversions -> min their use and use narrow or narrow_cast from GSL


/* Differences between gsl::span and std::span
The only difference between gsl::span and std::span is that gsl::span strictly enforces runtime bounds checking.
Any violations of the bounds check results in termination of the program.

Use gsl::span if:
1. you want to guarantee bounds safety in your project.
2. your project uses C++14 or C++17 , std::span is C++20.

Use std::span if:
your project is C++20 and you need the performance offered by std::span.
*/


int main()
{
//f(T*, int) interfaces vs. f(span<T>) interfaces
    cin.get();
    return 0;
}
