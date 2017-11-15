

#include "Matrix.h"    // Specification file





/*---------------------------------------------------------------
 * FUNCTION: main ()
 * DESCR: Creates a Matrix object. sets some values and displays it
 * RETURNS: 0
 *------------------------------------------------------------------*/


int main ()
{

    int m, n;

    cout <<"Input rows and cols: ";
    cin >> m >> n;

    Matrix mat1(m, n);

    for (int i = 0; i < m; i ++)
    {
        mat1.set(i, i%n, i+1);
    }

    mat1.display();
    return 0;


}
