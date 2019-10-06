#ifndef ACCURACY_H
#define ACCURACY_H

#include <map>
#include "aliases.h"

class Accuracy {
   private:
    Dataset analytical_solution;
    Dataset numerical_solution;

    double accuracy(double calculated, double analytical);

   public:
    Accuracy(Dataset analytical_solution, Dataset numerical_solution);
    AccuracyDataset solution_accuracy();
};

#endif