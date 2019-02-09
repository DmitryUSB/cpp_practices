#include <iostream>
#include <string>
#include <cstddef>
#include <vector>

using namespace std;
using std::vector;

int main()
{
  // Присвоение каждому эелементу массива значение его позиции в массиве
  constexpr size_t arr_size = 10;
  int ia[arr_size];
  int copy_ia[arr_size];
  for (size_t ix = 0; ix < arr_size; ++ix)
    ia[ix] = ix;
  // Выводим результат
  cout << "Arr of elemet's pos: ";
  for (auto i : ia)
    cout << i << " ";
  cout << endl;

  // Копирование массива ia
  for (auto i : ia)
    copy_ia[i] = i;
  // Выводим результат
  cout << "Copy of ia: ";
  for (auto i : copy_ia)
    cout << i << " ";
  cout << endl;
//-------------------------------------------------------------------------
  // Тоже самое тоько с векторами
  // Присвоение каждому эелементу вектора значение его позиции в векторе
  vector<unsigned> un_vec(10);
  vector<unsigned> copy_un_vec(10);
  for (auto it = un_vec.begin(); it != un_vec.end(); ++it)
    *it = distance(un_vec.begin(), it);
  // Выводим результат
  cout << "Vec of elemet's pos: ";
  for (auto ivec :   un_vec)
      cout << ivec << " ";
  cout << endl;

  // Копирование вектора un_vec
  copy_un_vec = un_vec;
  // Выводим результат
  cout << "Copy of un_vec: ";
  for (auto ivec :   copy_un_vec)
      cout << ivec << " ";
}
