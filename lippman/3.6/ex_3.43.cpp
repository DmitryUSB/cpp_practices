#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	
	cout << "1. Using serial for:" << endl;
	
	for (int(&row)[4] : ia) { // row - ссылка на массив из 4-х целых чисел
		for (int col: row) // для каждого элемента массива на который ссылается row 
			cout << col << "  "; // выводим элемент
		cout << endl;
	}
	
	cout << endl << "2. Using index:" << endl;
	size_t row = 3;
	size_t col = 4;
	for (size_t i = 0; i < row; ++i) { // для каждого ряда массива ia
		for (size_t j = 0; j < col; ++j) // для каждого столбца в ряду 
			cout << ia[i][j] << "  ";
		cout << endl;
	}
	
	cout << endl << "3. Using pointers:" << endl;
	for (int(*ip)[4] = ia; ip != ia + 3; ++ip) { // ip - указатель на массив из 4-х целых чисел, "= ia" иницаилизция адресом первого массива в массиве ia
		// jp - указатель на первый элемент массива из 4-х целых чисел (указатель на int)
		for (int* jp = *ip; jp != *ip + 4; ++jp)  // *ip - результат массив из четырех целых чисел, преобразуется в указатель на его первый элемент
			cout << *jp << "  ";
		cout << endl;
	}
	
		
	return 1;
}
