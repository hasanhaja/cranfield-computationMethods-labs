#include <iostream>
#include <cmath>
#include <vector>

const double ALPHA = 1.0;

using Vector = std::vector<std::vector<double>>;

double numeric_viscosity(double alpha, double deltax, double deltat) {
    double cfl = (alpha * deltat) / deltax;
    return ((alpha * deltax) / 2.0) * (1.0 - cfl);
}

/*
 * Utility function
 * This should become util::math::sign(double);
 */
double sign(double n) {
    return n > 0 ? 1.0 : -1.0;
}

/*
 * Analytical solutions for the initial conditions
 */
double analytical_f0(double x, double t) {
    return (sign(x-t) + 1.0) / 2.0;
}

double analytical_f1(double x, double t) {
    return (exp(-(pow(x - t, 2.0)))) / 2.0;
}

/*
 * Initial and boundary conditions
 */
double initial_condition1(double x) {
    return analytical_f0(x, 0.0);
}

double initial_condition2(double x) {
    return analytical_f1(x, 0.0);
}

Vector upwind() {
    Vector solution;

    /*
     * Boundaries
     */
    double left = -40.0;
    double right = 40.0;
    double points = 100.0;

    /*
     * boundary conditions
     */

    double grid_size = fabs(left) + fabs(right);
    double grid_spacing = grid_size / points;

    double x = left;
    std::vector<double> initial_values;

    for (int i = 0; i < ceil(points); i++) {
        initial_values.push_back(initial_condition1(x));
        x += grid_spacing;
    }

    double in1 = initial_condition1(x);

    for (int i = 0; i <= 100; i++) {

    }

    return solution;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}