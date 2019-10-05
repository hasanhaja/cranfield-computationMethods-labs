#include <iostream>
#include <map>

#include "solution.h"
#include "utilities.h"

double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

double fPrime(double x) { return 9.0 * (x * x) + 2.0; }

// double measureAccuracy(double calculated, double analytical) {
//     return analytical - calculated;
// }

// std::map<double, std::vector<double>> generateSolution(
//     double start, double end, double deltax, int steps,
//     std::function<double(double, double)> method) {
//     std::map<double, std::vector<double>> dataset;

//     for (int i = 0; i < steps; i++) {
//         auto finiteResults = finiteSolution(start, end, deltax, method);
//         dataset[deltax] = finiteResults;
//         deltax /= 10.0;
//     }

//     return dataset;
// }

// void display(double in, double result) {
//     std::cout << "f(" << in << ") = " << result << std::endl;
// }

// void show(std::string msg) { std::cout << msg << std::endl; }

// void printVec(std::vector<double> vec, std::string msg) {
//     show(msg);
//     for (auto result : vec) {
//         std::cout << result << std::endl;
//     }
// }

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    SchemeType scheme_t = SchemeType::Forward;

    Scheme scheme(f, fPrime, scheme_t);
    Solution sol(scheme, start, end, deltax);

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
