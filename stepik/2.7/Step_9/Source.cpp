#include <iostream>;

using namespace std;

int** create_matrix(size_t rows, size_t cols)
{
	int** m = new int* [rows];
	m[0] = new int[rows * cols];
	for (size_t i = 1; i != rows; ++i)
		m[i] = m[i - 1] + cols;

	return m;
}

void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int* pos = m[0];
/*	m[0] = m[2];
	m[2] = pos; */
	int row_with_min;
	int min_val = 999;
	int min_val_tmp;

	for (int i = 0; i < rows; ++i) {
		min_val_tmp = m[i][0];
		for (int j = 1; j < cols; ++j) {
			if (min_val_tmp < m[i][j]) continue;
			else min_val_tmp = m[i][j];
		}
		cout << "[" << i << "] min val: " << min_val_tmp << endl;

		if (min_val_tmp < min_val) {
			min_val = min_val_tmp;
			row_with_min = i;
		}
		else continue;
	}
	m[0] = m[row_with_min];
	m[row_with_min] = pos;

	cout << endl << min_val << " in row " << row_with_min;
}

int main() 
{
	int t[] = { 10, 20, 30, 40, 50, 50, 60, 70, 80, 90 };
	int* pt = t;
	int sum = 0;
	for (; pt = t; pt++) {
		sum += *pt;
	}

	int** normal_M = create_matrix(3, 4);
	normal_M[0][0] = 5;
	normal_M[0][1] = 4;
	normal_M[0][2] = 4;
	normal_M[0][3] = 4;
	normal_M[1][0] = 4;
	normal_M[1][1] = 1;
	normal_M[1][2] = 3;
	normal_M[1][3] = 3;
	normal_M[2][0] = 2;
	normal_M[2][1] = 5;
	normal_M[2][2] = 6;
	normal_M[2][3] = 5;

	cout << "Normal Matrix:" << endl;
	for (size_t i = 0; i != 3; ++i) {
		for (size_t j = 0; j != 4; ++j) {
			cout << normal_M[i][j] << "  ";
		}
		cout << endl;
	}

	swap_min(normal_M, 3, 4);

	cout << endl << "After swap_min:" << endl;
	for (size_t i = 0; i != 3; ++i) {
		for (size_t j = 0; j != 4; ++j) {
			cout << normal_M[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}