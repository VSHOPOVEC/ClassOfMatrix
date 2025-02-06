#include <iostream>
#include "Matrix.hpp"

int main() {
	std::vector<std::vector<double>> arr = { {1,0},{2,0} };
	std::vector<std::vector<double>> arr1 = { {1,4},{2,7} };
	Matrix<double> matr(arr);
	Matrix<double> matr1(arr1); 
	std::cout << matr[0][0] << std::endl;
	matr.PrintMatrix(); 
	matr[0][0] = 2; 
	matr.PrintMatrix(); 
	return 0;
}