/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     Polynomial.CPP
DESCRIPTION:   .CPP file for the poly_class program that 
PURPOSE:       holds bulk of the functions for the the class 'Polynomial'
USAGE:         to be used alongside poly_class.cpp. must be compiled along with poly_class.cpp and Polynomial.h
PARAMETERS:    int argc, char *argv[], but not used in this program
COMPILATION:   vim to write, and make file to compile: the linux command 'make -f Makefile poly_class'

NOTES:         many overloaded operators are used in this program to show example of how these operators can
                ben manipulated to work with classes.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  10-25-2017     1.0 / Polynomial.cpp
Tanner_Benavides  10-28-2017     2.0 / Polynomial.cpp
Tanner_Benavides  11-1-2017     3.0 / Polynomial.cpp
//-----------------------------------------------------------------------------*/ 
/*}}}*/

#include "Polynomial.h" // call to header file
//#include "Polynomial.cpp" // Call to Classes
//Implenmentation file for Polynomial Class

/*-------------------------------------------------------------------------------------
*FUNCTION:Polynomial()
*PURPOSE: primary constructor for the Polynomial class
*RETURNS: NA
*NOTE: 
*--------------------------------------------------------------------------------------*/
Polynomial::Polynomial()
{/*{{{*/
    /*cout << "\n*constructor*\n";*/
    sum = 0;
    degree = 0;
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:Polynomial(int, int)
*PURPOSE: overloaded constructor used similarly to the main constructor but with parameters
*RETURNS: NA
*NOTE: 
*--------------------------------------------------------------------------------------*/
Polynomial::Polynomial(int sum1, int degree1)
{/*{{{*/
    /*cout << "\n*OVERLOADED constructor*\n";*/
    sum = sum1;
    degree = degree1;
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator + ()
*PURPOSE: overloads the + symbol to add two class objects together
*RETURNS: NA
*NOTE: designed to add the coef of each level together (adds coef of the degrees)
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator + (const Polynomial &p1)
{/*{{{*/
    Polynomial p2(0, 0);

    cout << "\n[ADDING: Polynomial #1 + Polynomial #2] \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];

    return p2;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator - ()
*PURPOSE: overloads the - symbol to subtract the polynomial of one object class from the other
*RETURNS: NA
*NOTE: subtract coef from each other of the same degree.
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator - (const Polynomial &p1)
{/*{{{*/
    Polynomial p2;

    cout << "[SUBTRACTING: Polynomial #1 - Polynomial #2] \n";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] - p1.coef[i];

    return p2;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator == ()
*PURPOSE: overloads the == to see if the polynomial stored in two objects are the same
*RETURNS: true/false
*NOTE: check the value stored in each degree level and returns false if even one of them does not match
*--------------------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------------------------
*FUNCTION:operator >> ()
*PURPOSE: overloads the >> operator to 'strm' or cin the entirety of this function to the chose obj
*RETURNS: NA
*NOTE: works like cin >> into the poly[i] object
*--------------------------------------------------------------------------------------*/
istream &operator >> (istream &strm, Polynomial &p1)
{/*{{{*/
    cout << "\n[Enter degree of Polynomial]: ";
    strm >> p1.degree;
    cout << p1.degree;
    while (strm.fail())
    { cout << "Please enter Polynomial degree integer 1-9!\n";
      strm >> p1.degree;
    }
    cout << "\n[Enter " << p1.degree + 1 << " coeficient(s)]: ";
    for (int i = p1.degree; i >= 0; i--)
    {strm >> p1.coef[i];
        cout << p1.coef[i] << ", ";
        while (strm.fail())
        { cout << "Please enter Polynomial degree integer 1-9!\n";
          strm >> p1.coef[i];
        }
    }
    cout << endl;

}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator << ()
*PURPOSE: used to display out the stored 'polynomial' information from the class object
*RETURNS: NA
*NOTE: work like a cout >> to use the function to display the member with the desired effect
*--------------------------------------------------------------------------------------*/
ostream &operator << (ostream &strm, const Polynomial &p1)
{/*{{{*/
    
    int polysum = 0; 
    strm << " ";
    for (int i = p1.degree; i >= 0; i--)
    {
     if(p1.coef[i] != 0)
     {
        if (i < p1.degree)
        {
            if (p1.coef[i] >= 0) strm << " +";
            else strm << " ";
        }
      //  if (p1.coef[i] > 1)
            strm << p1.coef[i];

        if (i>1) strm << "x^" << i ;
        if (i==1) strm << "x";
     }
     polysum += p1.coef[i];
    }

    if (polysum == 0)
        strm << "0";

return strm;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator * () 
*PURPOSE: multiplies together the polynomial information stored in in two class objects
*RETURNS: NA
*NOTE: adds together degrees while also multiplying the coef of all same degree coefficients
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator * (const Polynomial &p1)
{/*{{{*/

Polynomial p2;

    cout << "[MULTIPLYING: Polynomial #1 * Polynomial #2]\n";

    p2.degree = MAX(degree, p1.degree);

    for (int i = degree; i >= 0; i--)
        for (int j = p1.degree; j >= 0; j--)
        {
          p2.coef[i+j] += (coef[i] * p1.coef[j]);
        }
    p2.degree = degree + p1.degree;


return p2;
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator ()
*PURPOSE: used to assign value to the 'x' displayed in the polynomials of the class objects
     and then sum up and solve the polynomial storing the answer in the 'sum' private member
*RETURNS: NA
*NOTE: uses the 'pow' power function to take the 'x' to a power then multiplies with the coef[i] 
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator () (int x)
{/*{{{*/
    for (int i = degree; i >= 0; i--) 
      sum += coef[i] * (pow (x, i));
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION: operator = ()
*PURPOSE: assigns the values of one class object including all members, to another class object
*RETURNS: void
*NOTE: works very similar to a copy constructor
*--------------------------------------------------------------------------------------*/
void Polynomial::operator = (const Polynomial &assign)
{/*{{{*/
    degree = assign.degree;
    sum = assign.sum;
    for (int i = 0; i < 100; i ++)
        coef[i] = assign.coef[i];
}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator -- ()
*PURPOSE: fuction obtains the derivative of the polynomial stored in the class object
*RETURNS: NA
*NOTE: using for loop multiplies the coef by the current degree and moves each coef down a power
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial:: operator -- ()
{/*{{{*/
     int coefTemp[100];

     for (int i = degree; i >= 0; i--) 
        coefTemp[i] = coef[i] * i;

     for (int i = degree; i >= 1; i--) 
        coef[i - 1] = coefTemp[i];
     --degree;

}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator ++ 
*PURPOSE: obtains the integral of the polynomial stored in the class object
*RETURNS: NA
*NOTE: raises the degree of each coefficient's power and also divides by the previous power
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial:: operator ++ ()
{/*{{{*/
     double coefTemp[100];

     for (int i = degree; i >= 0; i--) 
        coefTemp[i] =  coef[i] / (i + 1) ;

     for (int i = degree; i >= 0; i--) 
        coef[i + 1] = coefTemp[i];
        coef[0] = 0;
     ++degree;

}/*}}}*/

/*-------------------------------------------------------------------------------------
*FUNCTION:operator ++ (int)
*PURPOSE: does a definite integral, similar to previous function but uses upper and lower bounds
*RETURNS: NA
*NOTE: works like the '()' overloaded operator and then subtracts polynomial #2 from #1
*--------------------------------------------------------------------------------------*/
Polynomial Polynomial::operator ++(int)
{/*{{{*/
    double sum1 = 0;
    double sum2 = 0;
    double min = 0;
    double max = 0;

    cout << "\nDefine Beginnig Range for the Definite Integral: ";
    cin >> min;
    cout << min;
    cout << "\nDefine End Range for the Definite Integral: ";
    cin >> max;
    cout << max;
        
    for (int i = degree; i >= 0; i--) 
      sum1 += coef[i] * (pow (min, i));

    for (int i = degree; i >= 0; i--) 
      sum2 += coef[i] * (pow (max, i));

    sum = sum2 - sum1;


}/*}}}*/



