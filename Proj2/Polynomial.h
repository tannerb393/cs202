/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     Polynomial.h
DESCRIPTION:   .h file for the poly_class program that 
PURPOSE:       holds the class call and definition, library calls, and non class function prototypes
USAGE:         to be used alongside poly_class.cpp. must be compiled along with Polynomial.cpp and Polynomial.h
COMPILATION:   vim to write, and make file to compile: the linux command 'make -f Makefile poly_class'
NOTES:         many pre-definitions for the public: class protypes which are mostly for the constructors/destructor and 
                overloaded operators.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  10-25-2017     1.0 / Polynomial.h
Tanner_Benavides  11-1-2017     3.0 / Polynomial.h
//-----------------------------------------------------------------------------*/ 
/*}}}*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream> // main
#include <cstring> // for cstring input
#include <math.h>
#include <stdlib.h> // for system("clear");
#include <fstream> //file stream

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

    class Polynomial; // Forward declaration
    ostream &operator << (ostream &, const Polynomial &); // overloads >>
    istream &operator >> (iostream &, const Polynomial &); // overloads >>


/*-------------------------------------------------------------------------------------
*CLASS:class Polynomial
*PURPOSE: Class polynomial used to store the information for displaying and manipulating 
         polynomials as they would be manipulated in standard mathmatics
*RETURNS: NA
*--------------------------------------------------------------------------------------*/
class Polynomial 
{
    private:
        int degree; //store the degree of the polynomial
        double coef[100]; // coefficients of the poly up to 99
        double sum; // hold sum for the evaluation function

    public:
        Polynomial(); // constructor
        Polynomial(int, int); // overloaded constructor

        Polynomial(const Polynomial &pCopy) // Copy Constructor
        {  degree = pCopy.degree;
           for (int i = 0; i < 100; i++)
           coef[i] = pCopy.coef[i];
           sum = pCopy.sum;
         }

        ~Polynomial() // deconstrutor
        { /*cout << "\n*deconstructor*\n";*/}

        void displayTotal() const // Display out sum total of polynomial after defining X
        {cout << sum << endl;}

        void operator = (const Polynomial &);  // overloaded assignment 
        Polynomial operator + (const Polynomial &); // overloaded + to add poly
        Polynomial operator - (const Polynomial &); // overloaded - to subtract poly
              bool operator == (const Polynomial &); // overloade == to compare poly
        Polynomial operator * (const Polynomial &); // overload * to mutiply poly
        Polynomial operator () (int); // overloaded to solve for x of poly (evaluate)
        Polynomial operator -- (); // overload -- to derive poly
        Polynomial operator ++(); // overload right side ++ to integrate poly
        Polynomial operator ++(int); // overload left side ++ to integrate poly on range

    friend ostream &operator << (ostream &, const Polynomial &); // friend << to give access to private members
    friend istream &operator >> (istream &, Polynomial &); // friend >> to give access to private memebers
};


  int intChoice();
  void clearIt();


#endif /* __POLYNOMIAL_H__ */

