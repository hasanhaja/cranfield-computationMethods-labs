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
    MethodFn method;

   public:
    Solution(Scheme scheme);
    Solution(Scheme scheme, double start, double end);

    void set_points(double start, double end);

    Vec analytical();
    Vec finite();
};

#endif