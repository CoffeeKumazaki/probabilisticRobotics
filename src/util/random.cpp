#include <stdafx.hpp>
#include <util/random.hpp>

class RandomGenerator {

public:
  static RandomGenerator& getInstance() {
    static RandomGenerator instance;
    return instance;
  }

private:
  RandomGenerator();
  ~RandomGenerator();

public:
  void setSeed(size_t seed);
  double genUniform(double min, double max);
  double genGaussian(double ave, double sigma);

private:
  std::mt19937 rand;
};

RandomGenerator::RandomGenerator() {

  rand.seed(static_cast<unsigned int>(time(nullptr)));
}

RandomGenerator::~RandomGenerator() {

}

void RandomGenerator::setSeed(size_t seed) {

  rand.seed(seed);
}

double RandomGenerator::genUniform(double min, double max) {

  std::uniform_real_distribution<double> dist(min, max);
  return dist(rand);
}

double RandomGenerator::genGaussian(double ave, double sigma) {

  std::normal_distribution<double> dist(ave, sigma);
  return dist(rand);   
}

namespace util
{

void rand_seed(size_t seed) {

  RandomGenerator::getInstance().setSeed(seed);
}

double urand(double min, double max) {

  return RandomGenerator::getInstance().genUniform(min, max);
}

double nrand(double ave, double sigma) {

  return RandomGenerator::getInstance().genGaussian(ave, sigma);
}

} // namespace util
