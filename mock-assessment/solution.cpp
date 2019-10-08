#include "solution.h"

#include <utility>

// Default constructor
Solution::Solution(Scheme scheme) { set_scheme(std::move(scheme)); }

// This constructor will override the start and end values set by the default
// constructor
Solution::Solution(Scheme scheme, double start, double end) : Solution(std::move(scheme)) {
    set_points(start, end);
}

void Solution::set_points(double start, double end) {
    this->start = start;
    this->end = end;
}

void Solution::set_scheme(Scheme scheme) { this->scheme = std::move(scheme); }

Vector Solution::compute(double deltax, SolutionType solution_type) {
    Vector results;
    SchemeMethod method;

    switch (solution_type) {
        case SolutionType::Analytical:
            method = scheme.analytical();
            break;
        case SolutionType::Finite:
            method = scheme.method();
            break;
    }

    for (double x = start; x <= end; x += deltax) {
        double result = method(x, deltax);
        results.push_back(result);
    }

    return results;
}

Dataset Solution::generate_data_for_grid_sizes(const Vector& sizes, SolutionType solution_type) {
    Dataset dataset;

    for (auto deltax : sizes) {
        dataset[deltax] = compute(deltax, solution_type);
    }

    return dataset;
}