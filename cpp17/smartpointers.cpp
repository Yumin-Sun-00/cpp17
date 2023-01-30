
#include <iostream>
#include <memory>

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

    void Print() const
    {
        std::cout<<m_x<<std::endl;
    }
};


int main()
{

    {
        std::unique_ptr<E> e(new E());

        // exception safety without new
        std::unique_ptr<E> e2 = std::make_unique<E>();
        e->getX();

        // unique ptr copy costructor is deleted


        std::shared_ptr<E> e3 = std::make_shared<E>();
        // make shared pack two things together:
        // allocate memory and construct for storing reference count, the control block..
        // construct the object
        // avoid using new, you will be faster
    }

    {

        std::shared_ptr<E> e0;
        {

            std::shared_ptr<E> shared = std::make_shared<E>();
            e0 = shared; // reference count 2
        }
        // reference count 1
    }
    // reference count 0, destroyed

    {
        std::weak_ptr<E> weak;
        {
            std::shared_ptr<E> shared = std::make_shared<E>();
            weak = shared; // reference count 1
        }
        // reference count 0, destroyed
    }

    std::cin.get();

}
