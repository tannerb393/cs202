#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>
#include <sstream>


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
    T get (int , int);
    void set (int, int, T);

    void display();
};

#endif /* __MATRIX_H___ */


// OVERLOADED OPERATORS FOR INPUT AND OUTPUT WILL


// template <class T1>
// friends ostream& operator << (ostream &, const Matrix<T1> &);
// tempate <class T1>
// friend istrream& operator >> (istream &, Matrix <T1> &);
