#include "scheme.h"

Scheme::Scheme() {}

Scheme::Scheme(Fn fun, Fn fun_prime) { set_fun_and_fun_prime(fun, fun_prime); }

Scheme::Scheme(Fn fun, Fn fun_prime, SchemeType scheme_t)
    : Scheme(fun, fun_prime) {
    set_scheme_t(scheme_t);
}

void Scheme::set_fun_and_fun_prime(Fn fun, Fn fun_prime) {
    this->fun = fun;
    this->fun_prime = fun_prime;
}

void Scheme::set_scheme_t(SchemeType scheme_t) { this->scheme_t = scheme_t; }

SchemeType Scheme::get_scheme_t() const { return scheme_t; }

Fn Scheme::get_fun() const { return fun; }

Fn Scheme::get_fun_prime() const { return fun_prime; }

MethodFn Scheme::method() const {
    MethodFn method;

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