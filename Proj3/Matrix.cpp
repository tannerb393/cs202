/*{{{*/ /*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     Matrix.CPP
DESCRIPTION:   .CPP file for the poly_class program that 
PURPOSE:       holds bulk of the functions for the the class 'Matrix'
USAGE:         to be used alongside poly_class.cpp. must be compiled along with poly_class.cpp and Matrix.h
PARAMETERS:    int argc, char *argv[], but not used in this program
COMPILATION:   vim to write, and make file to compile: the linux command 'make -f Makefile poly_class'

NOTES:         many overloaded operators are used in this program to show example of how these operators can
                ben manipulated to work with classes.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  10-25-2017     1.0 / Matrix.cpp

//-----------------------------------------------------------------------------*/ 
/*}}}*/ /*}}}*/

#include "Matrix.h" // call to header file
//#include "Matrix.cpp" // Call to Classes


/*{{{*/ /*{{{*/ //-----------TEMP CLASS CONSTRUCTOR HEADER-----------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(int m_rows, int m_cols, string args[4], int argc)
{
    rows = m_rows;
    cols = m_cols;

        array = new T*[rows];

        for(int i = 0; i < rows; i++)
            array[i] = new T[cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
               array[i][j] = 0;
            }
        }
    for(int i = 0; i < argc; i++)
     m_args[i] = args[i];

cout << "Temp class Constructor (52 - Matrix.cpp)\n";

}/*}}}*/


/*{{{*/ /*{{{*/ //-------------MAIN OVERLOADED CONSTRUCTOR-----------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(string args[4], int c, int argc)
{
 
 ifstream infile;
  char let_x;

    m_argc = argc;

    for(int i = 0; i < argc; i++)
    {
       m_args[i] = args[i];
    //   cout << m_args[i] << endl;
    }

        infile.open(args[c].c_str());
        infile >> rows >> let_x >> cols;

        array = new T*[rows];

        for(int i = 0; i < rows; i++)
            array[i] = new T[cols];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                infile >> array[i][j];
            }

        }
    infile.close();

    cout << "Matrix overloaded constructor: (95 - Matrix.cpp) \n\n";
    cout << "      " << args[c] << endl;
    cout << "      " << rows << " x " << cols;

    
}/*}}}*/


/*{{{*/ /*{{{*/ //------ Matrix get() -----------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template<class T>
T Matrix<T>::get (int i, int j)
{
  //  cout << "get test\n";
    return array[i][j];
}/*}}}*/


/*{{{*/ /*{{{*/ //-------------- << operator ----------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T1>
ostream &operator << (ostream &strm, Matrix<T1> &m1)
{
   strm << endl;
   for (int i = 0; i < m1.rows; i++)
   {
       for (int j = 0; j < m1.cols; j++)
            {
                strm << setw(4) << m1.get(i, j);
            }
   strm << endl;
   }
strm << endl;

return strm;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ >> operator ------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T1>
istream &operator >> (istream &strm, Matrix<T1> &m1)
{


    /*
    cout << "\n[Enter degree of Matrix]: ";
    strm >> m1.degree;
    cout << m1.degree;
    while (strm.fail())
    { cout << "Please enter Matrix degree integer 1-9!\n";
      strm >> m1.degree;
    }
    cout << "\n[Enter " << m1.degree + 1 << " coeficient(s)]: ";
    for (int i = m1.degree; i >= 0; i--)
    {strm >> m1.coef[i];
        cout << m1.coef[i] << ", ";
        while (strm.fail())
        { cout << "Please enter Matrix degree integer 1-9!\n";
          strm >> m1.coef[i];
        }
    }
    cout << endl;
*/



}/*}}}*/


/*{{{*/ /*{{{*/ //------------ + operator---------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/  //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator + (Matrix<T> &m1)
{
  Matrix<double> m2(rows, cols, m_args, m_argc);

 // cout << "m2 created in + operator (187 - Matrix.cpp)\n";
 // cout << m2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (m1.array[i][j] + array[i][j]);
    }
    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //----------- - operator --------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator - (Matrix<T> &m1)
{
  Matrix<double> m2(rows, cols, m_args, m_argc);

 // cout << "m2 created in - operator (210 - Matrix.cpp)\n";
 // cout << m2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (m1.array[i][j] - array[i][j]);
    }
    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------- * operator -------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator * (Matrix<T> &m1)
{
  Matrix<double> m2(rows, cols, m_args, m_argc);

 // cout << "m2 created in - operator (210 - Matrix.cpp)\n";
 // cout << m2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (m1.array[i][j] * array[i][j]);
    }
    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ = operator----------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*///------------------------------------------------------------------------
template <class T>
void Matrix<T>::operator = (const Matrix<T> &m1)
{

   rows = m1.rows;
   cols = m1.cols;

    for(int i = 0; i < m1.m_argc; i++)
     m_args[i] = m1.m_args[i];


    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
           array[i][j] = m1.array[i][j];
        }
    }

    cout << " = Operator (238 - Matrix.cpp)\n";
}/*}}}*/


