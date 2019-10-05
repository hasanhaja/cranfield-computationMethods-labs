#include "solution.h"

Solution::Solution(Scheme scheme) { this->scheme = scheme; }

Solution::Solution(Scheme scheme, double start, double end) : Solution(scheme) {
    set_points(start, end);
}

void Solution::set_points(double start, double end) {
    this->start = start;
    this->end = end;
}

Vec Solution::analytical() {
    Vec results;
    auto deltax = scheme.get_deltax();
    auto method = scheme.get_fun_prime();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x);
        results.push_back(result);
    }

    return results;
}

Vec Solution::finite() {
    Vec results;
    auto deltax = scheme.get_deltax();
    auto method = scheme.method();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x, deltax);
        results.push_back(result);
    }

    return results;
}