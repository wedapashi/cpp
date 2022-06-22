#include <iostream>
using namespace std;

class Time
{
private:
    uint32_t hours;
    uint32_t minutes;
public:
    Time() { 
        hours = minutes = 0; 
    }
    Time(uint32_t hh, uint32_t min) {
        hours = hh;
        minutes = min;
    }
    friend Time operator+(Time t1, Time t2);
    void print(void) {
        cout << "Time: " << hours << ":" << minutes << endl;
    }
        
};
Time operator+(Time t1, Time t2)
{
    Time temp;
    temp.minutes = t1.minutes + t2.minutes;
    temp.hours = t1.hours + t2.hours + temp.minutes / 60;
    temp.minutes %= 60;
    return temp;
}
int main(void)
{
    Time T1(2, 56);
    Time T2(2, 44);
    Time T(0, 0);
    cout<<"Calling overloaded friend function.."<<endl;
    T = T1+T2;
    T.print();
    return 0;
}
