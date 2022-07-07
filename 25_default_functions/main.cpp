#include<iostream>
#include<cstdint>
using namespace std;

class foo {
private:
    uint32_t bar {0};
    uint32_t baz {0};
public:
    foo() = default;
    foo(uint32_t Bar, uint32_t Baz) {
        bar = Bar;
        baz = Baz;
    }
    foo(const foo &) = default;
    void print(void) {
        cout << "bar = " << bar << ", baz = " << baz << endl;
    }
        
};

int main(void)
{
    foo f1;
    f1.print();
    foo f2(10, 5);
    f2.print();
    foo f3(f2);
    f3.print();
    return EXIT_SUCCESS;
}
