/*   ----------------------------------------------------------------------------
FILE NAME:     command_line_v2.cpp
DESCRIPTION:   basic one function program demonstrating the use of commmand line parameters
               by setting them in int man () and outputtin them back on the screen, small changes
               from command_line_v1 including the program asking the user from more arguments if none
               entered.
PURPOSE:       .cpp file holding the code compiled to the executable command_line_v2
USAGE:         compile this file into an executable by using the make file in Lab2, run the 
                compiled file along with multiple parameters to test the functionality
EXAMPLES:      from terminal: $make command_line_v2, then: ./command_line_v2
PARAMETERS:    can use any text parameters listed as the programs only function is to list them
EXIT CODES:    0 = success
COMPILATION:   g++ -0, -std=gnu++11, 
NOTES:         this version of command_line programs builds slightly on the previous showing how the code
                can check for user inputted arguments (beyond the always present first argument)
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-12-2017     command_line_v1.cpp
Tanner_Benavides  09-12-2017     command_line_v2.cpp
----------------------------------------------------------------------------- */

// Test program for reading command-line parameters

#include <iostream>

using namespace std;


//      "main ()" function --- the program's entry point 
//      int argc        // Number of paramenteres on the command line
//      char *argv[]    // An array of pointers to C-strings



/*--------------------------------------------------------------------------------------
*FUNCTION NAME: int main ()
*PURPOSE: Holds main code for running program. first function called.
*RETURNS: 0 for true, 1 for false
*NOTE: holds two command line parameters
--------------------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
        
    int i = 0;

    cout << endl;

    if (argc==1) cout << "Arguments ?\n\n";

    cout << "argc = " << argc << endl;

    while (argc--)
    {
        cout << "argc = " << argc << "    ";
        cout << "Argument # " << i++ << "   is: ";
        cout << *argv++ << endl;
    }
    cout << endl;

        return 0;       // 0 = success

}



