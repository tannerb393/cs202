/*   ----------------------------------------------------------------------------
FILE NAME:     command_line_v3.cpp
DESCRIPTION:    expanded 'command_line_vx.cpp' file that builds upon the two previous versions of
                the program by adding more advanced listing capabilities, and checks for correctly 
                written arguments, this versions lacks the ability to correctly check past the first
                user defined argument and does not correctly make use of the 'valid_option' char array
                to check first-letter accuracy.
PURPOSE:       .cpp file holding the code compiled to the executable command_line_v3
USAGE:         compile this file into an executable by using the make file in Lab2, run the 
                compiled file along with multiple parameters to test the functionality
EXAMPLES:      from terminal: $make command_line_v3, then: ./command_line_v3
PARAMETERS:    can use any text parameters listed as the programs only function is to list them
EXIT CODES:    0 = success
COMPILATION:   g++ -0, -std=gnu++11,

NOTES:         this version of command_line programs can check for user inputted arguments 
                (beyond the always present first argument), uses bool and pointers to attempt to run
                through verifications for correct argument input.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-12-2017     command_line_v1.cpp
Tanner_Benavides  09-12-2017     command_line_v2.cpp
Tanner_Benavides  09-14-2017     command_line_v3.cpp
----------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>

using namespace std;


//      "main ()" function --- the program's entry point 
//      int argc        // Number of paramenteres on the command line
//      char *argv[]    // An array of pointers to C-strings



/*--------------------------------------------------------------------------------------
* FUNCTION NAME: int main ()
* PURPOSE: Holds main code for running program. first function that is called
* RETURNS: 0 for true, 1 for false
* NOTE: holds two command line parameters and test that uses them along with c-strings and pointers.
* --------------------------------------------------------------------------------------*/

int main (int argc, char *argv[])
{
        
    cout << endl;

    for (int i = 0; i < argc; ++i)
    {
        cout << "Argument " << i << " : " << argv[i]  << endl;
    }

    cout << endl;

    char* argument = argv[1];
    const char SLASH = '/';

    char valid_options[] = "?ABCDFILMNOPRSTW";
    char* p = valid_options;

    bool first_char = argument[0] == SLASH; // Test 1st arg's 1st character

    bool second_char = false;

    for (; p != 0; ++p) // Test 1st arg's 2nd character

    {
        second_char = argument[1] == *p;
        if (second_char == true)
            break;
    }

    char bfr[100 + 1];

            // Look for a string
    bool string_found = argument[2] != 0;
    strcpy(bfr, argument+2);

    cout << " Database file: " << bfr << endl;
    cout << endl;

        return 0;       // 0 = success

}



