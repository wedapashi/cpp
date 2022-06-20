#include <iostream>
using namespace std;

class Info {
private:
    int pid;
    int major;
    int minor;
public:
    static int ppid;
    
    static int get_ppid(void)
    {
        return ppid;
    }

    static void update_ppid(int v)
    {
        ppid = v;
        // pid = -1; // << Enable this and see the compilation error!
    }
};

int Info::ppid;
int main(void)
{
    Info P1, P2;
    P1.update_ppid(100);
    cout << "PPID when accessed through object P1 is: " << P2.get_ppid() << endl;
    cout << "PPID when accessed through object P2 is: " << P2.get_ppid() << endl;
    cout << "PPID when accessed through class method without using an object is: " << Info::get_ppid() << endl;

    return 0;
}
