#include <iostream>
using namespace std;
int getValue()
{
    return 0; // return a temporary, rvalue
}

// rvalue reference (todo)
int& getValueR()
{
    static int value = 10;
    return value;
}

void setValue(int v)
{

}


void setValueR(int& v)
{
//you can not take a lvalue reference from a rvalue
}

void setValueCR(const int& v)
{
//can accept both lvalue and rvalue now
}

void printName(std::string& name)
{
    // accept lvalue only
    cout<<name<<endl;
}

void printNameC(const std::string& name)
{
    // accept lvalue and rvalue
    cout<<name<<endl;
}
void printNameRR(std::string&& name)
{
    // rvalue reference can not be bound to lvalue
    // and EVEN printNameC has the same name as printNameRR
    // the && version will still be chosen

    // so this is nice, because we have a way to detect temporary object
    // and do somethign with them

    // how is this useful?
    // move semantics!
    cout<<name<<endl;
}
int main()
{
    int i = 10;
    // i has location, 10 is a value, has no location
    int a = i;

    int j = getValue(); // getValue() returns rvalue

    //getValue() = 5; you can not assign to a rvalue
    getValueR() = 5; // it is fine

    setValue(i);
    setValue(10);

    // you can not take a lvalue reference from a rvalue
    //setValueR(10); // expect a lvalue
    //int& b = 10;// you can not do this
    // but this works
    const int& c = 10; // compiler will do this for you: int tmp = 10; const int& c = tmp;

    std::string fn = "Yumin"; // literals are rvalue
    std::string ln = "Sun";
    std::string fullname = fn + ln; //fn+ln is also rvalue, because it is temporary
    printName(fullname);
    //printName(fn + ln); // will not work

    // So we have a way to detect whether something is rvalue, look function printName
    // do we have a way that the function only allow temporary object?
    printNameRR(fn+ln);

    // why it is good, if we know something is temporary?
    // because we know it is gonna disappear, we can steal the resources


    return 0;
}
