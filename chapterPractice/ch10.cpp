// practice code for learning chapter 10 of CS202

// Libraries
#include <iostream> // standing output on screen
#include <cstring> // for input
#include <cctype> // for testing characters
#include <cstdlib> // for many things but this one for : atoi, atof
#include <string> // for the string class

using namespace std;

// Function prototypes go here


void clear_screen();

//      "main ()" function --- the program's entry point 
//      int argc        // Number of paramenteres on the command line
//      char *argv[]    // An array of pointers to C-strings


int main (int argc, char *argv[])
{

    char ch = 253;
    char charTest1[50]; //large array size to take getline 
    char charTest2[50]; // "
    char charTest3[100]; // double size to hold both above arrays

    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0;

    
    clear_screen();
    for (int i = 0; i < argc; ++i)
    {
        cout << "Command line parameter " << i
            << " = " << argv[i] << endl;
    }

    cout << "Enter first test string: ";
    cin.getline (charTest1, 50); // * remember c-strings need cin.getline, not getline (cin,
    cout << "Enter second test string: ";
    cin.getline (charTest2, 50);

    int charLen1 = strlen(charTest1); // length of characters in rays added to inv vars
    int charLen2 = strlen(charTest2);
    int charLen3 = (charLen1 + charLen2 + 1); // stores size to be used for 3rd array

    cout << endl;
    
    //for loop for testing charTest (array) for multiple things listed below adds up
    //each kind of character and displays out
    for (int i = 0; i < charLen1; i++)
    {
       if (isalpha(charTest1[i])) // checks for letters only 
            A++;
       if (isalnum(charTest1[i])) // checks for numbers and letters
            B++;
       if (isdigit(charTest1[i])) // checks for 0-9 digits only
            C++;
       if (islower(charTest1[i])) // checks for lower case
            D++;
       if (isprint(charTest1[i])) // checks for printable chracters
            E++;
       if (isupper(charTest1[i])) // checks for uppercase letters
            F++;
       if (isspace(charTest1[i])) // checks for spaces (blank) characters
            G++;
    }
        // display out above character testers
        cout << "Testing: " << charTest1 << endl;
        cout << "There are " << A << " Letters in charTest1 array \n";
        cout << "There are " << B << " Numbers OR Letter in charTest1 array \n"; 
        cout << "There are " << C << " Digits (0-9) in charTest1 array \n"; 
        cout << "There are " << D << " Lowercase letters in charTest1 array \n"; 
        cout << "There are " << E << " printable characters in charTest1 array \n";
        cout << "There are " << F << " Uppercase Letters in charTest1 array \n"; 
        cout << "There are " << G << " Whitespace characters in charTest1 array \n";

        cout << endl;
        
        //using the strcat() function to append two arrays together
    
        cout << "charTest1 array: " << charTest1 << endl;
        cout << "charTest2 array: " << charTest2 << endl;
        strcat(charTest3, charTest1); // strcat adds first array to 3rd
        strcat(charTest3, charTest2); // " second to 3rd
        cout << "charTest2 appended to charTest1 shows: " << charTest3 << endl;

        char numberTest1[] = "57864.25"; // character array to  be converted to int

        // uses atoi and atof to convert the ascii characters in the numberTest1 char array
        // into actual integer numbers (int and double) that can then be used in mathtasticness
        cout << "character string stored in numberTest1: " << numberTest1 << endl;
        cout << "char array numberTest1 converted to int using 'atoi' and then divided by 2 : ";
        int char2int = atoi(numberTest1);
        cout << (char2int / 2) << endl;
        cout << "char array numberTest1 converted to double int using 'atof' and then divided by 2 : ";
        double char2dub = atof(numberTest1);
        cout << (char2dub / 2) << endl;

        cout << "X" << ch << endl;
        cout <<"X\u00b2" << endl;

    return 0;       // 0 = success

}

void clear_screen()
{
    for (int i = 0; i < 10; i++) // prints out 10 blank lines before program
        cout << endl;
}


