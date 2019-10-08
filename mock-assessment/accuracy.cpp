#include "accuracy.h"
#include <optional>
#include <utility>

double Accuracy::accuracy(double numerical, double analytical) {
    return analytical - numerical;
}

Accuracy::Accuracy(Dataset numerical_solution, Dataset analytical_solution) {
    this->analytical_solution = std::move(analytical_solution);
    this->numerical_solution = std::move(numerical_solution);
}

/*
 * This function can return an exception if the datasets or the data points are not of the same size.
 */
Dataset Accuracy::compute() {
    Dataset accuracy_dataset;

    if (numerical_solution.size() != analytical_solution.size()) throw std::invalid_argument("Datasets  are of different sizes.");

    for (auto data_point : numerical_solution) {
        auto key = data_point.first;
        auto numerical = data_point.second;
        auto analytical = analytical_solution[key];

        auto accuracy = compare(numerical, analytical);
        if (!accuracy) throw std::invalid_argument("Data points are of different sizes.");

        accuracy_dataset[key] = *accuracy;
    }

    return accuracy_dataset;
}

std::optional<Vector> Accuracy::compare(Vector numerical, Vector analytical) {
    Vector resultant;
    if (numerical.size() != analytical.size()) return {};

    int index = 0;
    for (auto e = numerical.begin(); e != numerical.end(); ++e, ++index) {
        resultant.push_back(accuracy(*e, analytical[index]));
    }
    return resultant;
}
