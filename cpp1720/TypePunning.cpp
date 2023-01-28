
#include <iostream>

struct Entity
{
    int x, y;

    int* GetPosition()
    {
        // it is terrible and slow
        int* array = new int[2];
        return array;
    }

    int* GetPositionFaster()
    {
        // no copy, no memory allocation
        // you can read & write
        return &x;
    }
};

int main()
{
    std::cout<<"type punning: int -> double\n";
    int a = 5;

    // undefined behaviour: reinterprate memory block for a from int to double
    double tpA = *(double*)&a;


    std::cout<<tpA<<std::endl;

    std::cout<<"type punning: struct size: " << sizeof(Entity)<<"\n";

    Entity e = {5,8};

    int* position = (int*)&e;
    std::cout<<position[0]<<","<<position[1] <<std::endl;

    int y = *(int*)((char*)&e + 4);
    std::cout<<y<<std::endl;


    int* pos = e.GetPosition();

    // I can also change it
    pos[0] = 2;


    // you can also use reinterprate_cast to do the same thing.
}
