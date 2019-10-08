#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <vector>
#include "aliases.h"
#include "scheme.h"
#include "solutiontype.h"

class Solution {
   private:
    Scheme scheme;
    double start = 0.0;
    double end = 1.0;

   public:
    Solution(Scheme scheme);
    Solution(Scheme scheme, double start, double end);
    void set_points(double start, double end);
    void set_scheme(Scheme scheme);
    Vector compute(double deltax, SolutionType solution_type);
    Dataset generate_data_for_grid_sizes(const Vector& sizes, SolutionType solution_type);

};

#endif //SOLUTION_H