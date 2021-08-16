#include <stdafx.hpp>
#include <util/random.hpp>

RandomGenerator::RandomGenerator() {

  rand.seed(static_cast<unsigned int>(time(nullptr)));
}

RandomGenerator::~RandomGenerator() {

}

void RandomGenerator::setSeed(size_t seed) {

  rand.seed(seed);
}

double RandomGenerator::genUniform(float min, float max) {

  std::uniform_real_distribution<double> dist(min, max);
  return dist(rand);
}

double RandomGenerator::genGaussian(float ave, float sigma) {

  std::normal_distribution<double> dist(ave, sigma);
  return dist(rand);   
}

