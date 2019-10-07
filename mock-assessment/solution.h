#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <vector>
#include "aliases.h"
#include "scheme.h"

enum class SolutionType {
    Analytical,
    Finite,
};

class Solution {
   private:
    Scheme scheme;
    double start = 0.0;
    double end = 1.0;
    Vector _compute(double deltax, SolutionType solution_type);

   public:
    Solution(Scheme scheme);
    Solution(Scheme scheme, double start, double end);
    void set_points(double start, double end);
    void set_scheme(Scheme scheme);
    Dataset generate_for_grid_sizes(Vector sizes, SolutionType solution_type);

    SolutionMethod compute = [&] (double deltax, SolutionType solution_type) -> Vector {
        return _compute(deltax, solution_type);
    };

};

#endif