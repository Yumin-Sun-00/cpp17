#include <vector>
#include <memory>

struct Vertex
{
    float x,y,z;
};


int main()
{
    std::vector<std::shared_ptr<Vertex>> list;
}
