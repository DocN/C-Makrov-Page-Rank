#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

/*
run - executes the search algo ranking 
Input
	N/A
Output
	Void
*/
void run(Matrix * test) {
	test->printMatrix();
	test->importance();
	test->generateQMatrix();
	test->convertToMMatrix();
	double * result = test->markov();
	test->rankCalculateProb(result);
	test->printRankArray(result);

}

/*
openFileAndRun - opens a matrix file and runs the algo ranking
Input
	string name - name of file
Output
	Void
*/
void openFileAndRun(string name) {
	ifstream infile;
	infile.open(name);
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
	Matrix * test = new Matrix(a, ((int)numbers.size()));
	run(test);
}

int main() {
	/*
	[ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0;
	1, 0, 0, 0, 0, 0, 1, 0, 1, 0;
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0;
	0, 0, 0, 0, 0, 0, 1, 1, 0, 0;
	0, 1, 0, 0, 0, 1, 0, 1, 0, 0;
	0, 0, 0, 0, 0, 0, 0, 1, 0, 1;
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0;
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
	0, 1, 1, 0, 0, 0, 1, 0, 0, 0;
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0 ] 
	A = 0.130816
	B = 0.268108
	C = 0.018188
	D = 0.054727
	E = 0.108890
	F = 0.079365
	G = 0.128962
	H = 0.015000
	I = 0.123972
	J = 0.071973
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 1" << endl;
	openFileAndRun("tester.txt");
	/*
	[ 0, 1, 1, 1, 1, 0, 1, 1, 0, 1;
	1, 0, 1, 1, 1, 1, 1, 1, 1, 1;
	1, 1, 0, 1, 1, 1, 1, 1, 1, 1;
	1, 1, 1, 0, 1, 0, 0, 1, 1, 1;
	0, 1, 1, 0, 0, 1, 1, 1, 1, 1;
	1, 1, 0, 0, 1, 0, 1, 1, 1, 1;
	1, 1, 0, 1, 0, 1, 0, 1, 1, 1;
	1, 0, 1, 1, 0, 1, 0, 0, 1, 1;
	0, 1, 1, 1, 1, 1, 0, 1, 0, 1;
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ] should generate a PageRank file that looks like this:

	A = 0.096501
	B = 0.117129
	C = 0.115544
	D = 0.093980
	E = 0.094919
	F = 0.092857
	G = 0.091111
	H = 0.084697
	I = 0.094869
	J = 0.118393
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 2" << endl;
	openFileAndRun("tester2.txt");

	/*
	[ 0, 1, 1, 1, 1, 1, 1;
	0, 0, 0, 1, 0, 1, 1;
	0, 1, 0, 1, 1, 1, 1;
	1, 1, 1, 0, 0, 1, 1;
	1, 1, 0, 0, 0, 1, 1;
	0, 0, 1, 0, 1, 0, 1;
	1, 1, 0, 1, 0, 1, 0 ] should generate a PageRank file that looks like this:

	A = 0.190277
	B = 0.095439
	C = 0.148268
	D = 0.171204
	E = 0.129194
	F = 0.120589
	G = 0.145029
	*/
	cout << "-----------------------------------------------------" << endl;
	cout << "test 3" << endl;
	openFileAndRun("tester3.txt");

	/*
	0 1 1 0
	1 0 1 0
	1 1 0 0
	0 0 0 0
	rank = 1.2698 / 3.999 = 0.3175
	1.2698 / 3.999 0.3175
	1.2698 / 3.999 0.3175
	0.1905 / 3.999 0.0476
	*/

	cout << "-----------------------------------------------------" << endl;
	cout << "test 4" << endl;
	openFileAndRun("tester4.txt");
	system("PAUSE");
	return 0;
}



