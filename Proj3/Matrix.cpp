/*{{{*/ /*{{{*/
 /* --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     Matrix.cpp
DESCRIPTION:   .cpp file for the matrix_math program that 
PURPOSE:       holds bulk of the functions for the the class 'Matrix'
USAGE:         to be used alongside matrix_math.cpp. must be compiled along with matrix_math.cpp and Matrix.h
PARAMETERS:    int argc, char *argv[]
COMPILATION:   vim to write, and make file to compile: the linux command 'make matrix_math'

NOTES:         make use of both class and template classes, uses member class functions with
                mathmatical manipulators to modify and combine matrices. Overloaded operators
                are also used to perform the changes and actions on the matrices, which are stored
                in the .mtx files.
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  11-28-2017     1.0 / Matrix.cpp
Tanner_Benavides  12-01-2017     2.0 / Matrix.cpp

//-----------------------------------------------------------------------------*/ 
/*}}}*/ /*}}}*/

#include "Matrix.h" // call to header file
//#include "Matrix.cpp" // Call to Classes

/*{{{*/ /*{{{*/ //----------- COPY CONSTRUCTOR --------------------------------
//FUNCTION: Matrix (Copy Constructor)
//PURPOSE: uses the '=' symbol between ojbects to copy the member data between
//RETURNS: NA
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(const Matrix<T> &m1) // COPY CONSTRUCTOR
{
   // copy constructor in the program, but is not used ever.
   rows = m1.rows;
   cols = m1.cols;

    for(int i = 0; i < m1.m_argc; i++)
     m_args[i] = m1.m_args[i];

    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
           array[i][j] = m1.array[i][j];
           cout << array[i][j] << endl;
        }
    }

}/*}}}*/

/*{{{*/ /*{{{*/ //-----------TEMP CLASS CONSTRUCTOR HEADER-----------------------------
//FUNCTION: Matrix (Overloaded Construcor)
//PURPOSE: used as an overloaded contructor for 'temporary' class members created in operators
//RETURNS: NA
//NOTE: used in overloaded operator like  '+' '*' '-'
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(int m_rows, int m_cols, string args[6], int argc)
{
    rows = m_rows;
    cols = m_cols;
    m_argc = argc;

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
}/*}}}*/


/*{{{*/ /*{{{*/ //----------- MAIN CONSTRUCTOR ---------------------------------
//FUNCTION: Matrix (Main constructor)
//PURPOSE: Basic (main) constructor which sets defaults for new Class memebers
//RETURNS: NA
//NOTE: initializes main memebers int main() before the assgnment operator is used
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix()
{
    rows = 0;
    cols = 0;
    m_argc = 0;

        array = new T*[rows];

        for(int i = 0; i < rows; i++)
            array[i] = new T[cols];

}/*}}}*/


/*{{{*/ /*{{{*/ //-------------MAIN OVERLOADED CONSTRUCTOR-----------------------------
//FUNCTION: Matrix (Overloaded Constructor)
//PURPOSE: overloaded constructor used to to initiate the two main objects of Matrix when
//          a two .mtx file input operations is chosen, like -add or -mul
//RETURNS: NA
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(string args[6], int c, int argc)
{
 ifstream infile;
  char let_x;

    m_argc = argc;

    for(int i = 0; i < argc; i++)
    {
       m_args[i] = args[i];
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
}/*}}}*/


/*{{{*/ /*{{{*/ //------ Matrix get() -----------------------------------------
//FUNCTION: get ()
//PURPOSE: grabs the template value of the item in a specific array location for display
//RETURNS: array[i][j];
//NOTE: used in << operator.
/*}}}*/ //---------------------------------------------------------------------
template<class T>
T Matrix<T>::get (int i, int j)
{
    return array[i][j];
}/*}}}*/

/*{{{*/ /*{{{*//*-------------Matrix trans() ----------------------------------------------------*/
//FUNCTION: trans{}
//PURPOSE: performs the transpose math function on the given matrix 
//RETURNS: NA 
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
template <class T>
void Matrix<T>::trans()
{/*{{{*/

    Matrix<double> m1(cols, rows, m_args, 6);

        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                m1.array[i][j] = array[j][i];
            }
        }
        cout << m1;
}/*}}}*/

/*{{{*/ /*{{{*//*-------------Matrix out() ----------------------------------------------------*/
//FUNCTION: out ()
//PURPOSE: saves the resulting Matrix to a new .mtx file named with by the user. 
//RETURNS: NA
//NOTE: used as the 5th and 6th commands in command mode (ex: ./matrix_math -add A B -out C)
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
template <class T>
void Matrix<T>::out()
{/*{{{*/

    ofstream save;
    m_args[5] += ".mtx";
    save.open(m_args[5].c_str(), ios::out);

   save << setw((cols * 2)) << rows << " x " << cols << endl;

   for (int i = 0; i < rows; i++)
   {    for (int j = 0; j < cols; j++)
                save << setw(4) << get(i, j);
        save << endl;   }

   save.close();
    



}/*}}}*/

