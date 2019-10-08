#ifndef ALIASES_H
#define ALIASES_H

#include <functional>
#include <map>
#include <vector>
#include "solutiontype.h"

using Vector = std::vector<double>;
using Function = std::function<double(double)>;
using SolutionMethod = std::function<Vector(double, SolutionType)>;
using SchemeMethod = std::function<double(double, double)>;
using Dataset = std::map<double, Vector>;
using AccuracyDataset = std::map<double, double>;

#endif //ALIASES_H