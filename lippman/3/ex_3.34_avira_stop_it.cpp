#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
  int ia[] = {1,2,3,4,5,6,7,8,9,10};
  int *p = begin(ia), *p_aft_last = end(ia);
  //обнуляем массив ia
  while (p < p_aft_last) {
    std::cout << *p << '\n';
    *p = 0;
    std::cout << *p << '\n';
    ++p;
  }
}
