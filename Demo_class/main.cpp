
#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;

    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main(void)
{
    Rectangle R1;

    R1.length = 10;
    R1.breadth = 5;
    cout<<"Area is "<<R1.area()<<endl;
    cout<<"Area is "<<R1.perimeter()<<endl;

    return 0;
}
