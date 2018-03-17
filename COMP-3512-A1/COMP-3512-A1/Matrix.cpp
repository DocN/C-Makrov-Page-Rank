#include <iostream>
#include "Matrix.hpp"
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <array>
#include <vector>


using namespace std;
//Matrix default constructor
Matrix::Matrix() {
	//create object and allocate space
	myMatrix = new double*[DEFAULT_SIZE];
	allocateArray(DEFAULT_SIZE);
	matrixSize = DEFAULT_SIZE;
	//store zero into the 1/1 grid
	int A[DEFAULT_SIZE] = { DEFAULT_SIZE };
	fillMatrix(A, DEFAULT_SIZE);
}

/*overloaded Matrix constructor
-Input
int array A - The array of integers we're going to story in the matrix
int n  - The size of the array A
-Output
N/A
*/
Matrix::Matrix(int A[], int n) {
	int dimension = DEFAULT_SIZE;
	//check if the size of the array is valid for a matrix
	if (checkSquarable(n)) {
		dimension = int(sqrt(n));
	}
	else {
		cout << "invalid number of elements, made 1 by 1 matrix " << endl;
	}
	//create matrix and allocate with dimensions 
	myMatrix = new double*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
	fillMatrix(A, n);
}

/*overloaded Matrix constructor
Creates an empty Matrix of desired dimensions
-Input
int dimension  - The dimensions of Matrix
-Output
N/A
*/
Matrix::Matrix(int dimension) {
	myMatrix = new double*[dimension];
	allocateArray(dimension);
	matrixSize = dimension;
}

/*
Matrix Destructor - Frees memory in use by Matrix
-Input
-Output
*/
Matrix::~Matrix() {
	//loop through all the dynamic arrays and delete them
	for (int i = 0; i < matrixSize; i++) {
		delete[] myMatrix[i];
	}
	//delete the pointer array to the dynamic arrays
	delete[] myMatrix;
}

/*
allocateArray - Allocates dynamic arrays in myMatrix
-Input
int dimension - the dimension of the array we're allocating
-Output
void
*/
void Matrix::allocateArray(int dimension) {
	//loop through the pointer array and allocate an array for each pointer
	for (int i = 0; i < dimension; i++) {
		myMatrix[i] = new double[dimension];
	}
}

/*
checkSquarable - Checks if a number is a valid square root
-Input
int number - the number we're checking
-Output
boolean - if the number is a valid square or not
*/
bool Matrix::checkSquarable(int number) {
	//allocate an integer and a double and check if the value is greater than 0 after square rooting
	int fullNumber = int(sqrt(number));
	double tempNumber = sqrt(number);
	tempNumber = tempNumber - fullNumber;
	if (tempNumber > 0) {
		return false;
	}
	return true;
}

/*
printMatrix - Prints the matrix to cout
-Input
N/A
-Output
void
*/
void Matrix::printMatrix() {
	//loop through the 2d array matrix and print all the values 
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			cout << myMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*
set_Value - sets the value of a specific cell in the matrix
-Input
int x -  the x position in the matrix
int y - the y position in the matrix
int value - the value we're storing at the cell
-Output
void
*/
void Matrix::set_Value(int x, int y, double value) {
	myMatrix[x][y] = value;
}

/*
get_Value - gets the value at a specific coordinate in the Matrix
-Input
int x - the coordinate on x axis
int y - the coordinate on the y axis
-Output
int - the value at the specified coordinates
*/
double Matrix::get_Value(int x, int y) {
	return myMatrix[x][y];
}

/*
clearArray - clears the matrix by setting everythijng to zero
-Input
N/A
-Output
void
*/
void Matrix::clearArray() {
	//loop through the matrix and set everything to zero
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = 0;
		}
	}
}

/*
fillMatrix - fills the matrix with the given array of ints
-Input
int A[] - the array we're storing in the matrix
int n - the size of the array we're storing in the matrix
-Output
void
*/
void Matrix::fillMatrix(int A[], int n) {
	int arrayCount = 0;
	//storing each array value in the matrix
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = A[arrayCount];
			arrayCount++;
		}
	}
}

