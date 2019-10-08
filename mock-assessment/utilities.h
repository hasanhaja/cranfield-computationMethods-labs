#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include "aliases.h"

namespace util {
    void display(double in, double result);
    void show(std::string msg);
    void printVec(Vector vec, std::string msg);
    double l1_norm(Vector x);
    double l2_norm(Vector x);
}  // namespace util

#endif  //UTILITIES_H