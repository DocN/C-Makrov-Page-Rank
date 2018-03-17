#pragma once
#include <iostream> 

using namespace std;


class Matrix {
public:
	Matrix();
	Matrix(int A[], int n);
	Matrix(int);
	~Matrix();
	void allocateArray(int);
	bool checkSquarable(int);
	void printMatrix();
	void set_Value(int, int, double);
	double get_Value(int, int);
	void clearArray();
	Matrix * identity();
	void fillMatrix(int A[], int);
	void Matrix::copier(Matrix & m1, Matrix const & rhs);
	
	friend ostream& operator<<(ostream& os, const Matrix& theMatrix);
	friend bool operator== (const Matrix &m1, const Matrix &m2);
	friend bool operator!= (const Matrix &m1, const Matrix &m2);
	friend bool operator< (const Matrix &m1, const Matrix &m2);
	friend bool operator<= (const Matrix &m1, const Matrix &m2);
	friend bool operator> (const Matrix &m1, const Matrix &m2);
	friend bool operator>= (const Matrix &m1, const Matrix &m2);
	Matrix& operator++();
	Matrix& operator++(int);
	Matrix& operator--();
	Matrix& operator--(int);
	Matrix& Matrix::operator=(const Matrix &rhs);
	Matrix& operator+=(Matrix& rhs);
	Matrix& operator-=(Matrix& rhs);
	friend Matrix& operator+(const Matrix& a, const Matrix& b);
	friend Matrix& operator-(const Matrix& a, const Matrix& b);

	//Assignment 1 
	void importance();
	Matrix * generateQMatrix();
	void convertToMMatrix();
	void setZeros();
	void copyToThisMatrix(Matrix *);
	double * markov();
	void rankCalculateProb(double *);
	void copyArray(double *, double *);
	void printRankArray(double *);
	bool compareRank(double *, double *);

private:
	static const int DEFAULT_SIZE = 1;
	static const int INITIAL_RANK = 1;
	const double P_VALUE = 0.85;
	double  ** myMatrix;
	int matrixSize;

};