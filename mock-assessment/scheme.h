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
    double x;
    double deltax;
    SchemeType scheme;

   public:
    Scheme(std::function<double(double)> fun,
           std::function<double(double)> fun_prime);
    Scheme(std::function<double(double)> fun,
           std::function<double(double)> fun_prime, double x, double deltax, SchemeType scheme);

    void set_x_and_deltax(double x, double deltax);
    
    std::function<double(double, double)> method();

    // Perhaps this could be private or protected? Protected makes sense
    double forward_difference(double x, double deltax) const;
    double backward_difference(double x, double deltax) const;
    double central_difference(double x, double deltax) const;
};

#endif