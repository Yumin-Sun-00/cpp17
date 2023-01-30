#include <iostream>
#include <vector>
#include <string>

//stack: predefined size, usually2 2MB
//heap: also predefined, but it can grow or shrink as our application goes on
// actually location of them two, all inside our RAM, stack is not located in cache or somewhere cpu.
struct Vector3
{
    float x,y,z;
};

int main()
{
    {
        int sval = 5; // stack allocation

        int array[2];
        array[0] = 1;
        array[1] = 2;

        Vector3 vec();
    }

    // when the scope ends, all objects allocated on the stack, all popped off
    // that is the reason we do not need to take care deallocation

    int* hval = new int(5); // heap allocation
    delete hval;

    int* harray = new int[2];
    harray[0] = 1;
    harray[1] = 2;
    delete[] harray;

    Vector3* hvector = new Vector3();
    delete hvector;


    // new will call malloc
    // which will call underlying OS, who will allocate memory for you
    // there is a free list that tracks which block is free
    // it will go through the free list, and you will get the pointer back to a block that is enough for your request
    // and it will update the free list (bookkeep)

    // if OS gives you a memory block, and you want to ask more, then it is expensive.

    // objects are close together is not really an argument for efficiency, because few cache misses is not a problem
    // on the other hand, stack memory is hot, because it keep pushing and popping, so it is anyway slow down.

    // the big difference is the memory allocation.
    // allocation on stack is one cpu instruction
    // you can open the assembly generators to see what is the difference...

    // if you pre-allocate 4GB for the program, then it will be the same as a stack
    std::cin.get();
    return 0;
}
