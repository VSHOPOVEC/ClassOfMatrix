#include <iostream>
#include "Matrix.hpp"

int main() {
	std::vector<std::vector<double>> arr_m = { {1,2},{0,1},{0,1} };
	std::vector<std::vector<double>> arr_m2 = { {0,1,4},{1,0,6} };
	//Matrix matr1(arr_m, 2, 2); 
	Matrix matr2(arr_m2, 2, 3); 
	Matrix matr1(arr_m, 3, 2); 
	Matrix matr(2, 2); 
	matr = matr2 * matr1; 
	matr.PrintMatrix(); 
	double item = (*matr[1])[1]; 
	std::cout << item << std::endl; 
	return 0;
}