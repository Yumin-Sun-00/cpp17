#include <iostream>

class Entity
{
private:
    std::string m_Name;
    mutable int m_counter = 0; // allow const method to change members
public:
    const std::string& getName() const
    {
        m_counter++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.getName();

    int x = 8;
    auto f = [=]() mutable // pass by value, can be changed
    {
        x++; // without mutable: cannot assign to a var captured by copy in a non-mutable lambda
        std::cout<<x<<std::endl;
    };

    f();

    std::cin.get();
}
