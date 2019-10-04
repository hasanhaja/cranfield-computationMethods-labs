#include "solution.h"

Solution::Solution(Scheme scheme) {
    this->scheme = scheme;
}

Solution::Solution(Scheme scheme, double start, double end) : Solution(scheme) {
    set_end_points(start, end);
}

void Solution::set_end_points(double start, double end) {
    this->start = start;
    this->end = end;
}

Vec analyticalSolution() {
    std::vector<double> results;

    for (double x = start; x <= end; x += Scheme.deltax) {
        double result = Scheme.fun_prime(x);
        results.push_back(result);
    }

    return results;
}
Vec finiteSolution() {
    std::vector<double> results;

    for (double x = start; x <= end; x += Scheme.deltax) {
        // TODO switch case with enums
        double result = Scheme.method(x, deltax);
        results.push_back(result);
    }

    return results;
}