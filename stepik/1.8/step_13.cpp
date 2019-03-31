#include <iostream>
using namespace std;

int log2(int x)
{
  int rez = 0;
  int new_x = 2;
  while (new_x <= x) {
    new_x *= 2;
    rez++;
  }
  return rez;
}

int main()
{
  int n_tests = 0;
  int x = 0;

  cin >> n_tests;
  for (int i = 0; i < n_tests; i++) {
    cin >> x;

    cout << log2(x) << endl;
  }

	return 0;
}
