#include <iostream>

using namespace std;

// new and malloc is used to allocate on heap
// dynamically allocated objects are default initialized
// built in or compund type have undefined value
// objects of class type are initialized by their default ctor

// Other initializations:
// direct initialization p84
// list initialization
// value initialization p98
// for class types that define their own ctors p262
// requesting value initialization is of no conseqquence, it will be default initialized
// a value-initialized object of built int type has a well defined value, but a default-initialized object does not
int* pi1 = new int; // default
int* pi2 = new int(); // value initialized

int main()
{
    // new is c++ only
    // delete is c++ only
    // delete call the class dstor
    // new call the constructor of the class
    int* i = new int;
    delete i;

    // malloc is a c lib function, but can be used in c++
    // free is a c lib function, but can be used in c++
    // free() frees the memory, but does not call the class dstor
    // malloc does not call the ctor
    // malloc return void*, you need to cast to the type you want to point to
    void* p = malloc(sizeof(int));
    free(p);

    std::cin.get();
    return 0;
}
