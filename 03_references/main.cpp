#include <iostream>
#include <cstdint>
using namespace std;

int main(void)
{
    uint32_t number = 10;
    //uint32_t &ref;
    uint32_t &ref = number;

    cout << "number = " << number << endl;
    cout << "ref = " << ref << endl;
    cout << "Address of number = " << &number << endl;
    cout << "Address of ref = " << &ref << endl;

    return 0;
}
