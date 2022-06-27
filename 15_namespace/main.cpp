#include<iostream>
using namespace std;
#define msg(x)  #x

namespace Dev1 {
    void printVersion(void) {
        cout << msg(V1.00) << endl;
    }
};

namespace Dev2 {
    void printVersion(void) {
        cout << msg(V2.00) << endl;
    }
};

int main(void) {    
    using namespace Dev1;
    printVersion();
    Dev1::printVersion();
    Dev2::printVersion();
    return EXIT_SUCCESS;
}
