#include <iostream>
#include "Matrix.hpp"
#include "Matrix_test .hpp"

int main() {
	std::vector<std::vector<double>> arr_m = { {1,2},{0,1},{0,1} };
	std::vector<std::vector<double>> arr_m2 = { {0,1,4},{1,0,6} };
	//Matrix matr1(arr_m, 2, 2); 
	Matrix matr2(arr_m2, 2, 3); 
	Matrix matr1(arr_m, 3, 2); 
	(matr1*matr2).PrintMatrix();
	return 0;
}