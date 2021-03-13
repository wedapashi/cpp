#include <iostream>
using namespace std;

class Rectangle
{
private:    
    int length;
    int breadth;
public:
    Rectangle(void);
    int getLength(void);
    void setLength(int);
    int getBreadth(void);
    void setBreadth(int);
    int area(void);
    int perimeter(void);
    ~Rectangle(void);
};

int Rectangle::getLength(void)
{
    return length;
}
void Rectangle::setLength(int l)
{
    length = l;
}
int Rectangle::getBreadth(void)
{
    return breadth;
}
void Rectangle::setBreadth(int b)
{
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
Rectangle::Rectangle(void)
{
    cout << "In constructor" << endl;
    length = 0;
    breadth = 0;
}
Rectangle::~Rectangle(void)
{
    cout << "In distructor" << endl;
    length = 0;
    breadth = 0;
}

int main(void)
{
    Rectangle R1;

    //R1.length = 10;
    //R1.breadth = 5;

    cout<<"Area is "<<R1.area()<<endl;
    cout<<"Area is "<<R1.perimeter()<<endl;

    return 0;
}
