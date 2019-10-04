#include <vector>
#include "scheme.h"

using Vec = std::vector<double>;

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
   private:
    Scheme scheme;
    double start;
    double end;
    std::function<double(double, double)> method;

   public:
    Solution(Scheme scheme);
    Solution(Scheme scheme, double start, double end);

    void set_end_points(double start, double end);

    Vec analytical_solution();
    Vec finite_solution();
};

#endif