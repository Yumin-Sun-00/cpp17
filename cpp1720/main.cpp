#include <iostream>
#include <variant>
#include <string>

using namespace std;


// compare unions and variant:
// variant is type safe
// insead of only storing one data type at once in unions,
// variat is technically a class that contains member variable of all types declared.
// and it uses index to specify which data type is in use to achiece type safe.
// it is roughly requires more memory comparing to unions. Also index requires extra 4 bytes.
// but anyway the largest data type leading the main memory consumtion, so it is toleratable.
// So, unless you really want to implement some low-level things, always use variant
// instead of unions.


int main()
{
    variant<std::string,int> data;

    cout<<sizeof(int)<< endl; //4
    cout<<sizeof(std::string)<< endl; // 24
    cout<<sizeof(data)<< endl; // 32: 4 + 24 + another 4 byte for the index, which is an integer

    data = 2;
    try {
        auto val1 = get<string>(data);
    } catch (bad_variant_access const& ex) {
        cerr << ex.what() << endl;
    }

    data = "hello";
    data = string("hello");

    auto val2 = get<string>(data);

    if(const auto ptr = get_if<int>(&data)) //constexpr
    {
        cout << "data is a int" << endl;
    }
    else
    {
        cout << "data is string" <<endl;
    }

    //You can not do static_assert
    //assert(get_if<int>(&data) && "data is not string type, can not get it"); // crashed

    cout << data.index() << endl; // 0

    cin.get();
    return 0;
}
