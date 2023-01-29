#include <vector>

const char* stringLiteralLifeTime()
{
    // looks like a temporal, but actually valid for entire life of program
    return "string literals";
}

// make compiler knows it is totally fine to compute it ahead time
constexpr int sum(int n)
{
    return n * (n+1) / 2;
}

struct S
{
    int x,y;
    std::string s;
};

float energy1(float m)
{
    return m * 2993874.0 * 2993874.0;
}

float energy2(float m)
{
    constexpr float SPEED = 2993874.0;
    return m * SPEED * SPEED;
}

const int* max1(const int* a, const int * b)
{
    return *a > *b ? a : b;
}

std::shared_ptr<const int> max2(std::shared_ptr<const int> a, std::shared_ptr<const int> b)
{
    return *a > *b ? a : b;
}

int main()
{


//! using namespace std

//! using std::endl...

//! using index in a for loop if you can avoid to expose the implementation

    //! rewriting algorithm
    {
        const std::vector<int> data = {1,4,8,2,-1,5,0,-9};
        std::size_t firstPosIdx = 0;
        for(std::size_t i = 0; i < data.size(); i++)
        {
            if(data[i] > 0)
            {
                firstPosIdx = i;
                break;
            }
        }
    }

    {
        const std::vector<int> data = {1,4,8,2,-1,5,0,-9};
        const auto isPositive = [](const auto& x) { return x > 0; };
        auto firstPosIt = std::find_if(data.cbegin(), data.cend(), isPositive);
    }


    //! using c array when you could use std::array

    //! use of reinterpret_cast. Almost cast back to the original type is the only allowed use case.

    //! cast away const

    //! Not knowking [] insert new element to std::map....at() vs [], at is const version.

    //! Not knowing string literals lifetime:
    {
        stringLiteralLifeTime();
    }

    //! Not using structured bindings

    //! doing in runtime, when it could be done on compiled time
    {
        const int limit = 1000;
        auto n = sum(limit);
    }

    //! forget virtual on destructor

    //! member variables initialization order not following the declaration order

    //! not knowking default vs value initialiation
    {
        // default initialized
        int x;
        int *y = new int;

        // value initialized
        int z{};
        int* m = new int{};
        int* n = new int();

        delete y,m,n;

        // this is a function declaration!
        int o();

        // default initiaalized
        S s;
        S* s1 = new S;

        // value initialized
        S s2{};
        S* s3 = new S{};
        S* s4 = new S();

        delete s1,s3,s4;
    }

    //! overuse magic number
    {
        energy1();
        energy2();
    }

    //! adding element into a container while looping it


    //! return a move to a local variable
    // compiler could have return value optimization; even it does not have it knows it can move the resource

    //! thinking std::move moves something, It ist just cast to rvalue

    //! evaluation order is not guaranteed!

    //! unnessary heap allocation

    //! raw pointer and exception safe
    // if before delete happens, code throws an exception, the delete will not be executed -> memory leak
    // smart pointer is exception safe

    //! not using make unique or make shared to construct directly, instead using new to construct

    //! Any use of new and delete
    //! TODO

    //! Never use manual resource management

    //! Thinking raw pointers are bad...
    {
        // if your function does not care about the ownership, you can use raw pointer
        //max1(...);
        //max2(...);
    }


    //! retunr a shared_ptr if you are not sure you want to share
    //! Thinking shareed_ptr is thread safe
    //! ignoring compiler warnings
}
