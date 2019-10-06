#include <iostream>
#include <map>
#include "solution.h"
#include "utilities.h"

double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

double fPrime(double x) { return 9.0 * (x * x) + 2.0; }

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    SchemeType scheme_t = SchemeType::Forward;

    Scheme scheme(f, fPrime, scheme_t);
    Solution sol(scheme);

    auto result = sol.analytical();

    for (auto e : result) {
        std::cout << e << std::endl;
    }

    auto forward = sol.finite();

    for (auto e : forward) {
        std::cout << e << std::endl;
    }

    return 0;
}
