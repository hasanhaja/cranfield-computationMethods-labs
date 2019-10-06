#include "solution.h"

// Default constructor
Solution::Solution(Scheme scheme) { set_scheme(scheme); }

// This constructor will override the start and end values set by the default
// constructor
Solution::Solution(Scheme scheme, double start, double end) : Solution(scheme) {
    set_points(start, end);
}

void Solution::set_points(double start, double end) {
    this->start = start;
    this->end = end;
}

void Solution::set_scheme(Scheme scheme) { this->scheme = scheme; }

Vector Solution::_analytical(double deltax) {
    Vector results;
    auto method = scheme.get_fun_prime();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x);
        results.push_back(result);
    }

    return results;
}

Vector Solution::_finite(double deltax) {
    Vector results;
    auto method = scheme.method();

    for (double x = start; x <= end; x += deltax) {
        double result = method(x, deltax);
        results.push_back(result);
    }

    return results;
}

Dataset Solution::generate_for_grid_sizes(Vector sizes, SolutionType solution_type) {
    Dataset dataset;
    SolutionMethod method;

    switch (solution_type) {
        case SolutionType::Analytical:
            method = analytical;
            break;
        case SolutionType::Finite:
            method = finite;
            break;
    }

    for (auto deltax : sizes) {
        dataset[deltax] = method(deltax);
    }

    return dataset;
}