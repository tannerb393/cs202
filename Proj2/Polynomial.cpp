/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     banking.CPP
DESCRIPTION:   polyclass.cpp file written to use create a banking program 
PURPOSE:       holds code that is compiled with makefie to run the banking program
USAGE:         compile this file into an executable by using the make file in Proj1, run the 
                compiled file along any command line actions.
EXAMPLES:      'make banking' followed by './banking '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         large project file that contains most processes in individual functions
		from the structure 'StudentGrade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-28-2017     1.0 / banking.cpp
Tanner_Benavides  10-8-2017     2.0 / banking.cpp
Tanner_Benavides  10-11-2017     3.0 / banking.cpp
//-----------------------------------------------------------------------------*/ 
/*}}}*/

//Polynomial.cpp
#include "Polynomial.h" // call to header file
//#include "Polynomial.cpp" // Call to Classes
//Implenmentation file for Polynomial Class

//Copy constructor
Polynomial::Polynomial()
{/*{{{*/
    sum = 0;
    degree = 0;
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}/*}}}*/

//Copy Contructor #2 (overloaded)
Polynomial::Polynomial(int sum1, int degree1)
{/*{{{*/
    sum = sum1;
    degree = degree1;
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}/*}}}*/

// Overloaded binary + operator
Polynomial Polynomial::operator + (const Polynomial &p1)
{/*{{{*/
    Polynomial p2(0, 0);

    cout << "\n[ADDING 2 Polynomials] \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];

    return p2;
}/*}}}*/

// Overloaded binary - operator
Polynomial Polynomial::operator - (const Polynomial &p1)
{/*{{{*/
    Polynomial p2;

    cout << "[SUBTRACTING 2 Polynomials] \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] - p1.coef[i];

    return p2;
}/*}}}*/

// Overloaded binary == operator
bool Polynomial::operator == (const Polynomial &p1)
{/*{{{*/

    bool equal = true;

    for(int i = 0; i <= p1.degree; i++){
       // cout << "p2= " << coef[i] << " p1=" << p1.coef[i] << endl; 
       if(coef[i] != p1.coef[i]){
           equal = false;
           break;
       }
    }
    return equal;
}/*}}}*/

// Overloaded binary + operator
istream &operator >> (istream &strm, Polynomial &p1)
{/*{{{*/
    cout << "[Enter degree of Polynomial]:\n";
    strm >> p1.degree;
    while (strm.fail())
    { cout << "Please enter Polynomial degree integer 1-9!\n";
      strm >> p1.degree;
    }
    cout << "[Enter " << p1.degree << " coeficient(s)]:\n";
    for (int i = p1.degree; i >= 0; i--)
    {strm >> p1.coef[i];
        while (strm.fail() || p1.degree == 0)
        { cout << "Please enter Polynomial degree integer 1-9!\n";
          strm >> p1.coef[i];
        }
    }

}/*}}}*/

// Overloaded binary << operator
ostream &operator << (ostream &strm, const Polynomial &p1)
{/*{{{*/

    for (int i = p1.degree; i >= 0; i--)
    {
    if (i < p1.degree)
    {
        if (p1.coef[i] >= 0) strm << " +";
        else strm << " ";
    }
    strm << p1.coef[i];

    if (i>1) strm << "x^" << i ;
    if (i==1) strm << "x";
     }
    strm << endl;
    strm << endl;

return strm;
}/*}}}*/

// Overloaded binary *
Polynomial Polynomial::operator * (const Polynomial &p1)
{/*{{{*/

Polynomial p2;

    cout << "[MULTIPLYING 2 Polynomials] \n";

    p2.degree = MAX(degree, p1.degree);

    for (int i = degree; i >= 0; i--)
        for (int j = p1.degree; j >= 0; j--)
        {
          p2.coef[i+j] += (coef[i] * p1.coef[j]);
        }
    p2.degree = degree + p1.degree;


return p2;
}/*}}}*/

//Overloaded assignment ( ) operator
Polynomial Polynomial::operator () (int x)
{/*{{{*/
    for (int i = degree; i >= 0; i--) 
      sum += coef[i] * (pow (x, i));
}/*}}}*/








