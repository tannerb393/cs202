/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     Matrix.h
DESCRIPTION:   .h file for the matrix_math.cpp program that compiles with Matrix.cpp as well
PURPOSE:       holds the class call and definition, library calls, and non class function prototypes
USAGE:         to be used alongside matrix_math.cpp. must be compiled along with Matrix.cpp 
COMPILATION:   vim to write, and make file to compile: the linux command 'make matrix_math'
NOTES:         many pre-definitions for the public: class Matrix which are mostly for the 
                constructors/destructor and overloaded operators.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  11-28-2017     1.0 / Matrix.h
Tanner_Benavides  12-01-2017     3.0 / Matrix.h
//-----------------------------------------------------------------------------*/ 
/*}}}*/

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream> 
#include <cstring> 
#include <math.h>
#include <stdlib.h> 
#include <fstream> 
#include <sstream> 
#include <string> 
#include <iomanip>

using namespace std;
    
    template <class T>
    class Matrix; // Forward declaration

/*{{{*/ /*{{{*//*-------------CLASS HEADER-------------------------------------------------------*/
//CLASS:class Matrix
//PURPOSE: Class matrix used to store the information for displaying and manipulating 
//         matrixs as they would be manipulated in standard mathmatics
//RETURNS: NA
/*}}}*/ /*--------------------------------------------------------------------------------*/
template <class T>
class Matrix 
{
    private:
        int rows, cols; 
        T **array;
        string m_args[6];
        int m_argc;

    public:
        Matrix<T>();
        Matrix<T>(string[6], int, int); 
        Matrix<T>(int, int, string[6], int);
        ~Matrix<T>() 
        {
            for (int i = 0; i < rows; i++)
                delete [] array[i];
            delete [] array;
           // cout << "~Matrix (69 - Matrix.h)\n";
        }
        Matrix<T>(const Matrix<T> &m1) // COPY CONSTRUCTOR
        {
           rows = m1.rows;
           cols = m1.cols;

            for(int i = 0; i < m1.m_argc; i++)
             m_args[i] = m1.m_args[i];

            for (int i = 0; i < m1.rows; i++)
            {
                for (int j = 0; j < m1.cols; j++)
                {
                   array[i][j] = m1.array[i][j];
                   cout << array[i][j] << endl;
                }
            }

        }

        Matrix<T> operator + (Matrix<T> &); // overloaded + to add poly
        Matrix<T> operator - (Matrix<T> &); // overloaded + to add poly
        Matrix<T> operator * (Matrix<T> &); // overloaded + to add poly
             bool operator == (const Matrix<T> &); // overloaded + to add poly
             void operator = (const Matrix<T> &);  // overloaded assignment 

        void set(int, int, T);
        T get (int, int);
        void trans ();
        void out ();
        bool sizecheck(const Matrix<T> &);
        bool mulsizecheck(const Matrix<T> &);

        void display();

    template <class T1>    
    friend ostream &operator << (ostream &, Matrix<T1> &); // friend << to give access to private members
    template <class T1>
    friend istream &operator >> (istream &, Matrix<T1> &); // friend >> to give access to private memebers
};/*}}}*/





#endif /* __MATRIX_H__ */

