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
    int x = 0;

    for (int i = 0; i < 2; i++) 
    {
        cin >> poly[i];
        cout << "POLYNOMIAL #" << i+1 << " is: ";
        cout << poly[i];
        cout << endl;
    }

        cout << "[Polynomial #1 ";
        if (poly[0] == poly[1])
            cout << "IS EQUAL ";
        else
            cout << "IS NOT EQUAL ";
        cout << "to Polynomial #2]\n";
        poly[2] = poly[0] + poly[1];
        cout << poly[2];
        poly[2] = poly[0] - poly[1];
        cout << poly[2];
        poly[2] = poly[0] * poly[1];
        cout << poly[2];
        cout << "Set Value for variable x: \n";
        cin >> x;
        poly[0](x);
        cout << "Polynomial #1 sum: ";
        poly[0].displayTotal();
        poly[1](x);
        cout << "Polynomial #2 sum: ";
        poly[1].displayTotal();

  //  cout << setprecision(2) << fixed << showpoint;

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


