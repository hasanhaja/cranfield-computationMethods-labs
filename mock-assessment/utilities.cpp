#include "utilities.h"
#include <iostream>

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

}  // namespace util