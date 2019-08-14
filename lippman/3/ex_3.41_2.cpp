#include<iostream>
#include "vector"

using namespace std;
using std::vector;

int main()
{
  // Инициализация вектора массивом
  const int int_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> int_vec(begin(int_arr), end(int_arr));
  for (auto i : int_vec)
    cout << i << " ";

  cout << endl;

  // Копирование вектора в массив
  vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int iarr[10], counter = 0;
  for (auto i : ivec) {
    iarr[counter] = i;
    ++counter;
  }
  for (auto i : iarr)
    cout << i << " ";


  return 0;
}
