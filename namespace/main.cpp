#include<iostream>

using namespace std;

#define msg(x)  #x

namespace Dev1
{
    void printVersion(void)
    {
        cout<<msg(V1.00)<<endl;
    }
};

namespace Dev2
{
    void printVersion(void)
    {
        cout<<msg(V1.01)<<endl;
    }
};

using namespace Dev1;
int main(void)
{
    printVersion();
    Dev2::printVersion();
    
    return 0;
}
