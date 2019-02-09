#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;
using std::vector;

int main()
{
vector<int> ivec;
int c_int;
cout << "Enter some sequence of numbers (type of int, use dot to confirm): " << endl;
while (cin >> c_int)
	ivec.push_back(c_int);
cout << "Source sequence: ";
for (auto i : ivec)
	cout << i << " ";
cout << endl;
int neigh_summ = 0, first_last_summ = 0;

//Neigh summ
cout << "Summ of two neighbours: ";
for (auto it = ivec.cbegin() + 1; it != ivec.cend() - 1; ++it){
	neigh_summ = *(it - 1) + *(it + 1);
	cout << neigh_summ << " ";
	}

//First and last summ
cout << endl << "Summ first and last: ";
int counter_i = 0;
for (auto it = ivec.cbegin(); it != ivec.cend(); ++it){
	first_last_summ = *(it) + *(ivec.cend() - (1+counter_i));
	cout << first_last_summ << " ";
	counter_i++;
	}
cout << endl;
}
