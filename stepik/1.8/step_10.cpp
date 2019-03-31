#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int a, b, c;
  double diskr;
  cin >> a >> b >> c;

  diskr = b*b - 4*a*c;

  if (diskr == 0) cout << -b/(2*a) << " " << -b/(2*a) << endl;
  else if (diskr > 0) cout << (-b + sqrt(diskr))/(2*a) << " " << (-b - sqrt(diskr))/(2*a) << endl;
  else cout << "No real roots" << endl;
  return 0;
}
