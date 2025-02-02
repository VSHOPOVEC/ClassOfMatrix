#include <vector>
#include <iostream>


class Matrix {
public:
	Matrix(std::vector<double> arr_massive, int rows, int columns);
	Matrix(bool identity_matrix, int rows, int columns);
	~Matrix();
	Matrix operator + (const Matrix& matrix);
	Matrix operator - (const Matrix& matrix);
	Matrix operator * (const Matrix& matrix);
	Matrix operator = (const Matrix& matrix);
	static double Determinant(const Matrix& matrix);
	void PrintMatrix();
private:
	int columns;
	int rows;
	double** matrix_arr;
	void CreateMatrixArr() {
		matrix_arr = new double* [rows];
		for (int i = 0; i < rows; ++i) {
			matrix_arr[i] = new double[columns];
		}
	}
};

Matrix::Matrix(std::vector<double> arr_massive, int rows, int columns)
{
	CreateMatrixArr();
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = arr_massive[i + columns * j];
		}
	}
}

Matrix::Matrix(bool identity_matrix, int rows, int columns) {
	CreateMatrixArr();
	switch (identity_matrix) {
	case true:
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				if (i == j) {
					matrix_arr[i][j] = 1;
				}
				else {
					matrix_arr[i][j] = 0;
				}
			}
		}
	case false:
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				std::cout << i << " " << j << std::endl;
				std::cin >> matrix_arr[i][j];
			}
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;
}

void Matrix::PrintMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << matrix_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}