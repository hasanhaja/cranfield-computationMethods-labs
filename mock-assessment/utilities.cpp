#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

namespace util {

    void display(double in, double result) {
        std::cout << "f(" << in << ") = " << result << std::endl;
    }

    void show(std::string msg) { std::cout << msg << std::endl; }

    void printVec(Vector vec, std::string msg) {
        show(msg);
        for (auto result : vec) {
            std::cout << result << std::endl;
        }
    }

    double l1_norm(Vector x) {
        // std::transform maps the entire Vector x to a vector of absolute values of the original elements
        std::transform(x.begin(), x.end(), x.begin(), [](double e) -> double { return std::fabs(e); });
        // std::accumulate folds the entire vector into a single value.
        return std::accumulate(x.begin(), x.end(), 0.0);
    }

    double l2_norm(Vector x) {

        return 0.0;
    }

}  // namespace util