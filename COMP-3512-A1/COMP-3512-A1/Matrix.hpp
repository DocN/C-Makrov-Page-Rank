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
	void set_Value(int, int, int);
	int get_Value(int, int);
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

private:
	static const int DEFAULT_SIZE = 1;
	int  ** myMatrix;
	int matrixSize;

};