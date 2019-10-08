#ifndef ACCURACY_H
#define ACCURACY_H

#include <map>
#include "aliases.h"
// TODO Norms for error rather than error for every single point.
class Accuracy {
   private:
    Dataset analytical_solution;
    Dataset numerical_solution;

    static double accuracy(double calculated, double analytical);

   public:
    Accuracy(Dataset analytical_solution, Dataset numerical_solution);
    static std::optional<Vector> compare(Vector numerical, Vector analytical);
    Dataset compute();
};

#endif  //ACCURACY_H