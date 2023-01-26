#include <iostream>

// c++11, rvalue reference and move semantics
// Motivation: avoid copy when I want to move the resource owner.
// Many times when I pass an object to a function, which will take over
// the ownership of the object, there was no choice but to copy it from the current stack frame
// which is not ideal, because I do need it here, but...there....
// The same when I want to return an object created from a function. (ignore the return value optimization....)
// Of course, when it is just few integers, that is not a bog deal to copy
// but when you have data allocated on heap like vector, string...
// You need to create a new heap allocation. that is not good at all.

class String
{
public:
    String() = default;
    String(const char* string)
    {
        printf("created\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size + 1];
        memcpy(m_Data, string, m_Size + 1);
    }

    ~String()
    {
        for(uint32_t i = 0 ; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("...destroyed\n"); // to copy or move a temp, we have to destroy it once it is finished
        delete[] m_Data;
    }

    String(const String& other)
    {
        printf("copied\n");
        m_Size = other.m_Size;
        m_Data = new char[other.m_Size + 1]; // to copy, we have to allocate on the heap
        memcpy(m_Data, other.m_Data, other.m_Size + 1);
    }


    String(String&& other) noexcept
    {
        printf("Moved\n");
        m_Size = other.m_Size; // size still get copied
        m_Data = other.m_Data; // take the pointer of the original string

        // take care the other string here, and ...it is important
        other.m_Data = nullptr;
        other.m_Size = 0;

        // because when the other is about to destroy, and it still own the resource by having the pointer
        // the destrcutor will destroy the data
    }

    void Print() const
    {
        for(uint32_t i = 0 ; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
private:
    uint32_t m_Size;
    char* m_Data;
};


class Entity
{
public:
    Entity(const String& name) : m_Name(name) // copy
    {

    }

    Entity(String&& name) // This is still a copy: m_Name(name)
        : m_Name((String&&)name) // or std::move(name)... cover it later....
    {

    }

    void PrintName() const
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{

    // created
    // copied      <- PROBLEM
    // yumin
    Entity e(String("yumin"));
    e.PrintName();


    printf("implicit class type case\n");

    Entity e2("xu"); // still a copy


    return 0;
}
