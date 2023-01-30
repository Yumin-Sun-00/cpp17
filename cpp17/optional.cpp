#include <iostream>
#include <fstream>
#include <string>
#include <optional>
using namespace std;

// how to deal with data may or may not be there

std::string read(const std::string& filePath, bool& success)
{
    std::ifstream stream(filePath);


    if(stream)
    {
        std::string result;
        //read
        stream.close();
        success = true;
        return result;
    }
    success = false;
    return "";
}

std::optional<std::string> read(const std::string& filePath)
{
    std::ifstream stream(filePath);

    if(stream)
    {
        std::string result;
        //read
        stream.close();
        return result;
    }
    return {};
}



int main()
{
    bool success = false;
    std::string data = read("data.txt", success); // empty file is also valid
    if(success)
    {

    }
    else
    {
        //...
    }

    // compare to optional...

    std::optional<std::string> data2 = read("data.txt");

    if(data2) // or data.has_value()
    {
        // how to access the value
        std::string& str = *data2;
        data2.value();
        std::cout<<"File read successfully\n";
    }
    else
    {
        std::cout<<"can not read file\n";
    }

    // what if you want some default behavior, if the data not exist
    std::string value = data2.value_or("Not present");
    cout<<value;

    cin.get();
    return 0;
}
