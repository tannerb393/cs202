//Polynomial.cpp
//Implenmentation file for Polynomial Class


#include "Polynomial.h"

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
   // cout << "\n\t";			//  Display polynomial

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


// Overloaded binary + operator
Polynomial Polynomial::operator + (const Polynomial &p1)
{
    Polynomial p2;

    cout << "\nADDING 2 Polynomials: ";

    p2.degree = MAX(degree, p1.degree);

    for(int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];

    return p2;
}
