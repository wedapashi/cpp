#include <iostream>
using namespace std;

void print(char* str) {
    cout << str << endl;
}

int main(void) {
    const char* c = "Maverick";
    print(const_cast<char*> (c));
    return EXIT_SUCCESS;
}
