#include "include.hpp"

class Matrix {
private:
	class MatrixRow {
	public:
		MatrixRow(double* matrixRow) : matrixRow(matrixRow) {}

		double operator[](int index) {
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

	Matrix(std::vector<std::vector<double>> arr_massive);

	Matrix(bool identity_matrix, int rows, int columns);

	Matrix(int rows, int columns);

	Matrix(const Matrix& matrix);

	Matrix(); 

	~Matrix();

	Matrix operator + (const Matrix& matrix) const;

	Matrix operator - (const Matrix& matrix) const;

	Matrix operator - ()const; 

	Matrix operator * (const Matrix& matrix) const;

	Matrix& operator = (const Matrix& matrix);

	MatrixRow operator[](int index) {
		return MatrixRow(matrix_arr[index]);
	}
	Matrix& TransposeMatrix();

	void PrintMatrix();
private:

	int columns;

	int rows;

	double** matrix_arr;

	void CreateMatrixArr(int rows, int columns);

	size_t InvalidValueArray(const std::vector<std::vector<double>>& arr);
};
