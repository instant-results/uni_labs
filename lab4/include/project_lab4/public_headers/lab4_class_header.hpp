#ifndef MATRIX_HPP
#define MATRIX_HPP
//#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
class Matrix
{
private:
	double* matrix;
	int n;
	int m;
	string filename;
	string path;

public:
	Matrix(const Matrix& copy_this);
	Matrix(int n, int m);
	Matrix(int n);
	void set(int n, int m, double val); //
	double get(int n, int m);           //
	Matrix add(Matrix);
	Matrix subtract(Matrix);
	Matrix multiply(Matrix);
	int cols();   //
	int rows();   //
	void print(); //
	void store(string filename, string path);
	void fill();
	Matrix(string filename, string path); //
	~Matrix();                            //

};
#endif