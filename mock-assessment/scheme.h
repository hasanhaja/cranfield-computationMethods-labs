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
    Fn fun;
    Fn fun_prime;
    SchemeType scheme_t;

   public:
    Scheme();
    Scheme(Fn fun, Fn fun_prime);
    Scheme(Fn fun, Fn fun_prime, SchemeType scheme_t);
    void set_deltax(double deltax);
    void set_fun_and_fun_prime(Fn fun, Fn fun_prime);
    void set_scheme_t(SchemeType scheme_t);
    SchemeType get_scheme_t() const;
    Fn get_fun() const;
    Fn get_fun_prime() const;
    MethodFn method() const;

   protected:
    MethodFn forward_difference = [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };

    MethodFn backward_difference = [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };

    MethodFn central_difference = [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };
};

#endif