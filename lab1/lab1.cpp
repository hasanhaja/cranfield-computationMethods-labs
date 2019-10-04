/*
 * This file has been deprecated and the development of this task has moved
 * to the directory /mock-assessment.
 */
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// TODO This should be defined elsewhere. Or should be user definable.
double f(double x) { return 3.0 * (x * x * x) + 2.0 * x + 1.0; }

// TODO This should be defined elsewhere. Or should be user definable.
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

    for (double x = start; x <= end; x += deltax) {
        double result = method(x);
        results.push_back(result);
    }

    return results;
}

std::vector<double> finiteSolution(
    double start, double end, double deltax,
    std::function<double(double, double)> method) {
    std::vector<double> results;

    for (double x = start; x <= end; x += deltax) {
        double result = method(x, deltax);
        results.push_back(result);
    }

    return results;
}

std::map<double, std::vector<double>> generateSolution(
    double start, double end, double deltax, int steps,
    std::function<double(double, double)> method) {
    std::map<double, std::vector<double>> dataset;

    for (int i = 0; i < steps; i++) {
        auto finiteResults = finiteSolution(start, end, deltax, method);
        dataset[deltax] = finiteResults;
        deltax /= 10.0;
    }

    return dataset;
}

void display(double in, double result) {
    std::cout << "f(" << in << ") = " << result << std::endl;
}

void show(std::string msg) { std::cout << msg << std::endl; }

void printVec(std::vector<double> vec, std::string msg) {
    show(msg);
    for (auto result : vec) {
        std::cout << result << std::endl;
    }
}

int main() {
    double start = 0.0;
    double end = 1.0;
    double deltax = 0.1;
    int steps = 5;

    auto actualResults = analyticalSolution(start, end, deltax, fPrime);
    auto forwardResults = finiteSolution(start, end, deltax, forwardDifference);
    auto backwardResults =
        finiteSolution(start, end, deltax, backwardDifference);
    auto centralResults = finiteSolution(start, end, deltax, centralDifference);

    auto solution = generateSolution(start, end, deltax, 5, centralDifference);

    auto first = solution[deltax];

    for (auto answer : solution) {
        std::vector<double> result = answer.second;

        printVec(result, "Answers");
        std::cout << "------------------" << std::endl;
    }

    return 0;
}
