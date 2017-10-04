/*   -----------------------------------------------------------------------------
FILE NAME:         Pointer2.CPP
DESCRIPTION:       This c++ code uses multiple pointer arrays to display the information
                   that is stored in both an int variable and a character array
PURPOSE:           This file contains the .cpp code that once complied runs the 'Pointers2' program
USAGE:             from the 'Lab1' folder run "make Pointers2.cpp", this will compile the .cpp file, 
                   once the file is compiled type "./Pointers2" to display the compiled code
EXAMPLES:          ./Pointers2
PARAMETERS:        to edit the .cpp or Makefile: vim (name of file), to compile: make (nameofcpp file)
EXIT CODES:        No exit codes
COMPILATION:       Tools used were vim editor, putty ssh command line, and Ubuntu terminal.
NOTES:             
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-05-2017     1.0
Tanner_Benavides  09-05-2017     2.0
----------------------------------------------------------------------------- */

//< This program stores the address of a variable in a pointer
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main ()
{
	
	int x = 25;//int variable
    int numberCounter;
	int* ptr = NULL; 	// Pointer variable, can point to an int
	ptr = &x;       // Store the address of x in ptr
	char My_Name[] = "Tanner Benavides"; // Character array for name
	char* charptr = nullptr; // char pointer for char array
	charptr = My_Name; // no &, array already point to beginning address	
    int nameLen = strlen(My_Name); // stores length of char array

    cout << "The hex address of x is: " << ptr << endl;
    cout << "The dec address of x is: " << (long long) ptr << endl;
    cout << "The size of ptr is " << sizeof(ptr) << " bytes \n\n";

	cout << "The size of  x is " << sizeof(x) << " bytes \n";
	cout << "The value of x is " << x << endl;

    cout << endl;
	cout << "My Name is ";
	for (int i = 0; i < nameLen ; i++)
		cout << My_Name[i];

	cout << endl; 

	cout << "The  size  of My_Name is " << setw(2) <<  sizeof(charptr) << " bytes \n";
	cout << "The length of My_Name is " << setw(2) <<  nameLen << " bytes \n\n";

    for (int i = 0; i <= nameLen; i++)
        {
            cout << "Char " << setw(2) << (i+1) << " is " << setw(2) << My_Name[i] << " at address: " << (long long) &My_Name[i];
            cout << " with value of: " << setw(4) << int(My_Name[i]) << endl;
        }

    cout << endl;

    for (int i = 0; i <= nameLen; i++)
        {
            cout << "Char " << setw(2) << (i+1) << " is " << setw(2) << charptr[i] << " at address: " << (long long) (charptr + i);
            cout << " with value of: " << setw(4) << int(charptr[i]) << endl;
        }

	return 0;
}


