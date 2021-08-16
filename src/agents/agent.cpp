#include <stdafx.hpp>
#include <agents/agent.hpp>

Agent::Agent(std::shared_ptr<IdealRobot> p)
: parent(p)
{
}

Agent::~Agent() 
{
}

Agent::Input Agent::decision() {

  Input input;
  input.vx = 10.0;
  input.yawRate = M_PI/10.0;
  return input;
}
