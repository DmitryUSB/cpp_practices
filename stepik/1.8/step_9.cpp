#include <iostream>

using namespace std;

int main()
{
  int n_tests = 0;
  int x1 = 0;
  int x2 = 0;

  cin >> n_tests;
  for (int i = 0; i < n_tests; i++) {
    cin >> x1 >> x2;
    cout << x1 + x2 << endl;
  }
  return 0;
}
