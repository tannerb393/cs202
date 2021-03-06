

#include "Matrix.cpp"    // Specification file



typedef unsigned char byte;

/*---------------------------------------------------------------
 * FUNCTION: main ()
 * DESCR: Creates a Matrix object. sets some values and displays it
 * RETURNS: 0
 *------------------------------------------------------------------*/


int main (int argc, char *argv[])
{
    int *ptr = 0;
    int i, j;
    int m, n;
    char let_x;
    char file1[2];
    ifstream infile;
    string args[3];



    stringstream ss[3];
    for (int i = 0; i < 3; i++){ 
       ss[i] << argv[i]; 
       ss[i] >> args[i];}


    if (argc < 3)
    {
        cout << "Not Enough Arguments! \n\n";
        return 0;
    }

    if (args[1] == "-inp")
        args[2] += ".mtx";


    infile.open(args[2].c_str());
    if(!infile)
    {   cout << "Error opening file: " << args[2] << endl;
        return 0;
    }
    
    infile >> m >> let_x >> n;

    double k;
 

   /*
    if (strcmp(argv[1], "-inp") == 0)
    {
        strcpy(file1, argv[2]);
        strcat(file1, ".mtx");
        infile.open(file1);

        if(!infile)             //Test for errors.
        {
            cout << "\n Error opening file: " << args[2] << "\n\n";
            return 0;
        }
    }
*/




    Matrix<double>  mat1(m, n);
//    int k; // value to be read for Matrix<int>
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
