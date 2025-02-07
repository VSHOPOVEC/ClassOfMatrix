#include <iostream>
#include "dVector.hpp"

int main() {
	//            1 2 3
	//  matrix =  4 5 6 if u wanna to get the last elements in the first 
	//            7 8 9 row u have to matrix[0][2]; 
	std::vector<double> arr = { 1, 1, 1 };
	dVector::dVector3d vec(arr);
	dVector::dVector3d vec_1(1, 1, 2); 
	dVector::dVector3d vec_2 = vec + vec_1; 
	vec_2.PrintVector(); 
	return 0;
}