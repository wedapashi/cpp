#include <iostream>
using namespace std;

class Rectangle
{
private:
    uint32_t length;
    uint32_t breadth;

public:
    Rectangle();
    Rectangle(uint32_t l, uint32_t b);
    Rectangle(Rectangle &r);
    void setLength(uint32_t l);
    uint32_t getLength();
    void setBreadth(uint32_t b);
    uint32_t getbreadth();
    uint32_t area();
    uint32_t perimeter();
    ~Rectangle();
};

Rectangle::Rectangle()
{
    cout<<"Rectangle: In default constructor"<<endl;
    setLength(1);
    setBreadth(1);
}
Rectangle::Rectangle(uint32_t l, uint32_t b)
{
    cout<<"Rectangle: In parameterized constructor"<<endl;
    setLength(l);
    setBreadth(b);
}

Rectangle::Rectangle(Rectangle &r)
{
    cout<<"Rectangle: In copy constructor"<<endl;
    length = r.length;
    breadth = r.breadth;
}

void Rectangle::setLength(uint32_t l) // Mutator
{
    length = l;
}

uint32_t Rectangle::getLength() // Facilitator
{
    return length;
}

void Rectangle::setBreadth(uint32_t b) // Mutator
{
    breadth = b;
}

uint32_t Rectangle::getbreadth() // Facilitator
{
    return breadth;
}

uint32_t Rectangle::area()
{
    return length * breadth;
}

uint32_t Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle()
{
    cout<<"Rectangle: In destructor.."<<endl;
}

int main(void)
{
    Rectangle R1;  // Invokes default constructor
    Rectangle R2(10, 5); // Invokes paramterized constructor
    Rectangle R3(R2); // Invokes copy constructor

    cout<<"Length is "<<R1.getLength()<<", "<<"Breadth is "<<R1.getbreadth()<<endl;
    cout<<"Area is "<<R1.area()<<endl;
    cout<<"Area is "<<R1.perimeter()<<endl;
    cout<<endl;
    cout<<"Length is "<<R2.getLength()<<", "<<"Breadth is "<<R2.getbreadth()<<endl;
    cout<<"Area is "<<R2.area()<<endl;
    cout<<"Area is "<<R2.perimeter()<<endl;
    cout<<endl;
    cout<<"Length is "<<R3.getLength()<<", "<<"Breadth is "<<R3.getbreadth()<<endl;
    cout<<"Area is "<<R3.area()<<endl;
    cout<<"Area is "<<R3.perimeter()<<endl;

    return 0;
}
