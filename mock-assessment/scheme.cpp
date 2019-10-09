#include "scheme.h"

Scheme::Scheme() {}

Scheme::Scheme(Function fun, Function fun_prime) { set_fun_and_fun_prime(fun, fun_prime); }

Scheme::Scheme(Function fun, Function fun_prime, SchemeType scheme_t)
    : Scheme(std::move(fun), std::move(fun_prime)) {
    set_scheme_t(scheme_t);
}

void Scheme::set_fun_and_fun_prime(Function fun, Function fun_prime) {
    this->fun = fun;
    this->fun_prime = fun_prime;
}

void Scheme::set_scheme_t(SchemeType scheme_t) { this->scheme_t = scheme_t; }

SchemeMethod Scheme::method() const {
    SchemeMethod method;

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

SchemeMethod Scheme::analytical() const {
    return _analytical;
}