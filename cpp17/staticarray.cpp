#include <iostream>
#include <array>
// static array: array does not grow

// john Jralor
//john causey

// alexander D.
void PrintArray(int* array, unsigned int size)
{
    //for()
}

// we have to pass the size 5 also.....
std::ostream& operator<<(std::ostream& stream, const std::array<int,5>& data)
{
    stream<<data[0]<<std::endl;
    return stream;
}

// to get rid off the size....
template<class _Ty, size_t _Size>
void PrintArray(const std::array<_Ty,_Size>& data)
{
    for(auto& d : data)
    {
        std::cout<<d <<",";
    }
}

int main()
{
    std::array<int,5> data;
    // access
    data[0] = 2;
    data[1] = 5;
    data[2] = 7;
    data[3] = 6;
    data[4] = 1;

    // std array and normal array allocated on stack
    // std vector on heap
    // normal array, no boundary check
    // std array has boundary check, but only for debug mode, so in release code, it is just normal array


    PrintArray(data);

    std::cin.get();
}
