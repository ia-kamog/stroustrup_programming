#ifndef STAT_H_
#define STAT_H_
#include <vector>

struct Stat_desc {
     double min, max, mean, median;
};

Stat_desc get_stat_desc(std::vector<double> d);
#endif
