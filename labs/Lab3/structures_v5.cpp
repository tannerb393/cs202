/*   ----------------------------------------------------------------------------
FILE NAME:     structures_v5.CPP
DESCRIPTION:   .cpp file written to use examples of structures and file input/output
PURPOSE:       holds code that is compiled with makefie to run the structures program
USAGE:         compile this file into an executable by using the make file in Lab3, run the 
                compiled file along with inputs for variable when prompted. or using the '<input.txt' file.
EXAMPLES:      'make structure_v5' followed by './structures_v5' or './structures_v5.cpp < input.txt '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         v5 tests out the check for multiple calls to the .h file and also uses the 'CLEAR_SCREEN', 'PRINT_LOCATION',
		and 'ARRAY_SIZE' definitions. 
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v1.cpp
Tanner_Benavides  09-21-2017     2.0 / structures_v2.cpp
Tanner_Benavides  09-21-2017     3.0 / structures_v3.cpp
Tanner_Benavides  09-23-2017     4.0 / structures_v4.cpp
Tanner_Benavides  09-23-2017     5.0 / structures_v5.cpp
----------------------------------------------------------------------------- */

#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"


//Verison 1 ... basic version
//Version 2 ... create an input function
//Version 2 ... create an output function
//Version 4 ... create a header file
//Version 5 ... add a preprocessor macro to the header file


// "main() function --- the program's entry point
//  int argc // Number of parameters on the command line
//      char *argv[] // An array of pointer to C-string

 /*--------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and and input to structures StudentGrade
 * --------------------------------------------------------------------------------------*/
int main (int argc, char* argv[])

{
    
    CLEAR_SCREEN;
    PRINT_LOCATION("At the start...");

    StudentGrade * student = new StudentGrade; //dynamically created new structure with pointer 'student'

    cout << "The size of type 'StudentGrade' is: "
        << sizeof(StudentGrade) << endl << endl;

    get_student_info(& (student[0]));       // Data input
    show_student_info(student); // Output statemnts

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

                            //Debugging output statement
    cout << "\nNumber of tests: " << ARRAY_SIZE ((*s).test) << endl;


    for (size_t i = 0 ; i < ARRAY_SIZE((*s).test) ; i++ )
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

    // CLEAR_SCREEN;

    cout << endl;                   // Output statement
    cout << "First name: " << s->fname << endl;
    cout << "Last name: " << s->lname << endl;

    for (size_t i = 0; i < ARRAY_SIZE((*s).test) ; i++ )
            cout << "Test score: " << s->test[i] << endl;
}
