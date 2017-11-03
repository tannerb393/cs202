/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     poly_class.cpp
DESCRIPTION:   .cpp file which is main .cpp for the poly_class programs. holds int main () and other non-class functions 
PURPOSE:       for connection the actions of the header file 'Polynomial.h' and 'Polynomial.cpp'
USAGE:         must be compiled along with Polynomial.h and Polynomial.cpp
COMPILATION:   vim to write, and make file to compile: the linux command 'make -f Makefile poly_class'
NOTES:         uses the int main () function to give call all other functions in a linear method to show all the functionality
                of the Class member functions, and variables. user input is limited to some basic calls for degree values,
                coeficcient values, x value, and ranges for integrals.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  10-25-2017     1.0 / poly_class.cpp
Tanner_Benavides  11-1-2017     2.0 / poly_class.cpp
//-----------------------------------------------------------------------------*/ 
/*}}}*/
#include "Polynomial.h" // call to header file
//#include "Polynomial.cpp" // Call to Classes


/* --------------------------------------------------------------------------------------
 *FUNCTION: int main ()
 *PURPOSE: holds majority of code to call other functions 
 *RETURNS: 0 to end program 
 * --------------------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{/*{{{*/
    Polynomial poly[5]; 
    int x = 0;

    for (int i = 0; i < 2; i++) 
    {
        cin >> poly[i];
        cout << "POLYNOMIAL #" << i+1 << " is: ";
        cout << poly[i] << endl;
        cout << endl;
    }

        cout << "[Polynomial #1 ";
        if (poly[0] == poly[1])
            cout << "IS EQUAL ";
        else
            cout << "IS NOT EQUAL ";
        cout << "to Polynomial #2]\n";

        poly[2] = poly[0] + poly[1];
        cout << poly[2] << endl << endl;

        poly[2] = poly[0] - poly[1];
        cout << poly[2] << endl << endl;

        poly[2] = poly[0] * poly[1];
        cout << poly[2] << endl << endl;

        cout << "\nSet Value for variable x: \n";
        cin >> x;
        poly[0](x);
        cout << "Answer for Polynomial #1 given f(" << x << ") : ";
        poly[0].displayTotal();
        poly[1](x);
        cout << "Answer for Polynomial #2 given f(" << x << ") : ";
        poly[1].displayTotal();

        poly[2] = poly[0];
        --poly[2];
        cout << "\n[DERIVATIVE OF " << poly[0] << " ]" << endl;
        cout << poly[2] << endl;
        poly[2] = poly[1];
        --poly[2];
        cout << "\n[DERIVATIVE OF " << poly[1] << " ]" << endl;
        cout << poly[2] << endl;

        poly[3] = poly[0];
        ++poly[3];
        cout << "\n[INTEGRAL OF " << poly[0] << " ]" << endl;
        cout << poly[3] << endl;
        poly[4] = poly[1];
        ++poly[4];
        cout << "\n[INTEGRAL OF " << poly[1] << " ]" << endl;
        cout << poly[4] << endl;

        poly[3]++;
        cout << "\n[Solution for the DEFINITE INTEGRAL OF " << poly[0] << "] \n ";
        poly[3].displayTotal();
        poly[4]++;
        cout << "\n[Solution for the DEFINITE INTEGRAL OF " << poly[1] << "] \n ";
        poly[4].displayTotal();

  //  cout << setprecision(2) << fixed << showpoint;

   return 0;
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION: intChoice()
 *PURPOSE: used to correct invalid, non-numerical choice input                                              
 *RETURNS: int value
 * --------------------------------------------------------------------------------------*/
int intChoice()
{/*{{{*/
    int choice = 0;
	cout << "Please enter a valid numerical choice(1-9): ";
	cin.clear();
	cin.ignore(100, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION: clearIt()
 *PURPOSE: clears buffer 
 *RETURNS: void 
 * --------------------------------------------------------------------------------------*/
void clearIt()
{/*{{{*/
	cin.clear();
	cin.ignore(100, '\n');
}/*}}}*/


