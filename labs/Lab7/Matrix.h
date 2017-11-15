#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>


using namespace std;

template <class T>

class Matrix
{
    private:
    int rows, cols; 		// Degree of the polynomial
    T **array; 		// Array of coefficients

    public:
    Matrix(int rows, int cols); // constructor
    ~Matrix();
    T get (int i, int j);
    void set (int i, int j, int T);

    void display();
};

#endif /* __MATRIX_H___ */


// OVERLOADED OPERATORS FOR INPUT AND OUTPUT WILL

