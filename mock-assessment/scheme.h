#ifndef SCHEME_H
#define SCHEME_H

#include "aliases.h"

enum class SchemeType {
    Forward,
    Backward,
    Central,
};

class Scheme {
   private:
    Function fun;
    Function fun_prime;
    SchemeType scheme_t;

   public:
    Scheme();
    Scheme(Function fun, Function fun_prime);
    Scheme(Function fun, Function fun_prime, SchemeType scheme_t);
    void set_fun_and_fun_prime(Function fun, Function fun_prime);
    void set_scheme_t(SchemeType scheme_t);
    SchemeType get_scheme_t() const;
    Function get_fun() const;
    Function get_fun_prime() const;
    SchemeMethod method() const;

   protected:
    SchemeMethod forward_difference = [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };

    SchemeMethod backward_difference = [&](double x, double deltax) -> double {
        return (fun(x) - fun(x - deltax)) / deltax;
    };

    SchemeMethod central_difference = [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x - deltax)) / (deltax+deltax);
    };
};

#endif