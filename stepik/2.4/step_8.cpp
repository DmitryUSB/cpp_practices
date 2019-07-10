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

int strstrMY(const char *text, const char *pattern)
{
  const char *text_in = 0;
  const char *pattern_in = 0;
  unsigned pos = 0;
  unsigned pos_in = 0;
  unsigned pat_len = strlen(pattern);
  //cout << pat_len << endl;
  if (*text == *pattern && *text == 0 || *pattern == 0) return 0;
  while (*text) {
      //cout << pos << " " << *text << endl;

      if (*text == *pattern) {
        text_in = text;
        pattern_in = pattern;
        for (; *pattern_in != '\0'; pattern_in++) {
          //cout << " inside " << pos_in << " " << *pattern_in << endl;
          if (*text_in == *pattern_in) pos_in++;
          else break;
          if (pos_in == pat_len) return pos;
          //cout << "  inside " << *text_in << endl;
          //cout << "  inside " << *pattern_in << endl;
          text_in++;
        }
      }
      pos_in = 0;
      text++;
      pos++;
  }
  return -1;
}

int main()
{
  cout << strstrMY("aa","");
  //return 0;
}
