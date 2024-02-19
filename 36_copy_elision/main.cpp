#include <iostream>
#include <vector>

class Integer {
public:
    int* ptr;
    Integer() { }
    Integer(int value) {
        std::cout << "Integer(int)" <<std::endl;
        ptr = new int(value);
    }
    Integer(const Integer& foo) : Integer(*foo.ptr) {
        std::cout << "Integer(const Integer&)" <<std::endl;
    }
    Integer(Integer&& foo) : ptr(foo.ptr) {
        std::cout << "Integer(Integer&&)" <<std::endl;
        foo.ptr = nullptr;
    }
    Integer& operator=(const Integer& obj) {
        std::cout << "In Copy assignment operator: Integer& operator=(const Integer&)" << std::endl;
        if(this == &obj) {
            return *this;
        }
        delete ptr;
        ptr = new int(*obj.ptr);
        return *this;
    }
    Integer& operator=(Integer&& obj) {
        std::cout << "In Move Assignment Operator: Integer& operator=(Integer&&)" << std::endl;
        if(this == &obj) {
            return *this;
        }
        delete ptr;
        ptr = obj.ptr;
        obj.ptr = nullptr;
        return *this;
    }
    void print(void) {
        std::cout << *ptr << std::endl;
    }
    ~Integer() {
        std::cout << "~Integer()" << std::endl;
        delete ptr;
    }
};

Integer add(int a, int b) {
    Integer temp (a + b);
    return temp;
}

int main() {
    //Integer a = 10; // invokes a parameterized constructor due to Copy Elision
    Integer sum = add(10,20);
    return 0;
}