/*{{{*/ /*{{{*/ //---------- == operator ---------------------------------------
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
bool Matrix<T>::operator == (const Matrix<T> &m1)
{

    bool equal = true;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
           if(m1.array[i][j] != array[i][j])
           {
               equal = false;
               break;
           }

    }

     return equal;
} /*}}}*/


/*{{{*/ /*{{{*/
/*
-------------------------------------------------------------------------------------
*FUNCTION:operator -- ()
*PURPOSE: fuction obtains the derivative of the matrix stored in the class object
*RETURNS: NA
*NOTE: using for loop multiplies the coef by the current degree and moves each coef down a power
*--------------------------------------------------------------------------------------
template <class T>
Matrix Matrix<T>:: operator -- ()
{
int coefTemp[100];

for (int i = degree; i >= 0; i--) 
    coefTemp[i] = coef[i] * i;

 for (int i = degree; i >= 1; i--) 
    coef[i - 1] = coefTemp[i];
 --degree;

}


-------------------------------------------------------------------------------------
*FUNCTION:operator ++ (int)
*PURPOSE: does a definite integral, similar to previous function but uses upper and lower bounds
*RETURNS: NA
*NOTE: works like the '()' overloaded operator and then subtracts matrix #2 from #1
*--------------------------------------------------------------------------------------
template <class T>
Matrix Matrix<T>::operator ++(int)
{
    double sum1 = 0;
    double sum2 = 0;
    double min = 0;
    double max = 0;

    cout << "\nDefine Beginnig Range for the Definite Integral: ";
    cin >> min;
    cout << min;
    cout << "\nDefine End Range for the Definite Integral: ";
    cin >> max;
    cout << max;
        
    for (int i = degree; i >= 0; i--) 
      sum1 += coef[i] * (pow (min, i));

    for (int i = degree; i >= 0; i--) 
      sum2 += coef[i] * (pow (max, i));

    sum = sum2 - sum1;


}

-------------------------------------------------------------------------------------
*FUNCTION:operator == ()
*PURPOSE: overloads the == to see if the matrix stored in two objects are the same
*RETURNS: true/false
*NOTE: check the value stored in each degree level and returns false if even one of them does not match
*--------------------------------------------------------------------------------------
template <class T>
bool Matrix<T>::operator == (const Matrix &m1)
{

    bool equal = true;

    for(int i = 0; i <= m1.degree; i++){
       // cout << "m2= " << coef[i] << " m1=" << m1.coef[i] << endl; 
       if(coef[i] != m1.coef[i]){
           equal = false;
           break;
       }
    }
    return equal;
}


-------------------------------------------------------------------------------------
*FUNCTION:operator ()
*PURPOSE: used to assign value to the 'x' displayed in the matrixs of the class objects
and then sum up and solve the matrix storing the answer in the 'sum' private member
*RETURNS: NA
*NOTE: uses the 'pow' power function to take the 'x' to a power then multiplies with the coef[i] 
*--------------------------------------------------------------------------------------
template <class T>
Matrix Matrix<T>::operator () (int x)
{
for (int i = degree; i >= 0; i--) 
  sum += coef[i] * (pow (x, i));
}
*/
/*}}}*/ /*}}}*/

