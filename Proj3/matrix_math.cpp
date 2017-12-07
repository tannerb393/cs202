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


void help();

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
    char x;
    string args[6];
    ifstream infile;
    double k;

    Matrix<double> mat1;
    Matrix<double> mat2;
    Matrix<double> mat3;



   stringstream ss[6];
   for (int i = 0; i < argc; i++){
       ss[i] << argv[i];
       ss[i] >> args[i];}

    if (args[1] == "-h"){
       help();  
       return 0;    }

    if (argc < 3 || argc > 6)
    {
        cout << "Invalid Argument Count \n\n";
        return 0;
    }

    args[2] += ".mtx";
    infile.open(args[2].c_str());
    if(!infile)
    {   cout << "Error opening file 1: " << args[2] << endl;
        return 0;   }
    infile.close();

    if (argc > 3)
      { args[3] += ".mtx";
        infile.open(args[3].c_str());
        if(!infile)
         {   cout << "Error opening file 2: " << args[3] << endl;
             return 0;  }
        infile.close();  }

    if (argc == 6 && args[4] == "-out")
      { args[5] += ".mtx";
          fstream checkf;
          checkf.open(args[5].c_str(), ios::out | ios::app);
          checkf.close();
          ifstream infile;
        infile.open(args[5].c_str());
        if(!infile)
         {   cout << "Error opening save file: " << args[3] << endl;
             return 0;  }
        infile.close();  
        cout << " 5 ";
      }

    Matrix<double> pass1(args, 2, argc);
    mat1 = pass1;
    if (argc > 3)
    { Matrix<double> pass2(args, 3, argc);
      mat2 = pass2; }  

    if (args[1] == "-inp")
        cout << mat1;


    if (mat1.sizecheck(mat2))
    {

        if (args[1] == "-add")
        {  cout << "ADDING MATRIX 1 AND MATRIX 2\n";
           cout << mat1 << "        +\n" << mat2;
           mat3 = (mat1 + mat2);
           cout << "\n      ANSWER:";
           cout << mat3;    }

        if (args[1] == "-sub")
        {  cout << "SUBTRACTING MATRIX 1 AND MATRIX 2\n";
           cout << mat1 << "        -\n" << mat2;
           mat3 = (mat1 - mat2);
           cout << "\n      ANSWER:";
           cout << mat3;    }


       if (args[1] == "-eq")
        {  cout << "EQUALITY TEST OF TWO MATRICES\n";
           cout << mat1 << mat2;

          cout << "Matrix #1 ";
          if (mat1 == mat2)
            cout << "IS EQUAL ";
          else
            cout << "IS NOT EQUAL ";
          cout << "to Matrix #2]\n";    }
    }

    if (!mat1.sizecheck(mat2) && ((args[1] == "-add") 
                || (args[1] == "-sub") || (args[1] == "-eq")))
    {
        cout << "EXIT! Rows Size for Matrix 1 & 2 Must Match for this math command\n";
        cout << "EXIT! Column Size for Matrix 1 & 2 Must Match for this math command\n";
        return 0;
    }


    if (args[1] == "-mul" && (mat1.mulsizecheck(mat2)))
    {  cout << "MULTIPLYING MATRIX 1 AND MATRIX 2\n";
       cout << mat1 << "        *\n" << mat2;
       mat3 = (mat1 * mat2);
       cout << "\n      ANSWER:\n";
       cout << mat3;    }

    if (!mat1.mulsizecheck(mat2) && (args[1] == "-mul"))
    {
        cout << "EXIT! Column Size of Matrix 1 \n";
        cout << "     Must Match Rows Size of Matrix 2 for -mul command\n";
        return 0;
    }   


   if (args[1] == "-T")
   {   cout << "TRANSPOSING MATRIX " << args[2] << endl;
       cout << mat1 << "    TRANSPOSED\n";
       mat1.trans();  }

   if (args[4] == "-out")
   {   
       cout << "COPYING RESULTS TO: " << args[5];
       mat3.out();
   }



    return 0;

}/*}}}*/

/*{{{*/ /*{{{*/ //-------------void help() ------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
void help()
{/*{{{*/
     cout << "\n                         matrix_math HELP MENU \n\n\n";
     cout << "The matrix_math program is a command line based program using .mtx text files and commands \n";
     cout << "The .mtx matrix files are Named using capital letters A through Z\n";
     cout << "When enter the names of the .mtx files, enter the corresponding letter of the files\n";
     cout << "      Example: ./matrix_math -inp A\n";
     cout << "The following commands and the functions are commands that are compatible with the program:\n\n";
     cout << "'-h'      help command used to access this menu.\n";
     cout << "'-inp'    used in conjunction with a single .mtx file to display the stored matrix on screen\n";
     cout << "'-out'    use this command, as well as a letter A-Z, that will be used to name and create a\n";
     cout << "          .mtx save file. This command may be used following with the -add, -sub, -mul commands\n";
     cout << "'-add'    adds together two matrices, .mtx files entered following the -add command\n";
     cout << "'-sub'    subtracts one matrix from another, .mtx files entered following -sub command\n";
     cout << "'-mul'    multiplies together two matrices, .mtx files entered following the -mul command\n";
     cout << "'-eq'     the two .mtx files entered following the -eq command will be compared for equality\n";
     cout << "'-T'      transposes the matrix in the .mtx file following the -T command\n";
     cout << "'-l'      inverses the matrix in the .mtx file following the -l command\n";
     cout << "'-det'    calculates the determinate of the matrix in the .mtx file follow the -det command\n";
     cout << "'-solve'  solves a system of equations\n";
}/*}}}*/

