#include <iostream>
#include "Matrix.hpp"

int main() {
	std::vector<std::vector<double>> arr_m = { {1,2},{0,1},{0,1} };
	std::vector<std::vector<double>> arr_m2 = { {0,1,4},{1,0,6} };
	Matrix matr2(arr_m, 3, 2); 
	Matrix matr = matr2;
	matr.PrintMatrix(); 
	return 0;
}