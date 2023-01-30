#include <iostream>

// template: like macro...
// template: allows you to define a template based on the rules you give, and compiler create it for you

template<typename T>
void Print(T value)
{
    // when is the code created? when you really use it
    // some compilers do not detect the error if you never use the template
    //std::cout<<valu<<std::endl;

    std::cout<<value<<std::endl;
}

// template is evaluated on compile time

template<typename T, int N>
class Array{
public:
    int getSize() const
    {
        return N;
    }

private:

    // array on stack
    T m_Array[N]; //I wish to determine the size on compile time
};

int main()
{
    Print(5.5f);

    Array<int, 5> array;
    std::cout<< array.getSize()<<std::endl;
}
