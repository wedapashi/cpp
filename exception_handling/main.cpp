#include <string>
#include <iostream>
using namespace std;

class UART
{
private:
    uint32_t dataLength;
    string Message;
public:
    UART();
    uint32_t getDataLength(void);
    void setDataLength(uint32_t);
    string getMessage(void);
    void setMessage(string s);
    uint32_t sendMessage(void);// throw (int);
    ~UART();
};

UART::UART(void)
{
    cout<<"In default constructor.."<<endl;
    this->Message.clear();
    this->dataLength = 0;
}
UART::~UART()
{
    cout<<"In default destructor.."<<endl;
}
void UART::setDataLength(uint32_t l)
{
    this->dataLength = l;
}
uint32_t UART::getDataLength(void)
{
    return this->dataLength;
}
void UART::setMessage(string s)
{
    this->Message = s;
}
string UART::getMessage(void)
{
    return this->Message;
}
uint32_t UART::sendMessage(void)// throw (int)
{
    if(0 == this->dataLength)
    {
        throw 1;
    }
    else if(true == this->Message.empty())
    {
        throw string("Unknown exception..");
    }
    else
    {
        cout<<this->Message<<"--";
        cout<<"Message sent!"<<endl;
    }

    return 0;
}

int main(void)
{
    uint32_t status = 0;
    UART uart;
    string str = "Exception Handling";
    //uart.setMessage(str);
    uart.setDataLength(str.length());

    try
    {
        status = uart.sendMessage();
    }
    catch(int e)
    {
        cout<<"In int catch block.."<<endl;

        if(1 == e)
        {
            cout<<"Data lenth not set.."<<endl;
        }
        else if(2 == e)
        {
            cout<<"Message is empty.."<<endl;
        }
        else
        {
            cout<<"Unknown exception.."<<endl;
        }
    }
    catch(double e)
    {
        cout<<"In double catch block.."<<endl;
    }
    catch(...)
    {
        cout<<"In catch-all block.."<<endl;
    }

    return 0;
}
