#include <iostream>
#include <cmath>

const double ALPHA = 1.0;

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

double initial_condition(double x) {
    return analytical_f0(x, 0.0);
}

double boundary_condition(double x) {
    return analytical_f1(x, 0.0);
}

double forward(double param) {
    return 0.0;
}

double backward(double param) {
    return 0.0;
}

double central(double param) {
    return 0.0;
}

double upwind(double space, double time) {
    forward(space);
    backward(time);
}

/*
 * Would be better if it took an Enum as a parameter.
 * Then the if-else can be replaced by switch-case
 */
double scheme(int space, int time) {
    if (space == 1 && time == -1) {
        upwind(0.0, 0.0);
    } else if (space == 0 && time == 0) {
        central(0.0);
    } else {
        // Do nothing for now
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}