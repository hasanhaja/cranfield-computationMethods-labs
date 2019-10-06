#ifndef ALIASES_H
#define ALIASES_H

#include <functional>
#include <map>
#include <vector>

using Vec = std::vector<double>;
using Fn = std::function<double(double)>;
using MethodFn = std::function<double(double, double)>;
using Dataset = std::map<double, Vec>;
using AccuracyDataset = std::map<double, double>;

#endif