#include "scheme.h"

Scheme::Scheme() {}

Scheme::Scheme(std::function<double(double)> fun,
               std::function<double(double)> fun_prime) {
    set_fun_and_fun_prime(fun, fun_prime);
}

Scheme::Scheme(std::function<double(double)> fun,
               std::function<double(double)> fun_prime, double deltax,
               SchemeType scheme_t)
    : Scheme(fun, fun_prime) {
    set_deltax(deltax);
    set_scheme_t(scheme_t);
}
void Scheme::set_fun_and_fun_prime(std::function<double(double)> fun,
                                   std::function<double(double)> fun_prime) {
    this->fun = fun;
    this->fun_prime = fun;
}
void Scheme::set_scheme_t(SchemeType scheme_t) { this->scheme_t = scheme_t; }

double Scheme::get_deltax() const { return deltax; }

SchemeType Scheme::get_schemeType() const { return scheme_t; }

std::function<double(double)> Scheme::get_fun() { return fun; }
std::function<double(double)> Scheme::get_fun_prime() { return fun_prime; }

std::function<double(double, double)> Scheme::method() {
    std::function<double(double, double)> method;

    switch (scheme_t) {
        case SchemeType::Forward:
            method = forward_difference;
            break;
        case SchemeType::Backward:
            method = backward_difference;
            break;
        case SchemeType::Central:
            method = central_difference;
            break;
    }

    return method;
}

void Scheme::set_deltax(double deltax) { this->deltax = deltax; }