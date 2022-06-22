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
    foo(const foo &) = delete;
    void print(void) {
        cout << "bar = " << bar << ", baz = " << baz << endl;
    }
    void setBar(uint32_t Bar) {
        bar = Bar;
    }
    void setBar(uint64_t Bar) = delete;
    void setBar(float Bar) = delete;
};

int main(void)
{
    uint64_t u64val = 4321;
    foo f1;
    f1.print();
    foo f2(10, 5);
    f2.print();
    foo f3(f2);
    f2.setBar(1234);
    f2.setBar(12.34f);
    f2.setBar(u64val);
    f2.print();
    return EXIT_SUCCESS;
}
