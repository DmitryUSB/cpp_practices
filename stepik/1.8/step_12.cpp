#include <iostream>
using namespace std;

int main()
{
    /* ... */

    char c = '\0';
    int space = 0;
    while (cin.get(c)) {
        if (c == ' ') { space = 1; }
        else if (space) {
          cout << " " << c;
          space = 0;
        }
        else cout << c;
    }

	return 0;
}