/*{{{*/ /*{{{*/ //-------------- << operator ----------------------------------
//FUNCTION: << operator
//PURPOSE: overloaded << to display the chosen matrix in the correct array format
//RETURNS: strm
/*}}}*/ //---------------------------------------------------------------------
template <class T1>
ostream &operator << (ostream &strm, Matrix<T1> &m1)
{
   strm << endl << setw((m1.cols * 2)) << m1.rows << " x " << m1.cols << endl;

   for (int i = 0; i < m1.rows; i++)
   {    for (int j = 0; j < m1.cols; j++)
                strm << setw(4) << m1.get(i, j);
        strm << endl;   }
strm << endl;

return strm;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ >> operator ------------------------------------
//FUNCTION: >> operator
//PURPOSE: input into a class object from a file.
//RETURNS: strm
//NOTE: mainly used for input from the .mtx file
/*}}}*/ //---------------------------------------------------------------------
template <class T1>
istream &operator >> (istream &strm, Matrix<T1> &m1)
{

  char let_x;

   m1.m_argc = m1.argc;

        strm >> m1.rows >> let_x >> m1.cols;

        for (int i = 0; i < m1.rows; i++)
        {
            for (int j = 0; j < m1.cols; j++)
            {
                strm >> m1.array[i][j];
            }
        }
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ + operator---------------------------------------
//FUNCTION: Matrix operator +
//PURPOSE: overloads the + symbol to add two Matrix objects together
//RETURNS: m2
//NOTE: the rows and cols size of both matrices have to been the same size
/*}}}*/  //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator + (Matrix<T> &m1)
{
    Matrix<double> m2(rows, cols, m_args, m_argc);
    m2 = m1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (array[i][j] + m1.array[i][j]);
    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ - operator---------------------------------------
//FUNCTION: Matrix operator -
//PURPOSE: overloads the - symbol to subtract two Matrix objects
////RETURNS: m2
//NOTE: the rows and cols size of both matrices have to been the same size
/*}}}*/  //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator - (Matrix<T> &m1)
{
    Matrix<double> m2;
    m2 = m1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (array[i][j] - m1.array[i][j]);
    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ * operator---------------------------------------
//FUNCTION: Matrix operator *
//PURPOSE: overloads the * symbol to add two Matrix objects together
//RETURNS: m2
//NOTE: The cols of the first matrix must be the size of the rows in the second
/*}}}*/  //---------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator * (Matrix<T> &m1)
{
    double c = 0;
    double d = 0;


    Matrix<double> m2(rows, m1.cols, m_args, 6);
  //  m2 = m1;

    for (int k = 0; k < m1.cols; k++)
    {
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                   c += (array[i][j] * m1.array[j][k]);
                m2.array[i][k] = c;
                c = 0;
           // cout << m2.array[i][k] << " ";
        }
      //  cout << endl;
    }

    return m2;
}/*}}}*/


/*{{{*/ /*{{{*/ //------------ = operator----------------------------------------
//FUNCTION: Matrix operator =
//PURPOSE: overloads the = symbol work as an assignment operator
//RETURNS: NA
//NOTE: used in int main() in this program to assign pass objects to mat objects
/*}}}*///------------------------------------------------------------------------
template <class T>
void Matrix<T>::operator = (const Matrix<T> &m1)
{

    for(int i = 0; i < rows; i++)
        delete [] array[i];
    delete [] array;

   // cout << "\n = Operator (238 - Matrix.cpp)\n";
    rows = m1.rows;
    cols = m1.cols;
    m_argc = m1.m_argc;

    array = new T*[m1.rows];

    for(int i = 0; i < m1.rows; i++)
        array[i] = new T[m1.cols];

    for(int i = 0; i < m_argc; i++)
     m_args[i] = m1.m_args[i];

    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.cols; j++)
        {
           array[i][j] = m1.array[i][j];
        }
    }


}/*}}}*/


/*{{{*/ /*{{{*/ //------------ == operator----------------------------------------
//FUNCTION: Matrix operator ==
//PURPOSE: overloads the = symbol to test two matrices for equality
//RETURNS: NA
//NOTE: checks to see that each number matches the corresponding spot in the other matrix
/*}}}*///------------------------------------------------------------------------
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

/*{{{*/ /*{{{*/ //------------ sizecheck() ----------------------------------------
//FUNCTION: sizecheck()
//PURPOSE: check for matching row and column size for + - == operators
//RETURNS: equal
//NOTE: used to prevent mismatching sizes which would result in segmentation core faults
/*}}}*///------------------------------------------------------------------------
template <class T>
bool Matrix<T>::sizecheck(const Matrix<T> &m1)
{
    bool equal = true;

   if(rows != m1.rows)
       equal = false;
   if(cols != m1.cols)
       equal = false;

     return equal;
} /*}}}*/

/*{{{*/ /*{{{*/ //------------ sizecheck() ----------------------------------------
//FUNCTION: sizecheck()
//PURPOSE: check for matching row and column size for + - == operators
//RETURNS: equal
//NOTE: used to prevent mismatching sizes which would result in segmentation core faults
/*}}}*///------------------------------------------------------------------------
template <class T>
bool Matrix<T>::mulsizecheck(const Matrix<T> &m1)
{
    bool equal = true;

   if(cols != m1.rows)
       equal = false;

     return equal;
} /*}}}*/

