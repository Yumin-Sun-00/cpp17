#include <string>
#include <iostream>
using namespace std;


// expression reading order: inside out, right to left


int main()
{
    // operation on array is treat as pointer the first element
    string nums[] = {"one","two","three"};
    string* p = &nums[0];
    // is equivalent to
    string* p2 = nums;

    // operation on array is treat as pointer: auto
    int ia[] = {0,1,2,3};
    auto ia2(ia);

    // but when typeid applied to array, the conversion to pointer is not done.
    cout<< "typeid of array ia is:" << typeid(ia).name() << "\n"
        << "typeid of auto ia2 is:" << typeid(ia2).name() << "\n"
        <<endl;

    // About typeid:
    // if the operand is not a class type or is a class without virtual functions:
    // then typeid operator indicates the static type of the operand.(compile type)
    // when operand is lvalue of a class type has at least one virtual function, then the type is evaluated at run time.

    // So, typeid of pointer returns the static, compile time type of the pointer.
    // typeid of *p is complicated:
    // if p is a pointer to a type that does not have virtual functions, then p does not need to be a valid pointer
    // otherwise, *p is evaluated at run time, so p must be a valid pointer.
    // if p is nullptr, throw bad_typeid exception

    // Type alias: myType is an array of 3 ints
    typedef int myType[3];
    // equivalent declarations
    using arrT = int[3];

    // array can not be copied or assgined
    // therefore a function can not return an array, but we can return a pointer to array
    arrT* ioo(int i);

    // To define a func return pointer to array without using type alias:
    // we must remember that the dimension of an array follows the name being defined
    int arr[10];
    int *pArr[10];
    int (*p2Arr)[10] = &arr;
    // Type (*function(parameter_list)) [dimension]
    int (*func(int i)) [10]; // func is a function takes 1 integer argument and return a pointer to 10 ints
    // func(int): we can call this func with an int arg
    // (*func(int)): we can dereference the result of that call
    // (*func(int)) [10]: dereferencing the result of a call to func yields an array of size ten
    // int (*func(int)) [10]: the element type in that array is int.

    // another way: use trailing
    auto func2(int i) -> int(*)[10];

    // using new[] to allocate array will not return an object with an array type, it is the pointer of the element type of the array
    int* ptrToFirstElement = new int[3]; // not array type
    int* ptrToFirstElement2 = new myType; // not array type
    cout<< "typeid of array ptrToFirstElement is:" << typeid(ptrToFirstElement).name() << "\n"
        << "typeid of auto ptrToFirstElement2 is:" << typeid(ptrToFirstElement2).name() << "\n"
        <<endl;

    delete[] ptrToFirstElement;
    delete[] ptrToFirstElement2;

    // remember: a dynamic array does not have an array type!
    // you can not have iterator begin and end
    // you can not have range for loop on it
    // because these functions use dimension

    myType** val; // decalre pointer to pointer to array of 3 ints


    //The C++ rule for the return type and value of new T is:
    // If T is not an array type, the return type is T *, and the returned value is a pointer to the dynamically allocated object of type T.
    // If T is an array of type U, the return type is U *, and the returned value is a pointer to the first element (whose type is U) of the dynamically allocated array of type T.
    myType** tmp = new myType*;

    // new (int[3])*; // not allowed
    // new int[3]*;   // not allowed
    // new int(*)[3]; // not allowed
    // new (int*)[3]; // not allowed
    auto omg = new (int(*)[3]);

    // funciton pointer syntax
    void (*goo)(int); // goo is a pointer points to a function, which take int as the argument and return void
    void* (*hoo)(int *); // ...returns void*
    void (*goo2)();
    void (*goo3)(int,double,void*, int);
    // another mind fuck
    int (*(*foo[2])())[3];    // declaration of an array of 2 pointers to functions
                              // returning pointer to array of 3 int
    cout << "void (*goo)(int) type id " <<typeid(goo).name()<<endl;
    cout << "void (*goo2)() type id " <<typeid(goo2).name()<<endl;
    cout << "void (*goo3)(int,double,void*, int) type id " <<typeid(goo3).name()<<endl;
    cout << "void* (*hoo)(int *) type id " <<typeid(hoo).name()<<endl;
    cout << "int (*(*foo[2])())[3] type id " <<typeid(foo).name()<<endl;

    new (int (*(*[2])())[3]); // type-id is "int (*(*[2])())[3]"

    // new int*[3] allocates an array of 3 pointers of int type, return a pointer to the first element, it should be int**
    auto tmp4 = new int*[3];
    int** tmp5 = new int*[3];
    cout<< "typeid of myType** tmp = new myType*:" << typeid(tmp).name() << "\n"
        << "typeid of auto tmp4 = new int*[3]:" << typeid(tmp4).name() << "\n"
        << "typeid of int** tmp5 = new int*[3]:" << typeid(tmp5).name() << "\n"
        << "typeid of auto omg = new (int(*)[3]):" << typeid(omg).name() << "\n"
        <<endl;

    delete tmp;
    delete[] tmp4;
    delete[] tmp5;
    delete omg;

    return 0;
}
