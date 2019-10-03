#include <functional>
#include <iostream>
#include <string>
#include <vector>

double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

double fPrime(double x) { return 9.0 * (x * x) + 2.0; }

double forwardDifference(double x, double deltax) {
    return (f(x + deltax) - f(x)) / deltax;
}

double backwardDifference(double x, double deltax) {
    return (f(x) - f(x - deltax)) / deltax;
}

double centralDifference(double x, double deltax) {
    return (f(x + deltax) - f(x - deltax)) / (2.0 * deltax);
}

double measureAccuracy(double calculated, double analytical) {
    return analytical - calculated;
}

std::vector<double> analyticalSolution(double start, double end, double deltax,
                                       std::function<double(double)> method) {
    std::vector<double> results;

    for (double x = start; x <= end;) {
        double result = method(x);
        results.push_back(result);
        x += deltax;
    }

    return results;
}

std::vector<double> finiteSolution(
    double start, double end, double deltax,
    std::function<double(double, double)> method) {
    std::vector<double> results;

    for (double x = start; x <= end;) {
        double result = method(x, deltax);
        results.push_back(result);
        x += deltax;
    }

    return results;
}

void display(double in, double result) {
    std::cout << "f(" << in << ") = " << result << std::endl;
}

void show(std::string msg) { std::cout << msg << std::endl; }

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;

    auto actualResults = analyticalSolution(start, end, deltax, fPrime);
    auto forwardResults = finiteSolution(start, end, deltax, forwardDifference);
    auto backwardResults =
        finiteSolution(start, end, deltax, backwardDifference);
    auto centralResults = finiteSolution(start, end, deltax, centralDifference);

    show("Actual results:");
    for (auto result : actualResults) {
        std::cout << result << std::endl;
    }

    show("Forward results:");
    for (auto result : forwardResults) {
        std::cout << result << std::endl;
    }

    show("Backward results:");
    for (auto result : backwardResults) {
        std::cout << result << std::endl;
    }

    show("Central results:");
    for (auto result : centralResults) {
        std::cout << result << std::endl;
    }

    return 0;
}
