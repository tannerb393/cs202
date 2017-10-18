// poly_struct_v3.cpp
// Test program for polynomials implemented as structures

// Version 1 ... Basic version
// Version 2 ... Accessing the polynomial array using pointers
// Version 3 ... Passing and returning members of the polynomial array

#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

struct Polynomial
{
    int degree; 		// Degree of the polynomial
    int coef[9]; 		// Array of coefficients
};

// Function prototypes go here

void init_poly(Polynomial *);
void get_poly(Polynomial *);
void display_poly(Polynomial *);
Polynomial Add_2_Polynomials(Polynomial, Polynomial);


// "main()" function --- the program's entry point
//    int argc      	// Number of parameters on the command line
//    char *argv[]  	// An array of pointers to C-strings 

int main(int argc, char * argv[])
{
    Polynomial poly[3];

    for (int n=0; n < 3; n++)  init_poly(poly+n);

    for (int n=0; n < 2; n++)
    {
	get_poly(poly+n);
	display_poly(poly+n);
    }

    poly[2] = Add_2_Polynomials(poly[0], poly[1]);

    display_poly(poly+2);

    return 0;
}

void init_poly(Polynomial *p)
{
    p->degree = 0;

    for (int i = 0; i < ARRAY_SIZE(p->coef); i++)
        p->coef[i] = 0;
}

void get_poly(Polynomial *p)
{
    cout << "\nEnter degree of polynomial: ";
    cin >> p->degree;

    cout << "\nEnter the " << p->degree+1 << " coefficients: ";

    for (int i = p->degree; i >= 0; i--)
        cin >> p->coef[i];
}

void display_poly(Polynomial *p)
{
    cout << "\n\t";			//  Display polynomial

    for (int i = p->degree; i >= 0; i--)
    {
	if (i < p->degree)
	{
	    if (p->coef[i] >= 0) cout << " +";
	    else cout << " ";
	}
	cout << p->coef[i];

	if (i>1) cout << "x^" << i ;
	if (i==1) cout << "x";
    }
    cout << endl;
    cout << endl;
}

Polynomial Add_2_Polynomials(Polynomial p0, Polynomial p1)  // Passes & returns
{						       // polynomial structures
    Polynomial p2;

    cout << "\nAdding the 2 polynomials: \n\n";

    p2.degree = MAX(p0.degree, p1.degree); 

    for (int i = p2.degree; i >= 0; i--)
        p2.coef[i] = p0.coef[i] + p1.coef[i];

    return p2;
}

