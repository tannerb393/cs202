// poly_class_v1.cpp
// Test program for polynomials implemented as structures

// Version 1 ... Basic version
// Version 2 ... Accessing the polynomial array using pointers
// Version 3 ... Passing and returning members of the polynomial array

#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial
{
    private:
    int degree; 		// Degree of the polynomial
    int coef[9]; 		// Array of coefficients

    public:
    Polynomial(); // constructor
    void get_poly();
    void display_poly();
    void Add_2_Polynomials(Polynomial, Polynomial);
};

// Function prototypes go here


// "main()" function --- the program's entry point
//    int argc      	// Number of parameters on the command line
//    char *argv[]  	// An array of pointers to C-strings 

int main(int argc, char * argv[])
{
    Polynomial poly[3];

    for (int n=0; n < 2; n++)
    {
	poly[n].get_poly();
	poly[n].display_poly();
    }

    poly[2].Add_2_Polynomials(poly[0], poly[1]);
    poly[2].display_poly();

    cout<< endl;

    return 0;
}

Polynomial::Polynomial() // constructor // Initailize all values at 0
{
    degree = 0;

    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}

void Polynomial::get_poly()
{
    cout << "\nEnter degree of polynomial: ";
    cin >> degree;

    cout << "\nEnter the " << degree+1 << " coefficients: ";

    for (int i = degree; i >= 0; i--)
        cin >> coef[i];
}

void Polynomial::display_poly()
{
    cout << "\n\t";			//  Display polynomial

    for (int i = degree; i >= 0; i--)
    {
	if (i < degree)
	{
	    if (coef[i] >= 0) cout << " +";
	    else cout << " ";
	}
	cout << coef[i];

	if (i>1) cout << "x^" << i ;
	if (i==1) cout << "x";
    }
    
    cout << endl;
}

void Polynomial::Add_2_Polynomials(Polynomial p0, Polynomial p1)  // Passes & returns
{						       // polynomial structures
    
    cout << "\nAdding the 2 polynomials: \n\n";

    degree = MAX(p0.degree, p1.degree); 

    for (int i = degree; i >= 0; i--)
        coef[i] = p0.coef[i] + p1.coef[i];
}

