#include <vector>
#include <iostream>
#include <string>
#include <cmath>

class Matrix {
private:
	class MatrixRow {
	public:
		MatrixRow(double* matrixRow) : matrixRow(matrixRow) {}

		double& operator[](int index) {
			return matrixRow[index];
		}
	private:
		double* matrixRow;
	};

	class Error {
	public:
		Error(std::string message) : message(message) {
			std::cout << GetMessage() << std::endl;
		};
		std::string GetMessage() { return message; }
	private:
		std::string message;
	};

public:

	Matrix(std::vector<std::vector<double>> arr_massive, int rows, int columns);

	Matrix(bool identity_matrix, int rows, int columns);

	Matrix(int rows, int columns);

	Matrix(Matrix const& matrix);

	~Matrix();

	Matrix operator + (const Matrix& matrix) const;

	Matrix operator - (const Matrix& matrix) const;

	Matrix operator - ()const; 

	Matrix operator * (const Matrix& matrix) const;

	Matrix* operator = (const Matrix& matrix);

	MatrixRow* operator[](int index) {
		MatrixRow curr_Row = MatrixRow(matrix_arr[index]);
		return &curr_Row;
	}

	Matrix* TransposeMatrix();

	void PrintMatrix();

private:

	int columns;

	int rows;

	double** matrix_arr;

	void CreateMatrixArr(int rows, int columns);

	void InvalidValueArray(int rows, int columns, const std::vector<std::vector<double>>& arr);

	void InvalidValueArray(int rows, int columns);
};
