// poly_styruct_v1.cpp
// Test program for polynomials impemented as structures


// Version 1 ... Basic Version
//


#include <iostream>
#define MAX(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

struct Polynomial 
{
    int degree; // Degree of ply
    int coef[9]; // Array of coeff

};

// FUnction prototypes go here


void get_poly(Polynomial *);
void display_poly(Polynomial *);
void Add_2_Polynomial(Polynomial *);

// "main()" function --- the program's entry point
// int argc // number of paramenters
// char *argv[] // an array of pointer to c-strings

int main(int argc, char * argv[])
{
    Polynomial poly[3];

    for (int n=0; n<2; n++)
    {
        get_poly(& poly[n]);
        display_poly(& poly[n]);
    }

    Add_2_Polynomial(poly);

    display_poly(& poly[2]);

    return 0;
}

void get_poly (Polynomial *p)
{
    cout << "\nEnter Degree of polynomial: ";
    cin >> p->degree;

    cout << "\nEnter the " <<  p->degree+1 << " coefficients: ";

    for (int i = p->degree; i >= 0; i--)
           cin >> p->coef[i];
    
}

void display_poly(Polynomial *p)
{
    cout << "\n\t"; // display poly

    for (int i = p->degree; i >= 0; i --)
    {

        if (i < p->degree)
        {
            if (p->coef[i] >= 0) cout << " +";
            else cout << " ";

        }
        cout << p->coef[i];

        if (i>1) cout << "x^" << i;
        if (i==1) cout << "x";
    }

    cout << endl;
    cout << endl;
}

void Add_2_Polynomial(Polynomial *p) // Using array elements
{
    cout << "\nAdding the 2 polynomials: \n\n";
    p[2].degree = MAX(p[0].degree, p[1].degree);

    for (int i = p[2].degree; i >= 0; i--)
        p[2].coef[i] = p[0].coef[i] + p[1].coef[i];
}