/*
identity - makes an identity matrix of the same dimensions of the original
-Input
N/A
-Output
Matrix pointer to new matrix
*/
Matrix * Matrix::identity() {
	Matrix * newIdentity = new Matrix(matrixSize);
	for (int i = 0; i < newIdentity->matrixSize; i++) {
		for (int j = 0; j < newIdentity->matrixSize; j++) {
			if (i == j) {
				newIdentity->set_Value(i, j, 1);
			}
			else {
				newIdentity->set_Value(i, j, 0);
			}
		}
	}
	return newIdentity;
}

/*
Overloaded << that prints the given matrix
-Input
ostream& os - the output stream we're changing and returning
const Matrix& theMatrix - the matrix we're outputting
-Output
ostream& os - the output stream we're changing and returning
*/
ostream& operator<<(ostream& os, const Matrix& theMatrix)
{
	for (int i = 0; i < theMatrix.matrixSize; i++) {
		for (int j = 0; j < theMatrix.matrixSize; j++) {
			os << theMatrix.myMatrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

/*
== comparison operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if they're equal or not
*/
bool operator== (const Matrix &m1, const Matrix &m2) {
	//check if they're the same size
	if (m1.matrixSize == m2.matrixSize) {
		for (int i = 0; i < m1.matrixSize; i++) {
			for (int j = 0; j < m1.matrixSize; j++) {
				//check each element to see if they're equal
				if (!(m1.myMatrix[i][j] == m2.myMatrix[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

/*
!= comparison not equals operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if they're not equal or not
*/
bool operator!= (const Matrix &m1, const Matrix &m2) {
	if (m1 == m2) {
		return false;
	}
	return true;
}

/*
comparison less than operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if they're not equal or not
*/
bool operator< (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize < m2.matrixSize) {
		return true;
	}
	return false;
}

/*
comparison less than equal operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if they're less than or equal or not
*/
bool operator<= (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize < m2.matrixSize || m1 == m2) {
		return true;
	}
	return false;
}

/*
comparison less than equal operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if they're less than or equal or not
*/
bool operator> (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize > m2.matrixSize) {
		return true;
	}
	return false;
}

/*
comparison >= operator overloaded
-Input
const Matrix &m1 -matrix one for comparison
const Matrix &m2 -matrix two for comparison
-Output
Boolean if >= or not
*/
bool operator>= (const Matrix &m1, const Matrix &m2) {
	if (m1.matrixSize > m2.matrixSize || m1 == m2) {
		return true;
	}
	return false;
}

/*
comparison preincrement ++ operator overloaded
-Input
N/A
-Output
Matrix - preincremented Matrix
*/
Matrix& Matrix::operator++() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			double currentVal = get_Value(i, j) + 1;
			set_Value(i, j, currentVal);
		}
	}
	return *this;
}

/*
comparison post increment ++ operator overloaded
-Input
N/A
-Output
Matrix - post incremented Matrix
*/
Matrix& Matrix::operator++(int) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			double currentVal = get_Value(i, j) + 1;
			set_Value(i, j, currentVal);
		}
	}
	return *this;
}
/*
comparison predeincrement -- operator overloaded
-Input
N/A
-Output
Matrix - predeincremented Matrix
*/
Matrix& Matrix::operator--() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			double currentVal = get_Value(i, j) - 1;
			set_Value(i, j, currentVal);
		}
	}
	return *this;
}

/*
comparison post deincrement -- operator overloaded
-Input
N/A
-Output
Matrix - post deincremented Matrix
*/
Matrix& Matrix::operator--(int) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			double currentVal = get_Value(i, j) - 1;
			set_Value(i, j, currentVal);
		}
	}
	return *this;
}

/*
comparison = operator overloaded
-Input
N/A
-Output
Matrix = copied object for equaling
*/
Matrix& Matrix::operator=(const Matrix &rhs) {
	Matrix * temp = new Matrix(rhs.matrixSize);
	copier(*temp, rhs);
	return *temp;
}

