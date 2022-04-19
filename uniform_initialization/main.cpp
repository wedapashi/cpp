#include <iostream>
using namespace std;

class driver {
    private:
        uint16_t dataRate;
        uint8_t dmaChannel;
        // Other membsers will follow
    public:
        uint16_t getDatarate(void) { return dataRate; }
        uint8_t  getDMAChannel(void) { return dmaChannel; }
        driver(uint16_t dRate, uint8_t dmaChan) : dataRate(dRate), dmaChannel(dmaChan) {}
};

int main(void)
{    
    driver i2c2(9600, 3U); // This is old-style
    driver i2c1{4800, 3U}; // Supported in C++11
    driver i2cn = {2400, 3U}; // Supported in C++11
       
    cout<<"Data rate for i2c2 instance is "<< i2c2.getDatarate()<<endl;
    cout<<"Data rate for i2c1 instance is "<< i2c1.getDatarate()<<endl;
    cout<<"Data rate for i2cn instance is "<< i2cn.getDatarate()<<endl;
    return 0;
}
