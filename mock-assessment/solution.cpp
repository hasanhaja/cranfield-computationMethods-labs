#include "solution.h"

// Default constructor
Solution::Solution(Scheme scheme) {
    set_scheme(scheme);
    set_points(0.0, 1.0);
    set_deltax(0.1);
}

// This constructor will override the start and end values set by the default
// constructor
Solution::Solution(Scheme scheme, double start, double end) : Solution(scheme) {
    set_points(start, end);
}

// This constructor will override the start and end values set by the secondary
// constructor as well as the deltax values
Solution::Solution(Scheme scheme, double start, double end, double deltax)
    : Solution(scheme, start, end) {
    set_deltax(deltax);
}

void Solution::set_points(double start, double end) {
    this->start = start;
    this->end = end;
}

void Solution::set_deltax(double deltax) { this->deltax = deltax; }

void Solution::set_scheme(Scheme scheme) { this->scheme = scheme; }

Vec Solution::analytical() {
    Vec results;
    auto method = scheme.get_fun_prime();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x);
        results.push_back(result);
    }

    return results;
}

Vec Solution::finite() {
    Vec results;
    auto method = scheme.method();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x, deltax);
        results.push_back(result);
    }

    return results;
}