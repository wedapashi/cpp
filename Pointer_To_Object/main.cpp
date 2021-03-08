
#include <iostream>
using namespace std;

#define STATIC_ALLOC    1

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
#ifdef STATIC_ALLOC

    Rectangle R1;
    Rectangle *pRect = &R1;

#else

    Rectangle *pRect = new Rectangle;

#endif

    pRect->length = 10;
    pRect->breadth = 5;

    cout<<"Area is "<<pRect->area()<<endl;
    cout<<"Area is "<<pRect->perimeter()<<endl;

#ifndef STATIC_ALLOC
    free(pRect);
    pRect=nullptr;
#endif

    return 0;
}
