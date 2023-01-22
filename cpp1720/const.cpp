#include <iostream>

// const (outside class):

// 1. must be initialized
// 2. may only used operations that cannot change the object
// 3. by default: const objects are local to a file.
// Otherwise, we could result in multiple definitions, if their name is the same.
// So when we define a const with the same name in multiple files,
// it is as if we had written definitions for separate variables in each file.

// but sometimes we have a const that shared across multiple files, but whose initialier is not a constant expression
// in this case, we don't want compiler to generate a separate variable in each file.
// Instead, we want the const to behave like other nonconst
// we want to define the const in one file, and declare it in the other files that use that object

// 4. To define a single instance of a const, we use extern on both definition and declaration(s).
// assume fcn() is a non-constant expression
int fcn(int a) { return a;}
extern const int bufSize = fcn(10);
extern const int bufSize; //signifies that bufSize is not local to this file and its definition will occur elsewhere.

// 5. a reference to const may refer to an object that is not const
// 6. a pointer to const mat point to an oject that is not const

// 7. a const initialized from constant expression is also a constant expression.
// 8. var declares as constexpr are implicitly const and must be initialized by constant expression

// 9.1 auto: ignores top-level consts
// 9.2 reference to auto deduced type: top level consts are not ignored.
const int ci = 5; auto i = ci; // i is int, const qualifier is dropped
auto& rci = ci; // rci is a const int&
//auto& h = 42; // error: we can not bind a reference to a literal
const auto& ch = 42; // ok, w can bind a const ref to a literal

// 10. const is just a promise, you can break it

// 11. const + type alias: when we use typealias in a declaration, the base type of the declaration is that typealis
typedef char* pstring; //pstring is a pointer to char
const pstring cstr = 0; // cstr is a consant pointer to char
const pstring *ps; // ps is a pointer to const pointer to char

// 12. const_cast only changes LOW LEVEL const!!!!!!
// 13. you can not change constness through other named casts.
// 14. old style cast has the same bevahviour as static_cast, const_cast, reinterpret_cast
// if static_cast or const_cast would be legal, the old style cast does the same conversion as the respective named cast
// otherwise, it would be reinterpret_cast

int main()
{
    const int MAX_AGE = 90;

    int* a = new int;
    // int const *a : a pointer point to const int
    // const int *a:  the same
    // int* const a: a const pointer point to int

    *a = 2;
    //a = &MAX_AGE; // compile error: discards qualifiers

    int*b = a; // for free memory

    // bypass
    a = (int*)&MAX_AGE;
    *a =5; // undefined behaviour
    delete b;

    std::cout<< *a <<std::endl;
    std::cin.get();
}


class E
{
    int m_x, m_y;
    mutable int var = 0;
public:

    int getX() const
    {
        var++;
        return m_x;
    }

    int getX()
    {
        return m_x;
    }

    void setX(int x)
    {
        m_x = x;
    }
};