/*
swaper function for adding the values of matrix 1 to matrix 2
-Input
N/A
-Output
Matrix = copied object for equaling
*/
void Matrix::copier(Matrix & m1, Matrix const & rhs) {
	//copy from one matrix to the other.
	for (int i = 0; i < m1.matrixSize; i++) {
		for (int j = 0; j < rhs.matrixSize; j++) {
			m1.myMatrix[i][j] = rhs.myMatrix[i][j];
		}
	}
}

/*
increment plus equal Overloaded
-Input
Matrix& rhs - The matrix we're incrementing
-Output
Matrix - the incremented Matrix
*/
Matrix& Matrix::operator+=(Matrix& rhs) {
	if (rhs.matrixSize != matrixSize) {
		cout << "invalid summation, matrixes aren't the same size" << endl;
	}
	else {
		//loop through all the elements from each Matrix and sum them.
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				double newVal = myMatrix[i][j] + rhs.myMatrix[i][j];
				set_Value(i, j, newVal);
			}
		}
	}
	return *this;
}

/*
deincrement -= Overloaded
-Input
Matrix& rhs - The matrix we're deincrementing
-Output
Matrix - the deincremented Matrix
*/
Matrix& Matrix::operator-=(Matrix& rhs) {
	if (rhs.matrixSize != matrixSize) {
		cout << "invalid summation, matrixes aren't the same size" << endl;
	}
	else {
		//loop through all the values in the cells and subtract them
		for (int i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				double newVal = myMatrix[i][j] - rhs.myMatrix[i][j];
				set_Value(i, j, newVal);
			}
		}
	}
	return *this;
}

/*
operator+ overloaded
Input
const Matrix& a - the first matrix we're summing
const Matrix& b - the second matrix we're summing
Output
Matrix& the summed matrix we're returning
*/
Matrix& operator+(const Matrix& a, const Matrix& b) {
	Matrix * newMatrix = new Matrix(a.matrixSize);
	//check if they're the same size first
	if (a.matrixSize == b.matrixSize) {
		//loop through all the cells and sum them
		for (int i = 0; i < a.matrixSize; i++) {
			for (int j = 0; j < a.matrixSize; j++) {
				double newVal = a.myMatrix[i][j] + b.myMatrix[i][j];
				newMatrix->myMatrix[i][j] = newVal;
			}
		}
	}
	return *newMatrix;
}

/*
operator+ overloaded
Input
const Matrix& a - the first matrix we're subtracting
const Matrix& b - the second matrix we're subtracting
Output
Matrix& the subtracted matrix we're returning
*/
Matrix& operator-(const Matrix& a, const Matrix& b) {
	Matrix * newMatrix = new Matrix(a.matrixSize);
	//check if the matracies are the same size.
	if (a.matrixSize == b.matrixSize) {
		//loop through all the values and do the work
		for (int i = 0; i < a.matrixSize; i++) {
			for (int j = 0; j < a.matrixSize; j++) {
				double newVal = a.myMatrix[i][j] - b.myMatrix[i][j];
				newMatrix->myMatrix[i][j] = newVal;
			}
		}
	}
	return *newMatrix;
}

/*
importance - sets up the importance matrix
Input
	N/A
Output
	void
*/
void Matrix::importance() {
	//loop through and make the S matrix
	for (int i = 0; i < matrixSize; i++) {
		double total = 0;
		for (int j = 0; j < matrixSize; j++) {
			total = total + myMatrix[j][i];
		}
		//do the division and store it
		for (int j = 0; j < matrixSize; j++) {
			//don't divide by zero D:
			if (total == 0) {
				double value = ((double)1 / (double)matrixSize);
				myMatrix[j][i] = value;
			}
			else {
				myMatrix[j][i] = myMatrix[j][i] / total;
			}
			
		}
	}
}

/*
generateQMatrix - generates a Q Matrix for the search algo problem
Input
	N/A
Output
	Matrix * - matrix pointer to a Q matrix
*/
Matrix* Matrix::generateQMatrix() {
	//create a q matrix
	Matrix * qMatrix = new Matrix(matrixSize);
	double qVal = (0.15) * (((double)1) / (((double)matrixSize)));
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			qMatrix->set_Value(i, j, qVal);
		}
	}
	return qMatrix;
}

