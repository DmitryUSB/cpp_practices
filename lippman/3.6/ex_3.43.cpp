#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
  int ia1[] = {1,2,3,4,5,6,7,8,9,10};
  int *p1 = ia1, *p1_aft_last = end(ia1);
  int ia2[] = {1,2,3,4,5,6,7,8,9,10};
  int *p2 = ia2, step = 0;

  if (size(ia1) == size(ia2)) {
    std::cout << "Sizes is equal.." << '\n';
    while (p1 < p1_aft_last) {
      if (*p1 == *p2){
        std::cout << "ia1[" << step << "] == ia2[" << step << "]" << '\n';
        ++p1;
        ++p2;
        ++step;
      }
      else {
        std::cout << "ia1[" << step << "] != ia2[" << step << "]" << '\n';
        std::cout << "Arrays isn't equal!" << '\n';
        break;
      }
    }
  } else std::cout << "Sizes isn't equal!" << '\n';



}
