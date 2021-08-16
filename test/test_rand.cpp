#include <stdafx.hpp>
#include <util/random.hpp>

int main(int argc, char const *argv[])
{
  
  util::rand_seed(100);

  for (size_t i = 0; i < 10; i++)
  {
    std::cout << util::urand(0, 10.0) << std::endl;
  }
  
  return 0;
}
