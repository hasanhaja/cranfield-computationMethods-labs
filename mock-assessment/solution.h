#include <vector>
#include "aliases.h"
#include "scheme.h"

#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
   private:
    Scheme scheme;
    double start;
    double end;
    double deltax;
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
};

#endif