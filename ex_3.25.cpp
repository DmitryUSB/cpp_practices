#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;
using std::vector;

int main()
{
  vector<unsigned> scores(11,0);
  unsigned grade;
  vector<unsigned>::iterator it;
  while (cin >> grade) {
    if (grade <= 100) {                 // читаем только допустимые оценки (от 0 до 100)
      it = scores.begin() + grade/10;   // определяем новое значение итератора
      ++(*it);                          // увеличиваем счётчик оценки, обозначенной итератором it
    }
  }
  for (auto sc : scores)                //выводим все элементы веткора scores
    cout << sc << " ";
  cout << endl;
}
