#include <iostream>
#include "solution.h"
#include "accuracy.h"
#include "aliases.h"

double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

double fPrime(double x) { return 9.0 * (x * x) + 2.0; }

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    SchemeType scheme_t = SchemeType::Forward;
    Vector sizes {0.1, 0.01, 0.001, 0.0001, 0.00001};

    Scheme scheme(f, fPrime, scheme_t);
    Solution solution(scheme);

    auto result = solution.compute(deltax, SolutionType::Analytical);
    auto forward = solution.compute(deltax, SolutionType::Finite);
    auto analytical = solution.generate_data_for_grid_sizes(sizes, SolutionType::Analytical);
    auto finite = solution.generate_data_for_grid_sizes(sizes, SolutionType::Finite);

    for (auto e : result) {
        std::cout << e << std::endl;
    }

    for (auto e : forward) {
        std::cout << e << std::endl;
    }

    return 0;
}
