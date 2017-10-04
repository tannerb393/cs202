/*   ----------------------------------------------------------------------------
FILE NAME:     structures_v2.CPP
DESCRIPTION:   .cpp file written to use examples of structures and file input/output
PURPOSE:       holds code that is compiled with makefie to run the structures program
USAGE:         compile this file into an executable by using the make file in Lab3, run the 
                compiled file along with inputs for variable when prompted. or using the '<input.txt' file.
EXAMPLES:      'make structure_v2' followed by './structures_v2' or './structures_v2.cpp < input.txt '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         Frst version of the structures .cpp file, holds a 5 var structures and basic call for input to and output
		from the structure 'StudentGrade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v1.cpp
Tanner_Benavides  09-21-2017     2.0 / structures_v2.cpp
Tanner_Benavides  09-21-2017     3.0 / structures_v3.cpp
----------------------------------------------------------------------------- */
#include <iostream> // main
#include <cstring> // for cstring input
using namespace std;

//structures.cpp
//Test program for structures

//Verison 1 ... basic version
//Version 2 ... create an input function
//Version 2 ... create an output function


struct StudentGrade 
{
    unsigned int test[5]; // Array of 5 tests
    char fname[20 + 1]; // First name field (or data member)
    char lname[20 + 1]; // Last name field (or data member)
    double average; // Average of 5 scores
    char letter_grade; // :etter grade: A B C D F
};

// Function prototypes go here
void get_student_info(StudentGrade *);
void show_student_info(StudentGrade *);


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

    cout << "The size of type 'StudentGrade' is: "
        << sizeof(StudentGrade) << endl << endl;

    get_student_info(&student);       // Data input
    show_student_info(&student); // Output statemnts

   return 0;
}



/*--------------------------------------------------------------------------------------
* FUNCTION NAME: void get_student_info ()
* PURPOSE: Function called from int main() for gathering input from user for use in the
		StudentGrade structure
* RETURNS: NA - void 
* NOTE: mainly just input function
* --------------------------------------------------------------------------------------*/
void get_student_info (StudentGrade *s)

{
    cout << "The size of pointer 's' is: " << sizeof(s) << endl << endl;
    
    cout << " enter first name: "; // data input 
    cin >> (*s).fname;

    cout << "Enter last name: ";
    cin >> (*s).lname;

    for (int i= 0 ; i < 5 ; i++ )
    {
        cout << "Enter test score: ";
        cin >> (*s).test[i];
    }
}


/*--------------------------------------------------------------------------------------
* FUNCTION NAME: void show_student_info ()
* PURPOSE: function which handles the output of the information stored in the structure
		'StudentGrade'
* RETURNS: NA - void 
* NOTE: mainly just output function
* --------------------------------------------------------------------------------------*/
void show_student_info(StudentGrade *s)
{
    cout << endl;
    cout << "First name: " << s->fname << endl;
    cout << "Last name: " << s->lname << endl;

    for (int i = 0; i < 5 ; i++)
        cout << "Test score: " << s->test[i] << endl;
}
