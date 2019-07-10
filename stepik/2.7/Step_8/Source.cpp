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

void free_matrix(int** m)
{
	delete[] m[0];
	delete[] m;
}

int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
	int** tmp_M = create_matrix(cols, rows);
	for (size_t i = 0; i != cols; ++i)
		for (size_t j = 0; j != rows; ++j)
			tmp_M[i][j] = m[j][i];
		
	return tmp_M;
}



int main()
{
	int** normal_M = create_matrix(3, 4);
	normal_M[0][0] = 1;
	normal_M[0][1] = 2;
	normal_M[0][2] = 3;
	normal_M[0][3] = 4;
	normal_M[1][0] = 5;
	normal_M[1][1] = 6;
	normal_M[1][2] = 7;
	normal_M[1][3] = 8;
	normal_M[2][0] = 9;
	normal_M[2][1] = 10;
	normal_M[2][2] = 11;
	normal_M[2][3] = 12;

	cout << "Normal Matrix:" << endl;
	for (size_t i = 0; i != 3; ++i) {
		for (size_t j = 0; j != 4; ++j) {
			cout << normal_M[i][j] << "  ";
		}
		cout << endl;
	}
	
	int** transpose_M = transpose(normal_M, 3, 4);

	cout << endl << "Transposed Matrix:" << endl;
	for (size_t i = 0; i != 4; ++i) {
		for (size_t j = 0; j != 3; ++j) {
			cout << transpose_M[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}