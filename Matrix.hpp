#include "include.hpp"

template <typename T>
class Matrix {
private:

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

	Matrix(std::vector<std::vector<T>> arr_massive);

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

	T* operator[](int index);

	Matrix& TransposeMatrix();

	void PrintMatrix();
private:

	int columns;

	int rows;

	T** matrix_arr;

	void CreateMatrixArr(int rows, int columns);

	size_t InvalidValueArray(const std::vector<std::vector<T>>& arr);
};



class Error;
//Constructors Matrix
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> arr_massive)
{
	size_t rowsSize = arr_massive.size();
	size_t columnsSize = InvalidValueArray(arr_massive);
	rows = static_cast<int>(rowsSize); columns = static_cast<int>(columnsSize);
	CreateMatrixArr(rows, columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = arr_massive[i][j];
		}
	}
}

template <typename T>
Matrix<T>::Matrix(bool identity_matrix, int rows, int columns) :rows(static_cast<int>(fabs(rows))), columns(static_cast<int>(fabs(rows))) {
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

template <typename T>
Matrix<T>::Matrix(int rows, int columns) :rows(static_cast<int>(fabs(rows))), columns(static_cast<int>(fabs(columns)))
{
	CreateMatrixArr(this->rows,this->columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			matrix_arr[i][j] = 0;
		}
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix const& matrix) :rows(matrix.rows), columns(matrix.columns)
{
	CreateMatrixArr(rows, columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			this->matrix_arr[i][j] = matrix.matrix_arr[i][j];
		}
	}
}

template <typename T>
Matrix<T>::Matrix() :rows(3), columns(3)
{
	CreateMatrixArr(this->rows, this->columns);
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

template <typename T>
Matrix<T>::~Matrix<T>() {
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;
}


//Operators Matrix 
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& matrix) const
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

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& matrix) const
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

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix result(this->rows, this->columns);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			result.matrix_arr[i][j] = (this->matrix_arr[i][j]) * (-1);
		}
	}
	return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& matrix) const
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

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& matrix)
{
		for (int i = 0; i < rows; ++i) {
			delete[] matrix_arr[i];
		}
		delete[] matrix_arr;
		matrix_arr = new T * [matrix.rows];
		columns = matrix.columns;
		rows = matrix.rows;
		CreateMatrixArr(rows, columns);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				matrix_arr[i][j] = matrix.matrix_arr[i][j];
			}
		}
	return *this;
}

template<typename T>
T* Matrix<T>::operator[](int index) {
	return matrix_arr[index];
}

//Methods of class Matrix
template <typename T>
void Matrix<T>::PrintMatrix() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << matrix_arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
Matrix<T>& Matrix<T>::TransposeMatrix()
{
	Matrix result(*this);
	for (int i = 0; i < rows; ++i) {
		delete[] matrix_arr[i];
	}
	delete[] matrix_arr;

	int temp_rows = rows;

	matrix_arr = new T * [columns];
	for (int i = 0; i < columns; ++i) {
		matrix_arr[i] = new T[rows];
	}


	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->columns; ++j) {
			matrix_arr[j][i] = result.matrix_arr[i][j];
		}
	}
	rows = columns; columns = temp_rows;
	return *this;
}

template <typename T>
void Matrix<T>::CreateMatrixArr(int rows, int columns)
{
	matrix_arr = new T * [rows];
	for (int i = 0; i < rows; ++i) {
		matrix_arr[i] = new T[columns];
	}
}
template <typename T>
size_t Matrix<T>::InvalidValueArray(const std::vector<std::vector<T>>& arr)
{
	size_t amountOfRows = arr.size();
	size_t currentSizeArr = 0;
	bool firstElement = true;
	for (auto rowArr : arr) {
		if (firstElement == true) {
			currentSizeArr = rowArr.size();
			firstElement = false;
		}
		else {
			if (rowArr.size() != currentSizeArr) {
				throw Matrix::Error("Wrong vector size");
				break;
			}
		}
	}
	return currentSizeArr;
}


