/*   ----------------------------------------------------------------------------
FILE NAME:     structures_v4.h
DESCRIPTION:   .h file that is the header file for the .cpp file holding the library definitions
                the structure definition and the function prototypes.
PURPOSE:       This files helps to contain parts of the .cpp file which may be used by multiple 
                .cpp files, saving time and cleaning up the code.
USAGE:         included in the beginning of the .cpp by adding "#include structures_vx.h" "
EXAMPLES:      #include "structures_v4.h"
PARAMETERS:    none 
EXIT CODES:    NA
COMPILATION:   used vim and makefile which includes (.cpp :
	            g++ -o $* $*.cpp -std=c++11 -std=gnu++11
NOTES:        first version of the .h file which is 4th iteration of the .cpp file for structures
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v4.h
----------------------------------------------------------------------------- */
#include <iostream> // main
#include <cstring> // for cstring input
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX(x,y) ((x) ? (x) : (y) )


struct StudentGrade
{
    unsigned int test[5]; // Array of 5 tests
    char fname[20 + 1]; //First name field (or data memeber)
    char lname[20 +  1]; //Last name field (or data member)
    double average; // Average of 5 scores
    char letter_grade; // Letter grade: A B C D F
};


// Function prototypes go here
void get_student_info(StudentGrade *);
void show_student_info(StudentGrade *);

