#include <iostream>


// std::move: When you want to convert an existing object to a temporary
// help you do the manuall cast (_Ty&&) more elegant in a template way

// move assignment operator: when you want to move something into the other
// which is already exist.

// move constructor: move during construction

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

    String& operator=(String&& other) noexcept
    {
        printf("Move assigned\n");

        // first delete the current data is bad
        // because you need to consider what if..self assignment happens
        if(this != &other) //todo: i think we should check the data pointer, but not the same object...
        {
            delete[] m_Data;

            m_Size = other.m_Size; // size still get copied
            m_Data = other.m_Data; // take the pointer of the original string

            // take care the other string here, and ...it is important
            other.m_Data = nullptr;
            other.m_Size = 0;
        }

        return *this;
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

int main()
{

    String str = "Hello";
    //String dest = str; // copy assignment

    // move constructor
    //String dest1 = (String&&)str; // cast to temperoray
    //String dest2((String&&)str); // same, but not elegant, and not always work
    String dest3(std::move(str));

    // this is NOT a move assignment
    // because dest4 is a new object that going to be constructed
    // so at the end it still takes the move constructor
    //String dest4 = std::move(str);

    // move assignment only happens, when you want to move one object to an existing object
    String str2 = "World";
    printf("Hello:...");
    dest3.Print();
    printf("World:...");
    str2.Print();

    dest3 = std::move(str2);

    printf("Hello:...");
    dest3.Print();
    printf("World:...");
    str2.Print();
    // dest3 = std::move(dest3); self move assignment
    // now...what if the objects are different, but data is the same?
    return 0;
}
