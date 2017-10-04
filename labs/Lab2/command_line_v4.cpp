/*   ----------------------------------------------------------------------------
FILE NAME:     command_line_v4.cpp
DESCRIPTION:    expanded 'command_line_vx.cpp' file that builds upon the three previous versions of
                the program by fixing issues with the previous version including incorrectly implimented
                bool check for a '/' 'SLASH' at the beginning of the arguments, the for loop running 
                through the 'valid_options[]' array correctly going from ? to W in the list of approved 
                letters, and better output of the arguments showing, invalid arguments, and correct 'Option'
                and 'Value' of each correctly inputed argument
PURPOSE:       .cpp file holding the code compiled to the executable command_line_v4
USAGE:         compile this file into an executable by using the make file in Lab2, run the 
                compiled file along with multiple parameters to test the functionality
EXAMPLES:      from terminal: $make command_line_v4, then: ./command_line_v4
PARAMETERS:    can use any text parameters listed as the programs only function is to list them
EXIT CODES:    0 = success
COMPILATION:   g++ -0, -std=gnu++11,

NOTES:         this version of command_line programs can check for user inputted arguments 
                (beyond the always present first argument), uses bool and pointers to attempt to run
                through verifications for correct argument input. and lists all arguments valid or invalid
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-12-2017     command_line_v1.cpp
Tanner_Benavides  09-12-2017     command_line_v2.cpp
Tanner_Benavides  09-14-2017     command_line_v3.cpp
Tanner_Benavides  09-14-2017     command_line_v4.cpp
----------------------------------------------------------------------------- */


#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// Prototypes
void check_arg(char[]);

//      "main ()" function --- the program's entry point 
//      int argc        // Number of paramenteres on the command line
//      char *argv[]    // An array of pointers to C-strings




 /*--------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and a call to void check_arg function. which checks the 
 *command line parameters inputed and does a cout of the validity.
 * --------------------------------------------------------------------------------------*/

int main (int argc, char *argv[])
{
        
    cout << endl;

    for (int i = 0; i < argc; ++i) 
    {
        cout << "Argument " << i << " : " << left << setw(16) << argv[i];
        if (i) check_arg(argv[i]); // if argument is true (above 0, which is Argument:0, or ./command
        else cout << endl;
    }

    cout << endl;


        return 0;       // 0 = success

}


/*--------------------------------------------------------------------------------------
* FUNCTION NAME: void check_arg()
* PURPOSE: Calls code that takes checks a passed char array (from int main() parameter
*          and check for certain conditions, outputting a message a validity to the user.
* RETURNS: NA - void 
* NOTE: holds the bulk of the code for this program running the parameters stored in an
*       array and checking them with bool statements and character checks.
* --------------------------------------------------------------------------------------*/

void check_arg(char arg[]) // char arg[] obtains argv[] array.
{
    char buf[100]; 
    const char SLASH = '/';
    char valid_options[] = "?ABCDFILMNOPRSTW";
    char* p = valid_options; // pointer to beginning address of valid_options array
    bool first_char = arg[0] == SLASH; // Test paramenter's 1st char
    bool second_char = false; // test parameter's 2nd char

    for (; *p !=0; ++p) // ; basically means 'while', so while dereferenced pointer is not /0, loop
    {
        second_char = arg[1] == *p; // as it loops, if 2nd char of arg[] is equal to any of the 
                                    // valid options then second car will set to true.
        if (second_char == true) break;
    }

    if(!first_char || !second_char) // if either first_char set to 0 from no SLAHS or second char was
                                    // not a valid_option, then its invalid.
        cout << "Invalid argument" << endl;

    else
    {
        cout << "Option: " << *p;
        if(arg[2] != 0) // Look for a string
        {
            strcpy(buf, arg+2); // Save string to buffer (minus the /and valid ?ABCDFILMNOPRSTW
            cout << " Value: " << buf;
        }
        cout << endl;
    }
}


