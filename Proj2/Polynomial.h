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

#define MAX(x,y) ((x) > (y) ? (x) : (y)) 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) 



using namespace std;

	const int NAME_MAX = 31;
	const int SS_MAX = 12;
	const int PHONE_MAX = 14;
	const int ACCTN_MAX = 6;
	const int PASS_MAX = 7;

class Polynomial 
{
    private:
        long int term;
        int degree;
        int coef[9];

    public:
        void showPoly(Polynomial *);
        long int polyMath();
        void polyCheck(Polynomial *); 
        void polyDisplay(Polynomial *);
        Polynomial(); // constructor
        Polynomial polyAdd(Polynomial, Polynomial);

};

 // Function prototypes go here
  int intChoice();
  void clearIt();


#endif /* __POLYNOMIAL_H__ */

