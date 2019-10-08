#include "accuracy.h"

double Accuracy::accuracy(double calculated, double analytical) {
    return analytical - calculated;
}

Accuracy::Accuracy(Dataset analytical_solution, Dataset numerical_solution) {
    this->analytical_solution = analytical_solution;
    this->numerical_solution = numerical_solution;
}

AccuracyDataset Accuracy::solution_accuracy() {
    /*
     * dataset would look like: [0.1: Vector{values}, 0.01: Vector{values} ...]
     */
    AccuracyDataset accuracyDataset;

    // TODO

    return accuracyDataset;
}