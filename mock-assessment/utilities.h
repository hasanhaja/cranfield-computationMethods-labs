#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include "aliases.h"

namespace util {

    namespace display {
        void print_dataset(Dataset data);
        std::string stringify_vector(const Vector& vec);
        void print_accuracy(std::map<double, double> data);
    }

    namespace vector {
        double l1_norm(Vector x);
        double l2_norm(Vector x);
        double uniform_norm(Vector x);
    }

    namespace file {
        void write_to_file(std::string filename);
    }

}  // namespace util

#endif  //UTILITIES_H