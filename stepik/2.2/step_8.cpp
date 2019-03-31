#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd (b, a % b);
}

int main()
{
  unsigned a;
  unsigned b;
  cin >> a >> b;
  cout << gcd(a,b) << endl;
	return 0;
}
