

#include <iostream>
#include <vector>

struct Vertex
{
    float x,y,z;
    Vertex(float x,float y,float z)
        : x(x),y(y),z(z)
    {
        //std::cout<<"constructed\n";
    }

    Vertex(const Vertex& other)
        : x(other.x),y(other.y),z(other.z)
    {
        std::cout<<"copied\n";
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ","<< vertex.y <<","<<vertex.z<<std::endl;
    return stream;
}

int main()
{
    //stack allocated or heap allocated?
    // create on stack:
    // good: same cache line
    // bad:
    // when you resize the vector, you need to copy all the data
    // allocate on heap: when you resize, we just copy the address, data will not moved
    std::vector<Vertex> vStack;
    std::vector<Vertex*> vHeap;

    // you will copy 6 times!!!
    vStack.push_back(Vertex(1,2,3));
    vStack.push_back(Vertex(4,5,6));
    vStack.push_back(Vertex(7,8,9));

    // 1. we construct vertex in the frame of main
    // 2. copy the vertex into the vector
    // 3. we resized the vector twice, therefore you have 6 copies


    std::cout<<"after reserve....\n";

    // if our environment know you will have 3 vertex, then it will no need to resize the vector.
    std::vector<Vertex> vertices;
    vertices.reserve(3); // no construction, just reserve the memory

    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6));
    vertices.push_back(Vertex(7,8,9));


    std::cout<<"after emplace back....\n";

    // if our environment know you will have 3 vertex, then it will no need to resize the vector.
    std::vector<Vertex> vec;
    vec.reserve(3); // no construction, just reserve the memory

    // create vertex in the place of vector we allocated
    vec.emplace_back(1,2,3);
    vec.emplace_back(4,5,6);
    vec.emplace_back(7,8,9);


    std::cin.get();
}
