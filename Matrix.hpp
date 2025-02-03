#include <vector>
#include <iostream>
#include <string>
#include <cmath>

class InvalidSizeOfArray {
public:
	InvalidSizeOfArray(std::string message) : message(message) {
		std::cout << GetMessage() << std::endl;
	};
	std::string GetMessage() { return message; }
private:
	std::string message;
};

class InvalidSizeOfMatrix {
public:
	InvalidSizeOfMatrix(std::string message) : message(message) {
		std::cout << GetMessage() << std::endl; 
	}; 
	std::string GetMessage() { return message; }
private:
	std::string message; 
};

class InvalidValue {
public:
	InvalidValue(std::string message) : message(message) {
		std::cout << GetMessage() << std::endl;
	};
	std::string GetMessage() { return message; }
private:
	std::string message;
};

class Matrix {
public:
	Matrix(std::vector<std::vector<double>> arr_massive, int rows, int columns);
	Matrix(bool identity_matrix, int rows, int columns);
	Matrix(int rows, int columns);
	~Matrix();
	Matrix operator + (const Matrix& matrix) const;
	Matrix operator - (const Matrix& matrix) const;
	Matrix operator - ()const; 
	Matrix operator * (const Matrix& matrix) const;
	Matrix& operator = (const Matrix& matrix);
	//static double Determinant(const Matrix& matrix);
	void PrintMatrix();
private:
	int columns;
	int rows;
	double** matrix_arr;
	void CreateMatrixArr(int rows, int columns) {
		matrix_arr = new double* [rows];
		for (int i = 0; i < rows; ++i) {
			matrix_arr[i] = new double[columns];
		}
	}
	void ErrorInvalidValue(int rows, int columns){
		if (rows <= 0 || columns <= 0) {
			throw InvalidValue("Colums and Rows can't be a negative number");
		}
	}
	void ErrorInvalidSizeOfArray(int rows, int columns, const std::vector<std::vector<double>>& arr) {
		int arr_size = arr.size(); 
		if (arr_size == rows) {
			int k = 0; 
			for (int i = 0; i < arr_size; ++i) {
				if (arr[i].size() != columns) {
					k += 1; 
				}
			}
			if (k != 0) {
				throw InvalidSizeOfArray("Invalid size of columns"); 
			}
		}
		else {
			throw InvalidSizeOfArray("Invalid size of rows"); 
		}
	}
};

Matrix::Matrix(std::vector<std::vector<double>> arr_massive, int rows, int columns):rows(rows), columns(columns)
{
	ErrorInvalidValue(this->rows, this->columns); 
	ErrorInvalidSizeOfArray(this->rows, this->columns, arr_massive); 
	CreateMatrixArr(this->rows, this-> columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = arr_massive[i][j];
		}
	}
}

Matrix::Matrix(bool identity_matrix, int rows, int columns):rows(rows), columns(columns){
	ErrorInvalidValue(this->rows, this->columns);
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
	else{
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				std::cout << i << " " << j << std::endl;
				std::cin >> matrix_arr[i][j];
			}
		}
	}
}

Matrix::Matrix(int rows, int columns):rows(rows), columns(columns)
{
	ErrorInvalidValue(this->rows, this->columns);
	CreateMatrixArr(this->rows, this->columns); 
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = 0; 
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;
}

Matrix Matrix::operator+(const Matrix& matrix) const
{
	if (matrix.columns != this->columns && matrix.rows != this->rows) {
		throw InvalidSizeOfMatrix("Invalid size of Matrix"); 
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
		throw InvalidSizeOfMatrix("Invalid size of Matrix");
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
		throw InvalidSizeOfMatrix("Invalid size of Matrix");
	}
	else {
		Matrix result(this->rows, matrix.columns);
		for (int k = 0; k < this->rows; ++k) {
			for (int i = 0; i < matrix.columns; ++i) {
				for (int j = 0; j < this->columns; ++j){
					result.matrix_arr[k][i] += (this->matrix_arr[k][j]) * matrix.matrix_arr[j][i];
				}
			}
		}
		return result; 
	}
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (matrix.rows != this->rows || matrix.columns != this->columns) {
		throw InvalidSizeOfMatrix("Invalid size of Matrix");
	}
	else {
		for (int i = 0; i < matrix.rows; ++i) {
			for (int j = 0; j < matrix.columns; ++j) {
				this->matrix_arr[i][j] = matrix.matrix_arr[i][j]; 
			}
		}
		return *this;
	}
}

//double Matrix::Determinant(const Matrix& matrix)
//{
//	double Det = 0;
//	for (int i = 0; i < matrix.columns; ++i) {
//		matrix.matrix_arr[0][i] * pow(-1, i)*
//	}
//}

void Matrix::PrintMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << matrix_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}