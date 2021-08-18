#pragma once

struct ObservedData
{
  std::string sensorName;
  size_t timeStamp;
  double dis = 0.0; // distance
  double dir = 0.0; // direction
  double disErr = 0.0; 
  double dirErr = 0.0;
};

using OBS_PTR = std::shared_ptr<ObservedData>;
using LOBS = std::list<OBS_PTR>;