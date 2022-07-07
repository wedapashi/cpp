#include <iostream>
using namespace std;

double& calibrate(double& d) {
    const double m = 1.146789;
    const double c = -0.004583;
    d = d*m+c;
    return d;
}

void function(double& d) {
    cout << "(function) double& -- bound to l-value reference" << endl;
}

void function(const double& d) {
    cout << "(function) const double& -- bound to constant l-value reference" << endl;
}

void test(const double& d) {
    cout << "(test) const double& -- bound to constant l-value reference" << endl;
}

void test(double&& d) {
    cout << "(test) double&& -- bound to r-value reference" << endl;
}

int main(void) {
    double pressure = 42.564808;
    pressure = calibrate(pressure);
    cout << pressure << endl;
    cout << "Calling -- function(pressure) -- with l-value" << endl;
    function(pressure);
    cout << "Calling -- function(10.10) -- with temporary which is a r-value" << endl;
    function(10.10);
    cout << "Calling -- test(10.10) -- with temporary which is a r-value" << endl;
    test(10.10);
    return EXIT_SUCCESS;
}
