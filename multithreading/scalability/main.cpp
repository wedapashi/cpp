#include <algorithm>
#include <cmath>
#include <execution>
#include <iostream>
#include <vector>

//#define USE_PAR

int main() {

    constexpr size_t N { 500'000'00 };

    std::vector<double> readings(N);

    auto process {
            [i = 0ULL](double& value) mutable {
            double x = static_cast<double>(i++);
            for(int k = 0; k < 100; ++k) {
                x = std::sin(x) * std::cos(x);
            }
            value = x;
        }
    }; 

    #ifdef USE_PAR

    std::for_each(std::execution::par,
                  readings.begin(),
                  readings.end(),
                  process);

    #else

    std::for_each(readings.begin(),
                  readings.end(),
                  process);

    #endif
                  
    std::cout << "Done\n";
}