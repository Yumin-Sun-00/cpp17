#include <vector>
#include <memory>
#include <array>
#include <string_view>
#include <tuple>
#include <any>
#include <string>
#include <type_traits>
#include <functional>
#include <algorithm>

#include <iostream>
/*
int main() {
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
}
*/

std::tuple<std::string, int> CreatePerson()
{
    return {"Yumin", 30};
}

auto  factory()
{
    return std::make_unique<int>();
}

//! #6 fold expressions
template<typename ... T>
auto add(const T& ... param)
{
    return (param + ...);
}

// class hierarchy
struct SS
{
    double q;
};

struct S : SS
{
    int i ;
    float f;
};

// not copyable
struct A
{
    A(const A& other) = delete;
    A() = default;
};

struct AA
{
    AA(const AA& other) = default;
    AA() = default;
};

int doSomething(int i)
{
    return 5 + i;
}

std::vector<int> makeVec()
{
    return {1,2,3,4};
}


struct B
{
    const int j =  5;
    int doSomething(const int i)
    {
        return j + i;
    }
};

[[nodiscard("You may want to call clear()?")]] bool empty()
{
    return true;
}

std::size_t length(const std::string_view& s)
{
    return s.size();
}

int main()
{
    //! sequence container
    {
        // c++11
        std::vector<std::vector<int>> vec(3);

        vec.emplace_back(3,1); // {1,1,1}
        auto& v = vec.back();
        v.push_back(4); // {1,1,1,4}

        // c++17: emplace_back return a reference to the element just added
        vec.emplace_back(3,1).push_back(4);
    }

    //! nodiscard
    {
        // warning: ignoring return value of function declared with 'nodiscard' attribute: You mat want to call clear()?
        empty();
    }

    //! std::accumulate
    // copy value, fixed in c++20


    //! std::optional, performance
    //! variant
    //! std::any A type safe container to hold any object
    {
        std::vector<std::any> v{5, 3.4, std::string("yumin")};
        std::cout<< v.size()<<"\n";
        std::cout<< std::any_cast<int>(v[0]) << '\n'; // ok
        //std::cout<< std::any_cast<float>(v[0]) << '\n'; // bad any_cast!
        std::cout<< v[1].type().name() << '\n'; // You can ask what is the type

        // you can not put non copyable in to any container!
        //std::vector<std::any> v1{5, 3.4, std::string("yumin"), A()};

        static_assert(std::is_nothrow_move_constructible<AA>::value, "no thorw");
        std::cout<<"size of any "<<sizeof(std::any) << std::endl; //32bytes
        // -> put small object (no throw move constructible) into any will not pay the cost of dynamic allocation.

        // modify element in any contrainer
        {
            // Compiler error: non-const lvalue reference to type int can not bind to temporary of type int
            //int& i = std::any_cast<int>(v[0]);
        }
        int* i = std::any_cast<int>(&v[0]);
        *i = 10;
        std::cout<< std::any_cast<int>(v[0]) << '\n'; // ok
    }
/*
    //! std::invoke....TODO
    {
        std::cout << "invoke: " << std::invoke(&doSomething, 5) <<'\n';

        B b;
        std::cout << b.doSomething(3) << '\n';

        auto fp = &B::doSomething;
        int (B::*fp2)(int) = &B::doSomething;
        std::cout<< (b.*fp)(2) <<'\n';
        std::cout<< (b.*fp2)(1) <<'\n';
    }
*/

    //! aggregate intialization
    {
        // c++11, no way to brace initialize the base class SS::q
        //S s{1, 2.3};
        //c++17: default initialization for struct SS
        S s2{{}, 1, 2.3};
        S s3{{54.8}, 1, 2.3};
    }
    //!
    //! #1 guaranteed copy/move elision
    {
        auto widget = factory(); // created inplace
    }

    //! #2 Beginning 'constexpr' support in stdlib
    // Example: operator[] (std::array), std::max_element

    //! #3 'constexpr' for lambda
    constexpr auto l = [](){};

    //! #4 std::string_view
    {
        constexpr std::string_view name = "Hello";
        // avoid heap allocation
        auto sz = length("asdb;asikdfuheiufdhja;soidfja;sodia;soidja;");
    }


    //! #5 class template argument deduction
    std::array<int,5> data{1,2,3,4,5};
    std::array more_data{1,2,3,4,5};

    //! #6 fold expressions
    {
        add(1,2,3,4,5,6,7);
    }

    //! #7 structured bindings
    {
        auto[name, age] = CreatePerson();
        std::pair<int,int> values{1,2};
        auto [first, second] = values;
    }

    //! #8 switch, if-init expression
    {
        std::pair<int,int> values{1,2};
        if(auto [first, second] = values;
                first > 5)
        {
            std::cout<<"if-init expression....\n";
        }

        auto vec = makeVec();
        if(const auto it = std::find(vec.begin(), vec.end(), 2);
                it != vec.end())
        {
            *it = 3;
        }
        else
        {
            // it exist here too
            //vec.insert(it, 6);
        }

        if(const auto it = std::find(vec.rbegin(), vec.rend(), 3);
                it != vec.rend())
        {
            *it = 4;
        }
        else
        {
            // it exist here too
            //vec.insert(it, 6);
        }
    }

}
