#include <iostream>

using namespace std;

int main() {
  const char ca[] = {'h','e','l','l','o','\0'};
  const char *cp = ca;
  // выводит каждый символ строки, если нет нулевого символа,
  // то выводит мусор
  while (*cp) {
    cout << *cp << endl;
    ++cp;
  }
  return 0;
}
