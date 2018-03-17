#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

int main() {
	ifstream infile;
	infile.open("tester.txt");
	vector<int> numbers;
	int counter = 0;
	if (infile.is_open())
	{
		int num;
		while (infile >> num)
		{
			numbers.push_back(num);
		}
	}

	infile.close();
	int * a = &numbers[0];
	Matrix * test = new Matrix(a, numbers.size());
	test->printMatrix();
	test->importance();
	test->generateQMatrix();
	test->convertToMMatrix();
	double * result = test->markov();
	test->rankCalculateProb(result);
	test->printRankArray(result);
	system("PAUSE");
	return 0;
}