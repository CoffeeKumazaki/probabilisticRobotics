#pragma once

namespace util {

  double gaussian(double x, double mean, double sigma);
  double gaussian2D(const Eigen::VectorXd& x, const Eigen::VectorXd& mean, const Eigen::MatrixXd& cov);

}
