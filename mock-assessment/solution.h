#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <vector>
#include "aliases.h"
#include "scheme.h"

class Solution {
   private:
    Scheme scheme;
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    MethodFn method;

   public:
    Solution(Scheme scheme);
    Solution(Scheme scheme, double start, double end);
    Solution(Scheme scheme, double start, double end, double deltax);
    void set_points(double start, double end);
    void set_deltax(double deltax);
    void set_scheme(Scheme scheme);
    Vec analytical();
    Vec finite();
    Dataset generate_for_grid_sizes(Vec sizes);
};

#endif