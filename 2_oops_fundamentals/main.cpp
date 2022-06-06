#include <iostream>
using namespace std;

class Rectangle
{
private:
    uint32_t length;
    uint32_t breadth;
public:
    void setLength(uint32_t l)
    {
        length = l;
    }
    uint32_t getLength()
    {
        return length;
    }
    void setBreadth(uint32_t b)
    {
        breadth = b;
    }
    uint32_t getbreadth()
    {
        return breadth;
    }
    uint32_t area()
    {
        return length * breadth;
    }
    uint32_t perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main(void)
{
    Rectangle R1;
    R1.setLength(10);
    R1.setBreadth(5);

    cout<<"Length is "<<R1.getLength()<<", "<<"Breadth is "<<R1.getbreadth()<<endl;
    cout<<"Area is "<<R1.area()<<endl;
    cout<<"Area is "<<R1.perimeter()<<endl;

    return 0;
}
