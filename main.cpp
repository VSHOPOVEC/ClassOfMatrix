#include <iostream>
#include "Matrix.hpp"

int main() {
	std::vector<std::vector<double>> arr = { {1,0},{2,0} };
	std::vector<std::vector<double>> arr1 = { {1,4},{2,7} };
	Matrix matr(arr);
	Matrix matr2(arr1);
	(matr + matr2).PrintMatrix(); 
	std::cout << (*(*(matr + matr2)[1])[0]);
	Matrix matr6 = matr; 
	return 0;
}