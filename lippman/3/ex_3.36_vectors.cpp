#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

int main()
{
  vector<int> ivec1 = {1,2,3,4,5,6,7,8,9,10};

  vector<int> ivec2 = {1,2,3,4,5,6,7,8,9,10};


  if (ivec1 == ivec2) std::cout << "Vectors is equal!" << '\n';
  else std::cout << "Vecotrs isn't equal!" << '\n';



}
