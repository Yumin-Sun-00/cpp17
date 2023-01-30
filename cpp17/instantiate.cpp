#include <iostream>

// some reasons you want to allocate an object on the heap
// 1. automatic object has scope, it will be destroyed automatically, but you still hope to access that object
// 2. object is too large


class E
{
private:
    float m_x;
public:
    E() : m_x(0) {}
    E(float x) : m_x(x) {}

    const float& getX() const { return m_x; }
};


int main()
{
    E e;
    E e2(3); // preferred: most efficient way to instantiate object

    E* pe;
    {
        E entity(5); // allocate on the stack, automatic object
        pe = &entity; // pe points to an oject m_x = 5
    }
    // pe points to the same address, but it is gone.

    {
        E* entity = new E(5); // allocate on the heap
        pe = entity;
    }
    // the entity is still alive
    delete pe;
    std::cin.get();
}
