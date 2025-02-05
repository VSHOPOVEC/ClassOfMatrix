#include "Matrix.hpp"


class Error;

//Constructors Matrix
Matrix::Matrix(std::vector<std::vector<double>> arr_massive, int rows, int columns) :rows(rows), columns(columns)
{
	InvalidValueArray(this->rows, this->columns, arr_massive);
	CreateMatrixArr(this->rows, this->columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = arr_massive[i][j];
		}
	}
}

Matrix::Matrix(bool identity_matrix = true, int rows = 3, int columns = 3) :rows(rows), columns(columns) {
	InvalidValueArray(this->rows, this->columns);
	CreateMatrixArr(this->rows, this->columns);
	if (identity_matrix == true) {
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
	}
	else {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				std::cout << i << " " << j << std::endl;
				std::cin >> matrix_arr[i][j];
			}
		}
	}
}

Matrix::Matrix(int rows, int columns) :rows(rows), columns(columns)
{
	InvalidValueArray(this->rows, this->columns);
	CreateMatrixArr(this->rows, this->columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = 0;
		}
	}
}

Matrix::Matrix(Matrix const& matrix) :rows(matrix.rows), columns(matrix.columns)
{
	InvalidValueArray(rows, columns);
	CreateMatrixArr(rows, columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			this->matrix_arr[i][j] = matrix.matrix_arr[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;
}


//Operators Matrix 
Matrix Matrix::operator+(const Matrix& matrix) const
{
	if (matrix.columns != this->columns && matrix.rows != this->rows) {
		throw Error("Invalid size of Matrix");
	}
	else {
		Matrix result(matrix.rows, matrix.columns);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				result.matrix_arr[i][j] = this->matrix_arr[i][j] + matrix.matrix_arr[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator-(const Matrix& matrix) const
{
	if (matrix.columns != this->columns && matrix.rows != this->rows) {
		throw Matrix::Error("Invalid size of Matrix");
	}
	else {
		Matrix result(matrix.rows, matrix.columns);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				result.matrix_arr[i][j] = this->matrix_arr[i][j] - matrix.matrix_arr[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::operator-() const
{
	Matrix result(this->rows, this->columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			result.matrix_arr[i][j] = (this->matrix_arr[i][j]) * (-1);
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
	if (matrix.rows != this->columns || matrix.columns != this->rows) {
		throw Matrix::Error("Invalid size of Matrix");
	}
	else {
		Matrix result(this->rows, matrix.columns);
		for (int k = 0; k < this->rows; ++k) {
			for (int i = 0; i < matrix.columns; ++i) {
				for (int j = 0; j < this->columns; ++j) {
					result.matrix_arr[k][i] += (this->matrix_arr[k][j]) * matrix.matrix_arr[j][i];
				}
			}
		}
		return result;
	}
}

Matrix* Matrix::operator=(const Matrix& matrix)
{
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;
	matrix_arr = new double* [matrix.rows];
	columns = matrix.columns;
	rows = matrix.rows;
	for (int i = 0; i < rows; ++i) {
		matrix_arr[i] = new double[columns];
	}
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = matrix.matrix_arr[i][j];
		}
	}

	return this;



	//Версия оператора присваивания для матриц одного размера
	/*if (matrix.rows != this->rows || matrix.columns != this->columns) {
		throw MatrixError::InvalidSizeOfMatrix("Invalid size of Matrix");
	}
	else {
		for (int i = 0; i < matrix.rows; ++i) {
			for (int j = 0; j < matrix.columns; ++j) {
				this->matrix_arr[i][j] = matrix.matrix_arr[i][j];
			}
		}
		return *this;
	}*/
}

//Methods of class Matrix

void Matrix::PrintMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << matrix_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix* Matrix::TransposeMatrix()
{
	Matrix result(*this);
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;

	int temp_rows = rows;

	matrix_arr = new double* [columns];
	for (int i = 0; i < columns; ++i) {
		matrix_arr[i] = new double[rows];
	}

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->columns; ++j) {
			matrix_arr[j][i] = result.matrix_arr[i][j];
		}
	}
	rows = columns; columns = temp_rows;
	return this;
}

void Matrix::CreateMatrixArr(int rows, int columns)
{
	matrix_arr = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix_arr[i] = new double[columns];
	}
}

void Matrix::InvalidValueArray(int rows, int columns)
{
	if ((rows <= 0) || (columns <= 0)) {
		throw Matrix::Error("Colums and Rows can't be a negative number");
	}
}

void Matrix::InvalidValueArray(int rows, int columns, const std::vector<std::vector<double>>& arr) //Используется исключительно в конструкторе 
{
	int arr_size = int(arr.size());
	if ((rows <= 0) || (columns <= 0)) {
		throw Matrix::Error("Colums and Rows can't be a negative number");
	}
	else {
		if (arr_size == rows) {
			int k = 0;
			for (int i = 0; i < arr_size; ++i) {
				if (arr[i].size() != columns) {
					k += 1;
				}
			}
			if (k != 0) {
				throw Matrix::Error("Invalid size of columns");
			}
		}
		else {
			throw Matrix::Error("Invalid size of rows");
		}
	}
}


