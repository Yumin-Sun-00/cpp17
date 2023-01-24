#include <iostream>
//#include <string>
class String{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(const char* string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }

    // simulate the c++ shallow copy
    /*
    String(const String& other) : m_buffer(other.m_buffer), m_size(other.m_buffer)
    {
        // a more exiting way to do this
        //memcpy(this, &other, sizeof(String));
    }
    */

    // = delete : prevent you from copying

    // deep copy
    String(const String& other) : m_size(other.m_buffer)
    {
        m_buffer = new char[other.m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);
    }

    ~String()
    {
        delete[] m_buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};


std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buffer; // m_buffer is a private member
    return stream;
}

int main()
{
    String string = "yumin";
    String second = string; // without copy ctor, it is a shallow copy
    second[2] = 'a'; // both would be overwritten, because we only copy the address
    std::cout<<string<< std::endl;
    std::cout<<second<< std::endl;
    std::cin.get();
    // and delete will be execute twice!
}
