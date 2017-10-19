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
#include "Polynomial.h" // call to header file
//#include "Polynomial.cpp" // Call to Classes


/* --------------------------------------------------------------------------------------
 *FUNCTION: 
 *PURPOSE: 
 *RETURNS: 
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{/*{{{*/
    Polynomial poly[3]; 

    for (int i = 0; i <3; i++) 
    {
        poly.polyCheck(poly+i);
        polyDisplay(poly+i);
    }

    cout << setprecision(2) << fixed << showpoint;
 
    

   return 0;
}/*}}}*/

int intChoice()
{/*{{{*/
    int choice = 0;
	cout << "Please enter a valid numerical choice(1-9): ";
	cin.clear();
	cin.ignore(100, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

void clearIt()
{/*{{{*/
	cin.clear();
	cin.ignore(100, '\n');
}/*}}}*/

Polynomial::Polynomial()
{
    expo = 0;

    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;

}

void Polynomial::polyCheck(Polynomial *p)
{
    cout << "Enter degree of Polynomial: ";
    cin >> degree;
    while (cin.fail())
    { cout << "Please enter Polynomial degree integer 1-9!\n";
      cin >> degree;
    }
    polyPass(degree);
    cout << "Enter all " << degree << " coeficients: \n";
    for (int i = degree-1; i >= 0; i--)
    {cin >> p->coef[i];
        while (cin.fail() || degree == 0)
        { cout << "Please enter Polynomial degree integer 1-9!\n";
          cin >> p->coef[i];
        }
    }
}
void Polynomial::polyDisplay(Polynomial *p)
{
    cout << "\n\t"; //  Display polynomial

    for (int i = p->degree; i >= 0; i--)
    {
    if (i < p->degree)
    {
        if (p->coef[i] >= 0) cout << " +";
        else cout << " ";
    }
    cout << p->coef[i];

    if (i>1) cout << "x^" << i ;
    if (i==1) cout << "x";
     }
    cout << endl;
    cout << endl;
}

Polynomial polyAdd(Polynomial p0, Polynomial p1)  // Passes & returns
{                              // polynomial structures
        Polynomial p2;

            cout << "\nAdding the 2 polynomials: \n\n";

                p2.degree = MAX(p0.degree, p1.degree); 

                    for (int i = p2.degree; i >= 0; i--)
                                p2.coef[i] = p0.coef[i] + p1.coef[i];

                        return p2;
}


