#include <iostream>
using namespace std;

class Rectangle
{
private:
    uint32_t length;
    uint32_t breadth;

public:
    Rectangle();
    Rectangle(uint32_t length, uint32_t breadth);
    Rectangle(Rectangle &r);
    void setLength(uint32_t length);
    uint32_t getLength();
    void setBreadth(uint32_t breadth);
    uint32_t getBreadth();
    uint32_t area();
    uint32_t perimeter();
    ~Rectangle();
};

class Cuboid:public Rectangle
{
    private:
        uint32_t height;
    public:
        Cuboid(uint32_t l, uint32_t b, uint32_t h);
        uint32_t getHeight();
        void setHeight(uint32_t h);
        uint32_t getVolume(void);
        ~Cuboid();
};

Rectangle::Rectangle()
{
    cout<<"Rectangle: In default constructor"<<endl;
    setLength(1);
    setBreadth(1);
}
Rectangle::Rectangle(uint32_t length, uint32_t breadth)
{
    cout<<"Rectangle: In parameterized constructor"<<endl;
    setLength(length);
    setBreadth(breadth);
}
Rectangle::Rectangle(Rectangle &r)
{
    cout<<"Rectangle: In copy constructor"<<endl;
    this->length = r.length;
    this->breadth = r.breadth;
}
void Rectangle::setLength(uint32_t length) // Mutator
{
    this->length = length;
}
uint32_t Rectangle::getLength() // Facilitator
{
    return this->length;
}
void Rectangle::setBreadth(uint32_t breadth) // Mutator
{
    this->breadth = breadth;
}
uint32_t Rectangle::getBreadth() // Facilitator
{
    return this->breadth;
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

Cuboid::Cuboid(uint32_t l, uint32_t b, uint32_t h):Rectangle(b, l)
{
    cout<<"Cuboid: In parameterized constructor"<<endl;
    this->setHeight(h);
}
void Cuboid::setHeight(uint32_t h) // Mutator
{
    this->height = h;
}
uint32_t Cuboid::getHeight() // Facilitator
{
    return this->height;
}
uint32_t Cuboid::getVolume(void)
{
    return this->height * this->getLength() * this->getBreadth();
}

Cuboid::~Cuboid()
{
    cout<<"Cuboid: In destructor.."<<endl;
}

int main(void)
{
    Cuboid C1(10, 5, 8);

    cout<<"Length is "<<C1.getLength()<<", "<<"Breadth is "<<C1.getBreadth()<<", "<<"Height is "<<C1.getHeight()<<endl;
    cout<<"Volume is "<<C1.getVolume()<<endl;
    return 0;
}
