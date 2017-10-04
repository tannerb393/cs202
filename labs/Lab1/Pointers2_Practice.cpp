//< This program stores the address of a variable in a pointer
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;


// Function Prototypes
// void doubleValue(int*);


int main ()
{
	
	int x = 25;//int variable
    int numberCounter;
	int* ptr = NULL; 	// Pointer variable, can point to an int
    // int* dynamicIntArray = nullptr;
	ptr = &x;       // Store the address of x in ptr
	char My_Name[] = "Tanner Benavides"; // Character array for name
	char* charptr = nullptr;
	charptr = My_Name;	
    int nameLen = strlen(My_Name); 

        cout << "The hex address of x is: " << ptr << endl;
        cout << "The dec address of x is: " << (long long) ptr << endl;
        cout << "The size of ptr is " << sizeof(ptr) << " bytes \n";

        cout << endl;

	cout << "The size of x is " << sizeof(x) << " bytes \n";
	cout << "The value of x is " << x << endl;

	cout << endl;

	cout << "My Name is ";
	for (int i = 0; i < nameLen ; i++)
		cout << My_Name[i];
	cout << endl; 

	cout << "The size of My_Name is " <<  sizeof(charptr) << " bytes \n";
	cout << "The length of My_Name is " << nameLen << " bytes \n\n";

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

/*
    cout << "BEGINNING OF PRACTICE CODE \n\n";

	cout << "The value of *ptr = " << *ptr << endl;
	cout << "The value of ptr = " << ptr << endl;
	cout << "x = " << x << endl;
	*ptr = 100;
	cout << "After changing *ptr to equal 100 we see that ";
	cout << "*ptr = " << *ptr << ", and x = " << x << ", but ptr still = " << ptr << endl;
	cout << "address form of x variable, &x = " << &x << endl;
	cout << "The size of x = " << sizeof(x) << endl;


    cout << "spelling out My_Name using the *(My_Name + count) method \n"; 
    for (int i = 0; i < nameLen; i ++)
        cout << *(My_Name + i);
    cout << endl;

    //steps through char array comparing pointer to address loc of My_Name
    //?? tried charptr += 4; first but only need to increase address by one, isnt 
    //address of each character in char array 4 bits of address?

    cout << "name again is : ";
    cout << *charptr;
    while (charptr < &My_Name[nameLen])
        {
            charptr ++;
            cout << *charptr;
        }

    cout << endl;
    
    doubleValue(&x); // call function to pass address of x and change x using pointer in func

    // uses dynamic memory allocation to creat an int array, set a pointer to it and
    // input a size of the array by the user.
    cout << "Enters numbers to creat dynamic int Array and count up: ";
    cin >> numberCounter;
    cout << endl;

    dynamicIntArray = new int[numberCounter];

    for (int i = 1; i <= numberCounter; i++)
        dynamicIntArray[i] = i;
    for (int i = 1; i <= numberCounter; i++)
        cout << " " << dynamicIntArray[i] << " ";
    cout << endl;
*/

	return 0;


}

/*

// void function that pulls the address of 'x', puts in point pntx, dereferences using *pntx, 
// and then doubles and displays dereferenced pntx which dobles x to 200
void doubleValue (int* pntx)
{
    cout << "the function 'doubleValue' was called and doubles x, x is now = ";
    *pntx *= 2;
    cout << *pntx << endl;
}

*/    

