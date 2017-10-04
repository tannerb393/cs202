// This program stores the addres of a variable in a pointer
#include ioddress of x is: " << ptr << endl;
        cout << "The dec address of x is: " << (long long) ptr << endl;
        cout << "The size of ptr is " << size of(ptr) << " bytes\n";

        cout << endl;
stream>
using namespace std;



int main ()
{
	int x = 25; 	//int variable 
	int *ptr = nullptr; 	// Pointer variable, can point to an int

	cout << "The hex address of x is: " << ptr << endl;
	cout << "The dec address of x is: " << (long long) ptr << endl;
	cout << "The size of ptr is " << size of(ptr) << " bytes\n";

	cout << endl;	

	ptr = &x; 	// Sotre the address of x in ptr 
	cout << "The value in x is " << x << endl;
	cout << "The address of x is " << ptr << endl;

	return 0;

}
