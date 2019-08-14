#include <iostream>
#include <cstring>

using namespace std;

int main() {

  //Конкатенация двух строк в стиле С
  const char c_s1[] = "This is how";
  const char c_s2[] = "ctrcpy() works";
  char c_s3[30];

  strcpy(c_s3, c_s1);
  strcat(c_s3, " ");
  strcat(c_s3, c_s2);

  const char *cp = c_s3;
  while (*cp) {
    cout << *cp;
    ++cp;
  }

  return 0;
}
