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


/*{{{*/ /*{{{*/ //-----------TEMP CLASS CONSTRUCTOR HEADER-----------------------------
//FUNCTION: Matrix (Overloaded Construcor)
//PURPOSE: used as an overloaded contructor for 'temporary' class members created in operators
//RETURNS: NA
//NOTE: used in overloaded operator like  '+' '*' '-'
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(int m_rows, int m_cols, string args[6], int argc)
{
   // cout << "Temp class Constructor (52 - Matrix.cpp)\n";

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

   // cout << "Main Constructor (65 - Matrix.cpp)\n";
}/*}}}*/


/*{{{*/ /*{{{*/ //-------------MAIN OVERLOADED CONSTRUCTOR-----------------------------
//FUNCTION: 
//PURPOSE: 
//RETURNS: NA
//NOTE: 
/*}}}*/ //---------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(string args[6], int c, int argc)
{
 
// cout << "Matrix overloaded constructor: (95 - Matrix.cpp) \n\n";

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

   // cout << "      " << args[c] << endl;
    
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
    return array[i][j];
}/*}}}*/

/*{{{*/ /*{{{*//*-------------Matrix trans() ----------------------------------------------------*/
//FUNCTION: int main ()
//PURPOSE: holds majority of code to call other functions 
//RETURNS: 0 to end program 
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
//FUNCTION: int main ()
//PURPOSE: holds majority of code to call other functions 
//RETURNS: 0 to end program 
/*}}}*/ /*}}}*//*--------------------------------------------------------------------------------*/
template <class T>
void Matrix<T>::out()
{/*{{{*/

    ofstream save;

    save.open(m_args[5].c_str(), ios::out);

   save << setw((cols * 2)) << rows << " x " << cols << endl;

   for (int i = 0; i < rows; i++)
   {    for (int j = 0; j < cols; j++)
                save << setw(4) << get(i, j);
        save << endl;   }

   save.close();
    



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
   strm << endl << setw((m1.cols * 2)) << m1.rows << " x " << m1.cols << endl;

   for (int i = 0; i < m1.rows; i++)
   {    for (int j = 0; j < m1.cols; j++)
                strm << setw(4) << m1.get(i, j);
        strm << endl;   }
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
    m2 = m1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (array[i][j] + m1.array[i][j]);
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
    Matrix<double> m2;
    m2 = m1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
           m2.array[i][j] = (array[i][j] - m1.array[i][j]);
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
//FUNCTION:
//PURPOSE: 
//RETURNS: NA
//NOTE: 
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


