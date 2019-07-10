#include <iostream>
using namespace std;

char* resize(char* str, unsigned new_size)
{
	char* tmp_str = new char[new_size];
	for (unsigned i = 0; i < new_size; i++) {
		tmp_str[i] = str[i];
	}
	delete[] str;
	str = 0;
	return tmp_str;
}

char* getline()
{
	char* tmp_str = new char[1];
	char input_c;
	unsigned counter = 0;
	while (cin.get(input_c)) {
		tmp_str[counter] = input_c;
		counter++;
		tmp_str = resize(tmp_str, counter + 1);
	}
	
	tmp_str[counter] = '\0';
	return tmp_str;
}

int main()
{
	char* str = new char[1];
	str = getline();
	cout << str << endl;
	delete[] str;
}