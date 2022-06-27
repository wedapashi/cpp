#include<iostream>
#include<cstdint>

int main(void) {
    using namespace std;
    uint32_t foo = 10;
    uint32_t bar = 20;
    cout << "foo = " << foo << ", bar = " << bar << endl;
    [&foo, &bar](){
        foo ^= bar;
        bar ^= foo;
        foo ^= bar;
    }();
    cout << "foo = " << foo << ", bar = " << bar << endl;
    return EXIT_SUCCESS;
}
