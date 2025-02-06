#include <iostream>
#include "Matrix.hpp"

int main() {
	std::vector<std::vector<double>> arr = { {1,0},{2,0} };
	std::vector<std::vector<double>> arr1 = { {1,4},{2,7} };
	Matrix<double> matr(arr);
	Matrix<double> matr1(arr1); 
	std::cout << matr[0][0] << std::endl;
	matr.PrintMatrix(); 
	matr[1][0] = 3; 
	matr.PrintMatrix(); 
	//            1 2 3
	//  matrix =  4 5 6 if u wanna to get the last elements in the first 
	//            7 8 9 row u have to matrix[0][2];  
	return 0;
}