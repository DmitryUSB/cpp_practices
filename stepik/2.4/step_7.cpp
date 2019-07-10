#include <iostream>
using namespace std;
unsigned strlen(const char *str)
{
 unsigned size = 0;
     while (*str++) {
         ++size;
     }
     return size;
}

void strcatMY(char *to, const char *from)
{
    int counter = 0;
     for (; *from != '\0'; *from++) {
       cout << counter << " before " << strlen(to) << endl;

       *(to + strlen(to)) = *from;

       cout << counter << " after " << strlen(to) << endl;
       //from++;
       counter++;

     }
     //if (*(to + strlen(to) + 2) == '\0') cout << "Yes_bef" << endl;


}

int main()
{
  char str1[7] = {"abc"};
  const char str2[4]= {"DEF"};
  strcatMY(str1,str2);

  cout << str1 << endl;
  cout << strlen(str1);
  return 0;
}
