/*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     mtrx_class.cpp
DESCRIPTION:   .cpp file which is main .cpp for the mtrx_class programs. holds int main () and other non-class functions 
PURPOSE:       for connection the actions of the header file 'Matrix.h' and 'Matrix.cpp'
USAGE:         must be compiled along with Matrix.h and Matrix.cpp
COMPILATION:   vim to write, and make file to compile: the linux command 'make -f Makefile matrx_class'
NOTES:         uses the int main () function to give call all other functions in a linear method to show all the functionality
                of the Class member functions, and variables. user input is limited to some basic calls for degree values,
                coeficcient values, x value, and ranges for integrals.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  10-25-2017     1.0 / mtrx_class.cpp
Tanner_Benavides  11-1-2017     2.0 / mtrx_class.cpp
//-----------------------------------------------------------------------------*/ 
/*}}}*/
//#include "Matrix.h" // call to header file
#include "Matrix.cpp" // Call to Classes


/*{{{*/ /*{{{*//*-------------FUNCTION HEADER---------------------------------------------------*/
//FUNCTION: int main ()
//PURPOSE: holds majority of code to call other functions 
//RETURNS: 0 to end program 
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{/*{{{*/

    int *ptr = 0;
    int m, n;
    char let_x;
    string args[4];
    ifstream infile;
    double k;

 //   cout << argc << endl;

   stringstream ss[4];
   for (int i = 0; i < argc; i++){
       ss[i] << argv[i];
       ss[i] >> args[i];}

    if (argc < 3)
    {
        cout << "Not Enough Arguments! \n\n";
        return 0;
    }


    args[2] += ".mtx";
    infile.open(args[2].c_str());
    if(!infile)
    {   cout << "Error opening file 1: " << args[2] << endl;
        return 0;
    }
    infile.close();
    if (argc == 4)
    {
        args[3] += ".mtx";
        infile.open(args[3].c_str());
        if(!infile)
         {   cout << "Error opening file 2: " << args[3] << endl;
             return 0;
         }
        infile.close();
    }


    if (args[1] == "-inp")
    {
       cout << "-inp (72 - matrix_math)\n";
       Matrix<double>mat1(args, 2, argc);
       cout << mat1;
    }


    if (args[1] == "-add")
    {
       cout << "ADDING MATRIX 1 AND MATRIX 2\n";
       Matrix<double>mat1(args, 2, argc);
       cout << mat1;
       Matrix<double>mat2(args, 3, argc);
       cout << mat2;
/*       Matrix<double>mat3(args, 2, argc);
       cout << mat3;
       mat3 = mat2 + mat1; */ //WTF WHY NO WORKY?
       Matrix<double>mat3 = mat2 + mat1;
       cout << "\n      ANSWER:";
       cout << mat3;
    }

    if (args[1] == "-sub")
    {
       cout << "SUBTRACTING MATRIX 1 AND MATRIX 2\n";
       Matrix<double>mat1(args, 2, argc);
       cout << mat1;
       Matrix<double>mat2(args, 3, argc);
       cout << mat2;
       Matrix<double>mat3 = mat2 - mat1;
       cout << "\n      ANSWER:";
       cout << mat3;
    }

    if (args[1] == "-mul")
    {
       cout << "MULTIPLYING MATRIX 1 AND MATRIX 2\n";
       Matrix<double>mat1(args, 2, argc);
       cout << mat1;
       Matrix<double>mat2(args, 3, argc);
       cout << mat2;
       Matrix<double>mat3 = mat2 * mat1;
       cout << "\n      ANSWER:";
       cout << mat3;
    }

   if (args[1] == "-eq")
    {
       cout << "EQUALITY TEST OF TWO MATRICES\n";
       Matrix<double>mat1(args, 2, argc);
       cout << mat1;
       Matrix<double>mat2(args, 3, argc);
       cout << mat2;

      cout << "Matrix #1 ";
      if (mat1 == mat2)
        cout << "IS EQUAL ";
      else
        cout << "IS NOT EQUAL ";
      cout << "to Matrix #2]\n";
    }




 //   mat1.display();

 //   infile.close();

    return 0;

/*{{{*/
/*
    Matrix mtrx[5]; 
    int x = 0;

    for (int i = 0; i < 2; i++) 
    {
        cin >> mtrx[i];
        cout << "matrix #" << i+1 << " is: ";
        cout << mtrx[i] << endl;
        cout << endl;
    }

        cout << "[Matrix #1 ";
        if (mtrx[0] == mtrx[1])
            cout << "IS EQUAL ";
        else
            cout << "IS NOT EQUAL ";
        cout << "to Matrix #2]\n";

        mtrx[2] = mtrx[0] + mtrx[1];
        cout << mtrx[2] << endl << endl;

        mtrx[2] = mtrx[0] - mtrx[1];
        cout << mtrx[2] << endl << endl;

        mtrx[2] = mtrx[0] * mtrx[1];
        cout << mtrx[2] << endl << endl;

        cout << "\nSet Value for variable x: \n";
        cin >> x;
        mtrx[0](x);
        cout << "Answer for Matrix #1 given f(" << x << ") : ";
        mtrx[0].displayTotal();
        mtrx[1](x);
        cout << "Answer for Matrix #2 given f(" << x << ") : ";
        mtrx[1].displayTotal();

        mtrx[2] = mtrx[0];
        --mtrx[2];
        cout << "\n[DERIVATIVE OF " << mtrx[0] << " ]" << endl;
        cout << mtrx[2] << endl;
        mtrx[2] = mtrx[1];
        --mtrx[2];
        cout << "\n[DERIVATIVE OF " << mtrx[1] << " ]" << endl;
        cout << mtrx[2] << endl;

        mtrx[3] = mtrx[0];
        ++mtrx[3];
        cout << "\n[INTEGRAL OF " << mtrx[0] << " ]" << endl;
        cout << mtrx[3] << endl;
        mtrx[4] = mtrx[1];
        ++mtrx[4];
        cout << "\n[INTEGRAL OF " << mtrx[1] << " ]" << endl;
        cout << mtrx[4] << endl;

        mtrx[3]++;
        cout << "\n[Solution for the DEFINITE INTEGRAL OF " << mtrx[0] << "] \n ";
        mtrx[3].displayTotal();
        mtrx[4]++;
        cout << "\n[Solution for the DEFINITE INTEGRAL OF " << mtrx[1] << "] \n ";
        mtrx[4].displayTotal();

  //  cout << setprecision(2) << fixed << showpoint;
*/
/*}}}*/

}/*}}}*/

/*{{{*/ /*{{{*//*-------------FUNCTION HEADER---------------------------------------------------*/
//FUNCTION: int main ()
//PURPOSE: holds majority of code to call other functions 
//RETURNS: 0 to end program 
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
int intChoice()
{/*{{{*/
    int choice = 0;
	cout << "Please enter a valid numerical choice(1-9): ";
	cin.clear();
	cin.ignore(100, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

/*{{{*/ /*{{{*//*-------------FUNCTION HEADER---------------------------------------------------*/
//FUNCTION: int main ()
//PURPOSE: holds majority of code to call other functions 
//RETURNS: 0 to end program 
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
void clearIt()
{/*{{{*/
	cin.clear();
	cin.ignore(100, '\n');
}/*}}}*/


