#pragma once

#include <stdafx.hpp>

struct Pos2D {
  double x = 0;
  double y = 0;
  double theta = 0;

  Pos2D(double _x = 0, double _y = 0, double _t = 0) {
    x = _x; y = _y; theta = _t;
  }
};

using VPOS = std::vector<Pos2D>;
using VPOS_IT = std::vector<Pos2D>::iterator;
using VPOS_CIT = std::vector<Pos2D>::const_iterator;
using LPOS = std::list<Pos2D>;
using LPOS_IT = std::list<Pos2D>::iterator;
using LPOS_CIT = std::list<Pos2D>::const_iterator;

struct Size2D {
  double w = 0;
  double h = 0;

  Size2D(double _w = 0, double _h = 0) {
    w = _w; h = _h;
  }
};
