#include <stdafx.hpp>
#include <util/gaussian.hpp>

namespace util
{

double gaussian(double x, double mean, double sigma) {
  return exp( 0.5 * (mean-x)*(mean-x) / sigma/sigma );
}

double gaussian2D(const Eigen::VectorXd& x, const Eigen::VectorXd& mean, const Eigen::MatrixXd& cov) {
 
  double n = x.rows();
  double sqrt2pi = std::sqrt(2 * M_PI);
  double quadform  = (x - mean).transpose() * cov.inverse() * (x - mean);
  double norm = std::pow(sqrt2pi, - n) *
                std::pow(cov.determinant(), - 0.5);

  return exp(-0.5 * quadform);
}

} // namespace util
