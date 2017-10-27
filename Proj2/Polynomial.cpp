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

Polynomial::Polynomial()
{/*{{{*/
    degree = 0;
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;

}/*}}}*/

void Polynomial::setPoly()
{/*{{{*/
    cout << "Enter degree of Polynomial: ";
    cin >> degree;
    while (cin.fail())
    { cout << "Please enter Polynomial degree integer 1-9!\n";
      cin >> degree;
    }
    cout << "Enter all " << degree << " coeficients: \n";
    for (int i = degree; i >= 0; i--)
    {cin >> coef[i];
        while (cin.fail() || degree == 0)
        { cout << "Please enter Polynomial degree integer 1-9!\n";
          cin >> coef[i];
        }
    }
}/*}}}*/

void Polynomial::getPoly()
{/*{{{*/
  //  cout << "\n\t"; //  Display polynomial

    for (int i = degree; i >= 0; i--)
    {
    if (i < degree)
    {
        if (coef[i] >= 0) cout << " +";
        else cout << " ";
    }
    cout << coef[i];

    if (i>1) cout << "x^" << i ;
    if (i==1) cout << "x";
     }
    cout << endl;
    cout << endl;
}/*}}}*/

// Overloaded binary + operator
Polynomial Polynomial::operator + (const Polynomial &p1)
{/*{{{*/
    Polynomial p2;

    cout << "\nADDING 2 Polynomials: \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];

    return p2;
}/*}}}*/

// Overloaded binary - operator
Polynomial Polynomial::operator - (const Polynomial &p1)
{/*{{{*/
    Polynomial p2;

    cout << "SUBTRACTING 2 Polynomials: \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] - p1.coef[i];

    return p2;
}/*}}}*/


// Overloaded binary << operator
Polynomial Polynomial::operator << (const Polynomial &p1)
{/*{{{*/
    Polynomial p2;

    cout << "\nADDING 2 Polynomials: ";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];

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




















