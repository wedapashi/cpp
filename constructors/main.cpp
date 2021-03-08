#include <iostream>
using namespace std;

class Rectangle
{
private:
    uint32_t length;
    uint32_t breadth;

public:
    // Default constructor, can't return anything!
    /*
    Rectangle()
    {
        cout<<"Rectangle: In default constructor"<<endl;
        length = 1;
        breadth = 1;
    }
    */
    // Parameterized constructor, can't return anything! This also acts as default argument constructor
    // If default arguments are provided, the deault constructor is no longer required.
    Rectangle(uint32_t l=1, uint32_t b=1)
    {
        cout<<"Rectangle: In parameterized constructor"<<endl;
        setLength(l);
        setBreadth(b);
    }
    // Copy constructor
    Rectangle(Rectangle &r)
    {
        cout<<"Rectangle: In copy constructor"<<endl;
        length = r.length;
        breadth = r.breadth;
    }
    void setLength(uint32_t l) // Mutator
    {
        length = l;
    }
    uint32_t getLength() // Facilitator
    {
        return length;
    }
    void setBreadth(uint32_t b) // Mutator
    {
        breadth = b;
    }
    uint32_t getbreadth() // Facilitator
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
    Rectangle R1;  // Invokes default constructor
    Rectangle R2(10, 5); // Invokes paramterized constructor
    Rectangle R3(R2); // Invokes copy constructor

    cout<<"Length is "<<R1.getLength()<<", "<<"Breadth is "<<R1.getbreadth()<<endl;
    cout<<"Area is "<<R1.area()<<endl;
    cout<<"Perimeter is "<<R1.perimeter()<<endl;
    cout<<endl;
    cout<<"Length is "<<R2.getLength()<<", "<<"Breadth is "<<R2.getbreadth()<<endl;
    cout<<"Area is "<<R2.area()<<endl;
    cout<<"Perimeter is "<<R2.perimeter()<<endl;
    cout<<endl;
    cout<<"Length is "<<R3.getLength()<<", "<<"Breadth is "<<R3.getbreadth()<<endl;
    cout<<"Area is "<<R3.area()<<endl;
    cout<<"Perimeter is "<<R3.perimeter()<<endl;

    return 0;
}
