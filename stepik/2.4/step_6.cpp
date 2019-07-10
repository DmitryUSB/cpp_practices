#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
/* unsigned len = 0;
for (; str; str++) {
  if (*str == '\0') break;
   len++;
 }
 return len;*/

 unsigned size = 0;
     while (*str++) {
         ++size;
     }
     return size;

}

int main()
{
const char str[13] = {"Hello Wolrd!"};
//cin >> str;

//or (auto i : str)
  cout << strlen(str);

  return 0;
}
