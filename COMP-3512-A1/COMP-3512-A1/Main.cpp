#include<iostream>
#include "Matrix.hpp"
using namespace std;

int main() {
	int foo[16] = { 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 };
	Matrix * test = new Matrix(foo, 16);
	test->printMatrix();
	test->importance();
	test->generateQMatrix();
	test->convertToMMatrix();
	test->markov();
	system("PAUSE");
	return 0;
}