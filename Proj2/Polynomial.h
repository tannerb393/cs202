/*{{{*/

/* --------------------------------FILE HEADER------------------------------------
* FILE NAME:     Polynomial.h
* DESCRIPTION:   .h file that is the header file for the .cpp file holding the library definitions
                the structure definition and the function prototypes.
PURPOSE:       This files helps to contain parts of the .cpp file which may be used by multiple 
                .cpp files, saving time and cleaning up the code.
USAGE:         included in the beginning of the .cpp by adding "#include 
EXAMPLES:      #include "banking.h"
PARAMETERS:    none 
EXIT CODES:    NA
COMPILATION:   used vim and makefile which includes (.cpp :
	            g++ -o $* $*.cpp -std=c++11 -std=gnu++11
NOTES:         
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-28-2017     1.0 / banking.h
Tanner_Benavides  10-1-2017     2.0 / banking.h
//----------------------------------------------------------------------------- 
*//*}}}*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream> // main
#include <cstring> // for cstring input
#include <stdlib.h> // for system("clear");
#include <cctype> //for testing characters
#include <fstream> //file stream

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

    class Polynomial; // Forward declaration
    ostream &operator << (ostream &, const Polynomial &);
    iostream &operator >> (iostream &, const Polynomial &);



class Polynomial 
{
    private:
        int degree; //store the degree of the polynomial
        int coef[9]; // coefficients of the poly up to 9

    public:
        Polynomial();
        void setPoly();
        void getPoly();
      //  void objOut();
      //  void objIn();
      //  void assing();
      //  void evaluate();

        Polynomial operator + (const Polynomial &); // Overload operator for adding polynomails
        Polynomial operator - (const Polynomial &);
        bool operator == (const Polynomial &);
       
     /*   Polynomial operator * (const Polynomial &);
        Polynomial operator = (const Polynomial &);


        Polynomial operator () (const Polynomial &);
        Polynomial operator -- (const Polynomial &);
        Polynomial operator ++ (const Polynomial &);
    */
      //  Polynomial operator ++ (const Polynomial &);
    friend ostream &operator << (ostream &, const Polynomial &);
    friend iostream &operator >> (iostream &, Polynomial &);


};


 // Function prototypes go here
  int intChoice();
  void clearIt();


#endif /* __POLYNOMIAL_H__ */

