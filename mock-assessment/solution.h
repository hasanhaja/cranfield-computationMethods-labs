#include "scheme.h"
#include <vector>

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

    Vec analyticalSolution(double start, double end, double deltax);
    Vec finiteSolution(double start, double end, double deltax);
};

#endif