#include <iostream>
using namespace std;

class interface
{
private:
    uint8_t port;
    uint8_t pin;
    uint8_t dir;
    uint8_t pinFunction;
public:
    interface()
    {
        port = pin = dir = pinFunction = {0};
    }
    void configure(uint8_t Port, uint8_t Pin, uint8_t Direction, uint8_t PinFunction)
    {
        port = Port;
        pin = Pin;
        dir = Direction;
        pinFunction = PinFunction;
        cout << "Address held in this pointer:" << this << endl; 
    }
};

int main(void)
{
    interface iface1;
    interface iface2;

    cout << "Address of iface1 object:" << &iface1 << endl; 
    iface1.configure(1, 2, 0, 4);
    cout << "Address of iface2 object:" << &iface2 << endl; 
    iface2.configure(2, 8, 1, 1);

    return EXIT_SUCCESS;
}
