#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	
	cout << "1. Using serial for:" << endl;
	
	for (int(&row)[4] : ia) { // row - ������ �� ������ �� 4-� ����� �����
		for (int col: row) // ��� ������� �������� ������� �� ������� ��������� row 
			cout << col << "  "; // ������� �������
		cout << endl;
	}
	
	cout << endl << "2. Using index:" << endl;
	size_t row = 3;
	size_t col = 4;
	for (size_t i = 0; i < row; ++i) { // ��� ������� ���� ������� ia
		for (size_t j = 0; j < col; ++j) // ��� ������� ������� � ���� 
			cout << ia[i][j] << "  ";
		cout << endl;
	}
	
	cout << endl << "3. Using pointers:" << endl;
	for (int(*ip)[4] = ia; ip != ia + 3; ++ip) { // ip - ��������� �� ������ �� 4-� ����� �����, "= ia" ������������ ������� ������� ������� � ������� ia
		// jp - ��������� �� ������ ������� ������� �� 4-� ����� ����� (��������� �� int)
		for (int* jp = *ip; jp != *ip + 4; ++jp)  // *ip - ��������� ������ �� ������� ����� �����, ������������� � ��������� �� ��� ������ �������
			cout << *jp << "  ";
		cout << endl;
	}
	
		
	return 1;
}
