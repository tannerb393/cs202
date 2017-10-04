
/*   -----------------------------------------------------------------------------
FILE NAME:         Pointer.CPP
DESCRIPTION:       This c++ code uses a pointer to display the information
                   that is stored in an int variable
PURPOSE:           This file contains the .cpp code that once complied runs the 'Pointers' program
USAGE:             from the 'Lab1' folder run "make Pointers.cpp", this will compile the .cpp file, 
                   once the file is compiled type "./Pointers" to display the compiled code
EXAMPLES:          ./Pointers
PARAMETERS:        to edit the .cpp or Makefile: vim (name of file), to compile: make (nameofcpp file)
EXIT CODES:        No exit codes
COMPILATION:       Tools used were vim editor, putty ssh command line, and Ubuntu terminal.
NOTES:             
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-05-2017     1.0
----------------------------------------------------------------------------- */

//< This program stores the addres of a variable in a pointer
#include <iostream>
using namespace std;



int main ()
{
	
	int x = 25; 	//int variable 
	int *ptr = nullptr; 	// Pointer variable, can point to an int
	ptr = &x;       // Sotre the address of x in ptr

	
        cout << "The hex address of x is: " << ptr << endl;
        cout << "The dec address of x is: " << (long long) ptr << endl;
        cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";

        cout << endl;

	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << ptr << endl;

	return 0;

}
