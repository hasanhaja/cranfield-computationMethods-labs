#include "utilities.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

namespace util {

    namespace vector {
        double l1_norm(Vector x) {
            // std::transform maps the entire Vector x to a vector of absolute values of the original elements
            std::transform(x.begin(), x.end(), x.begin(), [](double e) -> double { return std::fabs(e); });
            // std::accumulate folds the entire vector into a single value.
            return std::accumulate(x.begin(), x.end(), 0.0);
        }

        double l2_norm(Vector x) {
            std::transform(x.begin(), x.end(), x.begin(), [](double e) -> double { return e*e; });
            double sum = std::accumulate(x.begin(), x.end(), 0.0);
            return std::sqrt(sum);
        }

        double uniform_norm(Vector x) {
            // std::transform maps the entire Vector x to a vector of absolute values of the original elements
            std::transform(x.begin(), x.end(), x.begin(), [](double e) -> double { return std::fabs(e); });
            // std::max_element points to the largest element in the vector and the return statement dereferences the pointer
            return *std::max_element(x.begin(), x.end());
        }
    }

    namespace file {
        void write_to_file(std::string filename) {
            // TODO a text file would do, but maybe a csv file would be quicker?
            // Only if it is built in.
        }
    }

    namespace display {
        std::string stringify_vector(const Vector& vec) {
            std::string s;
            for (auto e : vec) {
                s += std::to_string(e);
                s += ", ";
            }
            return s;
        }

        void display::print_dataset(Dataset data) {
            for (auto e : data) {
                auto deltax = e.first;
                auto vec = e.second;
                std::cout << "Analytical: Deltax [" << deltax << "]: [" << stringify_vector(vec) << "]" << std::endl;
            }
        }

        void print_accuracy(std::map<double, double> data) {
            for (auto e: data) {
                std::cout << "Accuracy: Delta[" << e.first << "] = " << e.second << std::endl;
            }
        }
    }

}  // namespace util