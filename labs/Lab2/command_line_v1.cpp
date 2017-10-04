/*   ----------------------------------------------------------------------------
FILE NAME:     command_line_v1.cpp
DESCRIPTION:   basic two function program demonstrating the use of commmand line parameters
               by setting them in int man () and outputtin them back on the screen
PURPOSE:       .cpp file holding the code compiled to the executable command_line_v1
USAGE:         compile this file into an executable by using the make file in Lab2, run the 
                compiled file along with multiple parameters to test the functionality
EXAMPLES:      from terminal: $make command_line_v1, then: ./command_line_v1
PARAMETERS:    can use any text parameters listed as the programs only function is to list them
EXIT CODES:    0 = success
COMPILATION:   g++ -0, -std=gnu++11, 
NOTES:         while this version displays out arguments and explains the basics, the arguments are
               not yet in any functions for manipulation.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-12-2017     command_line_v1.cpp
----------------------------------------------------------------------------- */

// Test program for reading command-line parameters

#include <iostream>

using namespace std;



/*--------------------------------------------------------------------------------------
* FUNCTION NAME: int main ()
* PURPOSE: Holds main code for running program and calling other functions
* RETURNS: 0 for true, 1 for false
* NOTE: holds two command line parameters and a call to void clear_screen function.
* --------------------------------------------------------------------------------------*/
void clear_screen();

//      "main ()" function --- the program's entry point 
//      int argc        // Number of paramenteres on the command line
//      char *argv[]    // An array of pointers to C-strings


int main (int argc, char *argv[])
{
    clear_screen();
        
    for (int i = 0; i < argc; ++i)
    {
         cout << "Command line parameter " << i
        << " = " << argv[i] << endl;
    }


    cout << endl;

    return 0;       // 0 = success

}



/*--------------------------------------------------------------------------------------
* FUNCTION NAME: void clear_screen()
* PURPOSE: Calls code that outputs clear space on a command terminal 
* RETURNS: NA - void 
* NOTE: used for readability of program once it is begin run.
* --------------------------------------------------------------------------------------*/
void clear_screen()
{
    for (int i = 0; i < 50; i++)
        cout << endl;
}


