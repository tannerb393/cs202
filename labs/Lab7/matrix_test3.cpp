

#include "Matrix.cpp"    // Specification file



typedef unsigned char byte;

/*---------------------------------------------------------------
 * FUNCTION: main ()
 * DESCR: Creates a Matrix object. sets some values and displays it
 * RETURNS: 0
 *------------------------------------------------------------------*/


int main (int argc, char *argv[])
{
    int *ptr = nullptr;
    int i, j, k;
    int m, n;
    char let_x;
    char file1[2];
    ifstream infile;

    if (argc < 3)
    {
        cout << "Not enough Arguments ?\n\n";
        return 0;
    }

    if (strcmp(argv[1], "-inp") == 0)
    {
        strcpy(file1, argv[2]);
        strcat(file1, ".mtx");
        infile.open(file1);

        if(!infile)             //Test for errors.
        {
            cout << "\n Error opening file: " << file1 << "\n\n";
            return 0;
        }
    }



    infile >> m >> let_x >> n;

    Matrix<int>  mat1(m, n);
    int k; // value to be read for Matrix<int>
//   Matrix<double> mat1(m, n);
//   double k;
//  Matrix<byte> mat1(m, n);
//    byte k;

    for (i=0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            infile >> k;
            mat1.set(i, j, k);
        }
    }

    mat1.display();

    infile.close();

    return 0;

}
