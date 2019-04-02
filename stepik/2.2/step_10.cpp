#include <iostream>
using namespace std;

void rec()
{
  unsigned in;
  cin >> in;
  if (in == 0) return;
  rec();
  cout << in << " ";
}

int main()
{
  rec();
	return 0;
}
