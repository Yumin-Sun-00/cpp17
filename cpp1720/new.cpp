// new is an operator, i.e. you can overload it...later will cover it
// placement new will cover also later
// new returns void*, takes size

#include <iostream>

class E
{
private:
    float m_x;
public:
    E() : m_x(0) {
        std::cout<<"default ctor called...\n";
    }
    E(float x) : m_x(x) {}

    ~E()
    {
        std::cout<< "destroyed..\n";
    }

    const float& getX() const { return m_x; }
};


int main()
{
    std::cout<<"new array..will call default constructor\n";
    E* e = new E[5]; // allocate memeory, continiously 50 entity in a row, default ctor called

    //E* e2 = new E();
    //delete e2;

    std::cout<<"call new will call malloc()..usually. But here is the difference....\n"
               "malloc..will not call constructor, it only allocate\n";
    E* e3 = (E*)malloc(sizeof(E));

    // You should not use malloc to allocate memory in c++

    delete[] e;

    std::cout<<"free will not call destructor..\n";
    free(e3); // for malloc

    std::cin.get();

}
