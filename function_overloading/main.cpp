#include<iostream>
#include<stdint.h>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

float add(float a, float b)
{
    return a+b;
}

int main(void)
{
    int sum = add(10, 20);
    float fsum = add(12.53f, 45.89f);
    cout << sum  << endl;
    cout << fsum << endl;
    return 0;
}
