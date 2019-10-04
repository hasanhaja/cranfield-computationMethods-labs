#include "solution.h"

Solution::Solution(Scheme scheme) { this->scheme = scheme; }

Solution::Solution(Scheme scheme, double start, double end) : Solution(scheme) {
    set_end_points(start, end);
}

void Solution::set_end_points(double start, double end) {
    this->start = start;
    this->end = end;
}

Vec Solution::analytical_solution() {
    std::vector<double> results;

    for (double x = start; x <= end; x += scheme.get_deltax()) {
        double result = scheme.get_fun_prime()(x);
        results.push_back(result);
    }

    return results;
}
Vec Solution::finite_solution() {
    std::vector<double> results;

    for (double x = start; x <= end; x += scheme.get_deltax()) {
        double result = scheme.method()(x, scheme.get_deltax());
        results.push_back(result);
    }

    return results;
}