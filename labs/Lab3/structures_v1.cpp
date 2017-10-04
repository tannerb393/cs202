/*   ----------------------------------------------------------------------------
FILE NAME:     structures_v1.CPP
DESCRIPTION:   .cpp file written to use examples of structures and file input/output
PURPOSE:       holds code that is compiled with makefie to run the structures program
USAGE:         compile this file into an executable by using the make file in Lab3, run the 
                compiled file along with inputs for variable when prompted. or using the '<input.txt' file.
EXAMPLES:      'make structure_v1' followed by './structures_v1' or './structures_v1.cpp < input.txt '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         Frst version of the structures .cpp file, holds a 5 var structures and basic call for input to and output
		from the structure 'StudentGrade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v1.cpp
----------------------------------------------------------------------------- */
#include <iostream> // main
#include <cstring> // for cstring input
using namespace std;

//structures.cpp
//Test program for structures

//Verison 1 ... basci version

struct StudentGrade 
{
    unsigned int test[5]; // Array of 5 tests
    char fname[20 + 1]; // First name field (or data member)
    char lname[20 + 1]; // Last name field (or data member)
    double average; // Average of 5 scores
    char letter_grade; // :etter grade: A B C D F
};

// Function prototypes go here


//"main()" function --- the program's entry point
//int argc      // Number of paramenters on the command line
//char *argv[]      // An array of pointers to C-string


 /*--------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and and input to structures StudentGrade
 * --------------------------------------------------------------------------------------*/

int main (int argc, char* argv[])

{

    StudentGrade student;

    cout << " Enter first name: ";
    cin >> student.fname;

    cout << "Enter last name: ";
    cin >> student.lname;

    for (int i = 0; i < 5 ; i++)
    {
        cout << "Enter test score: ";
        cin >> student.test[i];
    }

    cout << endl; //output statement
    cout << "First name: " << student.fname << endl;
    cout << "Last name: " << student.lname << endl;

    for (int i = 0; i < 5 ; i++)
        cout << "Test score: " << student.test[i] << endl;




   return 0;
}
