
#include <iostream>

class E
{
private:
    float x;
public:
    E() : x(0)
    {
        std::cout<<"default ctor called...\n";
    }

    E(float x)
    {
        // x = x; // this is actually assigning x to x, has nothing to do with the member variable x
        //E* const e = this;
        //E& e = *this;
        this->x = x;
    }

    float getX() const
    {
        //const E* e = this;
        //const E& e = *this;
        return this->x;

        // besides...never delete this inside any member function
        //delete this; access any memeber data after this, you will exploid.
    }

    ~E()
    {
        std::cout<< "destroyed..\n";
    }

    void Print() const
    {
        std::cout<<x<<std::endl;
    }
};


int main()
{

}
