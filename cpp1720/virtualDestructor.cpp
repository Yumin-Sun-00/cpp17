#include <iostream>
class Base
{
public:
    Base()
    {
        std::cout<<"Base constructed\n";

    }
    // without virtual
    virtual ~Base()
    {

        std::cout<<"Base destructed\n";
    }

};


class Derived : public Base
{
public:

    Derived()
    {
        m_Array = new int[5];
        std::cout<<"Derived constructed\n";
    }

    ~Derived()
    {
        delete[] m_Array;
        std::cout<<"Derived destructed\n";
    }


private:
    int* m_Array;
};

int main()
{
        // ok
        Base* base = new Base;
        delete base;
        std::cout<<"-----------------------\n";
        //ok
        Derived* derived = new Derived;
        delete derived;
        std::cout<<"-----------------------\n";
        // not ok: no virtual destructor
        Base* poly = new Derived;
        delete poly;

}
