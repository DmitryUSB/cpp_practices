#include <iostream>
using namespace std;

void rotate(int a[], unsigned size, int shift)
{
	int tmp = 0;
	int* beg = a;
	int* last = &a[size]-1;
	tmp = *(last - shift);
	a[size-1-shift] = *last;
}

int main()
{
  int M[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto k:M) cout << k << " ";
  rotate(M, 10, 2);
  cout << endl;
  for (auto k:M) cout << k << " ";
  //int* p = &M[size(M)-1];
  //cout << *p;
  return 0;
}