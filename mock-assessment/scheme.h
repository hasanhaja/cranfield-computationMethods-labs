#include <functional>

#ifndef SCHEME_H
#define SCHEME_H

enum class SchemeType {
    Forward,
    Backward,
    Central,
};

class Scheme {
   private:
    std::function<double(double)> fun;
    std::function<double(double)> fun_prime;
    double deltax;
    SchemeType scheme_t;

   public:
    Scheme();
    Scheme(std::function<double(double)> fun,
           std::function<double(double)> fun_prime);
    Scheme(std::function<double(double)> fun,
           std::function<double(double)> fun_prime, double deltax,
           SchemeType scheme_t);

    void set_deltax(double deltax);
    void set_fun_and_fun_prime(std::function<double(double)> fun,
                               std::function<double(double)> fun_prime);
    void set_scheme_t(SchemeType scheme_t);

    double get_deltax() const;
    SchemeType get_schemeType() const;

    std::function<double(double)> get_fun();
    std::function<double(double)> get_fun_prime();

    std::function<double(double, double)> method();

   protected:
    std::function<double(double, double)> forward_difference =
        [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };

    std::function<double(double, double)> backward_difference =
        [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };

    std::function<double(double, double)> central_difference =
        [&](double x, double deltax) -> double {
        return (fun(x + deltax) - fun(x)) / deltax;
    };
};

#endif