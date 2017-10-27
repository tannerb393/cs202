// poly_class_v2.cpp
// Test program for polynomials implemented as classes
//
// Version 1 Poly_struct.cpp coverted to a class implementation
// Version 2 poly_class broken into 3 files
//      Tihs is the driver
//
#include "Polynomial.h" // Specification FIle

//#include "Polynomial.cpp" // Implementation file 

// "main()" function === the program's entry point
// int argc
// char *argv[]

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


