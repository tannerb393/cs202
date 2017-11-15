#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
    rows = n_rows;
    cols = n_cols;

    array = new int*[rows];

    for (int i = 0; i < rows; i++)
        array[i] = new int[cols];

    cout << "Matrix constructor: ";
    cout << rows << " X " << cols << endl;
}

template <class T>
int Matrix<T>::get(int i, int j)
{
    return array[i][j];
}

template <class T>
void Matrix<T>::set(int i, int j, int k)
{
    array[i][j] = k;
}

template <class T>
void Matrix<T>::display()
{
    cout << endl;
   for (int i = 0; i < rows; i++)
   {
       for (int j=0; j < cols; j++)
            {
                cout << setw(4) << get (i, j);
            }
       cout << endl;

    }
   cout << endl;
}

template <class T>
Matrix<T>::~Matrix()
{
 //   delete array;

   for (int i = 0; i < rows; i++)
    delete [] array[i];

   delete [] array;

}

