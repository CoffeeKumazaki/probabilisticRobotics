#pragma once

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
  double genUniform(float min, float max);
  double genGaussian(float ave, float sigma);

private:
  std::mt19937 rand;
};

