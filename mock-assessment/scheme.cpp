#include "scheme.h"

Scheme::Scheme(std::function<double(double)> fun, std::function<double(double)> fun_prime) {
    this->fun = fun;
    this->fun_prime = fun_prime;
}

Scheme::Scheme(std::function<double(double)> fun,
               std::function<double(double)> fun_prime, double x,
               double deltax, SchemeType scheme) : Scheme(fun, fun_prime) {
    set_x_and_deltax(x, deltax);
    this->scheme = scheme;
}

std::function<double(double, double)> Scheme::method() {
    
    std::function<double(double, double) method;

    switch(scheme) {
        case Forward:
            method = forward_difference;
            break;
        case Backward:
            method = backward_difference;
            break;
        case Central:
            method = central_difference;
            break;
    }

    return method;
}

double Scheme::forward_difference(double x, double deltax) const {
    return (fun(x + deltax) - fun(x)) / deltax;
}

double Scheme::backward_difference(double x, double deltax) const {
    return (fun(x) - fun(x - deltax)) / deltax;
}

double Scheme::central_difference(double x, double deltax) const {
    return (fun(x + deltax) - fun(x - deltax)) / (deltax + deltax);
}

void Scheme::set_x_and_deltax(double x, double deltax) {
    this->x = x;
    this->deltax = deltax;

}