/*
setZeros - sets all the values in the matrix to 0 
Input
	N/A
Output
	void
*/
void Matrix::setZeros() {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = 0;
		}
	}
}

/*
convertToMMatrix - converts a matrix to the M matrix format required by the search algo
Input
	N/A
Output
	void
*/
void Matrix::convertToMMatrix() {
	Matrix * qMatrix = generateQMatrix();
	//do stuff before matrix multi
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] =  (P_VALUE * myMatrix[i][j]);
		}
	}
	//sum the TransitionMatrix with the StochasticMatrix
	Matrix result = *this + *qMatrix;
	copyToThisMatrix(&result);
}

/*
markov - execute the markov function until we reach equalibrium 
Input
	N/A
Output
	double * - array of ranks 
*/
double * Matrix::markov() {
	//create a traversal markov from running through data
	double * traverseMarkov = new double[matrixSize];
	//setup initial traversal values
	for (int i = 0; i < matrixSize; i++) {
		traverseMarkov[i] = INITIAL_RANK;
	}
	//copy the values to another rank list to compare each markov run
	double * lastMarkov = new double[matrixSize];
	copyArray(lastMarkov, traverseMarkov);

	//do until we reach a good equalibrium 
	do {
		//store results in a rank array
		double * results = new double[matrixSize];
		//copy the current traversal to the last one for reference
		copyArray(lastMarkov, traverseMarkov);

		//run another makrov iteration
		for (int i = 0; i < matrixSize; i++) {
			double total = 0;
			for (int j = 0; j < matrixSize; j++) {
				total = total + (myMatrix[i][j] * traverseMarkov[j]);
			}
			results[i] = total;
		}
		copyArray(traverseMarkov, results);
		//show current makrov
		printRankArray(traverseMarkov);
	} while (compareRank(lastMarkov, traverseMarkov));
	return traverseMarkov;
}

/*
rankCalculateProb - calculate the probability out of 1 
Input
	double * rank - array of doubles 
Output
	void
*/
void Matrix::rankCalculateProb(double * ranks) {
	double total = 0;
	//sum the total of all ranks
	for (int i = 0; i < matrixSize; i++) {
		total = total + ranks[i];
	}
	//divide by number of elements
	total = total / matrixSize;
	//divide each one 
	for (int i = 0; i < matrixSize; i++) {
		ranks[i] = ranks[i] / matrixSize;
	}
}

/*
compareRank - For comparing the last rank to the current one to see if we've reached equalibrium
Input
	double * cur - the current ranking table
	double *last - the previous ranking table
Output
	bool - result if we've reached desired makrov result
*/
bool Matrix::compareRank(double * cur, double *last) {
	for (int i = 0; i < matrixSize; i++) {
		double difference = cur[i] - last[i];
		difference = fabs(difference);
		if (difference < 0.00001) {
			return false;
		}
	}
	return true;
}

/*
copyArray - Copies the values of one array to another.
Input	
	double * a1 - first array
	double * a2 - second array
Output
	void
*/
void Matrix::copyArray(double * a1, double * a2) {
	for (int i = 0; i < matrixSize; i++) {
		a1[i] = a2[i];
	}
}

/*
printRankArray - prints the rank rank list A 
Input
	double * rank - rank array we're printing
Output
	void
*/
void Matrix::printRankArray(double * rank) {
	char letter = 'A';
	for (int i = 0; i < matrixSize; i++) {
		cout << letter << ": ";
		cout << rank[i] << endl;
		letter++;
	}
	cout << "------" << endl;
}

/*
copyToThisMatrix - Takes all the values from the temp matrix and sets the values in myMatrix
Input
	Matrix * temp - the matrix we're taking values from
Output
	void
*/
void Matrix::copyToThisMatrix(Matrix * temp) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			myMatrix[i][j] = temp->get_Value(i, j);
		}
	}
}





