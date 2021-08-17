#pragma once

namespace util {
  
void rand_seed(size_t seed);

// generate noise with uniform distribution. 
double urand(double min, double max);

// generate noise with normal distribution. 
double nrand(double ave, double sigma);

// generate noise with exponential distribution.
double erand(double lambda);

} // namespace util
