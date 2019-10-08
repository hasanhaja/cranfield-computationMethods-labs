#include <iostream>
#include "solution.h"
#include "aliases.h"
#include "utilities.h"
#include "accuracy.h"

double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

double fPrime(double x) { return 9.0 * (x * x) + 2.0; }

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    SchemeType scheme_t = SchemeType::Forward;
    Vector sizes {0.1, 0.01, 0.001, 0.0001, 0.00001};
//    Vector sizes {0.1, 0.01};
//    Vector sizes {0.1};


    Scheme scheme(f, fPrime, scheme_t);
    Solution solution(scheme);

    auto result = solution.compute(deltax, SolutionType::Analytical);
    auto forward = solution.compute(deltax, SolutionType::Finite);

    auto analytical = solution.generate_data_for_grid_sizes(sizes, SolutionType::Analytical);
    auto finite = solution.generate_data_for_grid_sizes(sizes, SolutionType::Finite);

//    util::display::print_dataset(analytical);
//    util::display::print_dataset(finite);

    Accuracy accuracy(finite, analytical);
    auto acc_dataset = accuracy.compute();

    std::map<double, double> normalized;
    std::cout << "L1 Norm:" << std::endl;
    for (const auto& e : acc_dataset) {
        normalized[e.first] = util::vector::l1_norm(e.second);
    }
    util::display::print_accuracy(normalized);

    std::cout << "L2 Norm:" << std::endl;
    std::map<double, double> normalized_2;
    for (const auto& e : acc_dataset) {
        normalized_2[e.first] = util::vector::l2_norm(e.second);
    }
    util::display::print_accuracy(normalized_2);

    std::cout << "Uniform Norm:" << std::endl;
    std::map<double, double> normalized_uniform;
    for (const auto& e : acc_dataset) {
        normalized_uniform[e.first] = util::vector::uniform_norm(e.second);
    }

    util::display::print_accuracy(normalized_uniform);

    return 0;
}
