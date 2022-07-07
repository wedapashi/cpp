#include <iostream>
#include <cstdint>

using namespace std;

class foo
{
public:
    static uint32_t u32Count;
    uint32_t read(void)
    {
        cout << "In read.." << endl;
        // Some code
        return 0;
    }
    uint32_t write(void);
};
uint32_t foo::write(void)
{
    cout << "In write.." << endl;
    // Some code
    return 0;
}

uint32_t foo::u32Count = 50;
uint32_t u32Count = 100;

int main(void)
{
    foo alloc;
    uint32_t u32Count = 10;
    
    cout << "u32Count (local) = " << u32Count << endl;
    cout << "u32Count (global) = " << ::u32Count << endl;
    cout << "u32Count (alloc) = " << foo::u32Count << endl;

    alloc.read();
    alloc.write();
    
    return 0;
}
