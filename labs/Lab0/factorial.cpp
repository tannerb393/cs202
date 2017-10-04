/* -----------------------------------------------------------------------------

FILE NAME:         factorial.cpp

DESCRIPTION:       Factorial program

PURPOSE:           To compute the mathematical function n!

EXIT CODES:        0 = Success
                   Otherwise = Error

COMPILATION:       Compiled with a GNU toolset

NOTES:             None

MODIFICATION HISTORY:

Author              Date          Modification(s)
----------------    ----------    ---------------
Joel Fredrickson    2016-01-22    Version 0001

----------------------------------------------------------------------------- */

#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// Macros
#define ENABLE_ASSERTIONS 1
#define SHOW_TRACE        0

// Function prototypes
void clear_the_screen    ();
void compute_n_factorial (int &, const int);
int  get_input           ();
void print_error_message (std::stringstream &, std::string);
void report_result       (std::stringstream &, const int, const int, const std::string);
void skip_some_lines     (const int);
bool verify_input        (std::stringstream &, const int, std::string);

static const int NUM_LINES_PER_SCREEN = 20;

/* -----------------------------------------------------------------------------

FUNCTION NAME:     main()

PURPOSE:           Program entry point

RETURNS:           Integer return code

                       0     = success
                       Other = error

NOTES:             None

----------------------------------------------------------------------------- */

int main(
    int    argc,
    char * argv [])

{

    int               n;                         // Value of n
    int               nfact = 1;                 // Value of n!
    std::string       programmer("YoursTruly");  // Programmer's name
    int               rc = 0;                    // Return code
    std::stringstream ss(std::stringstream::out);

    #if SHOW_TRACE
        std::cout << "Executing ... 01" << std::endl;
    #endif

    clear_the_screen();

    n = get_input();

    if (verify_input(ss, n, programmer))
    {
        #if SHOW_TRACE
            std::cout << "Executing ... 02" << std::endl;
        #endif
        compute_n_factorial(nfact, n);
        report_result(ss, n, nfact, programmer);
    }
    else
    {
        #if SHOW_TRACE
            std::cout << "Executing ... 03" << std::endl;
        #endif
        rc = 1; // Bad return code
    }

    #if SHOW_TRACE
        std::cout << "Executing ... 04" << std::endl;
    #endif

    // Show output
    std::cout << ss.str();

    // Write output to a file
    std::ofstream ofile;
    std::string filename = programmer+"_output.txt";
    ofile.open(filename.c_str(), std::ios::out);
    if (ofile)
    {
        ofile << ss.str();
        ofile.close();
    }

    return rc;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     compute_n_factorial()
PURPOSE:           Computes the factorial value of 'n'
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

void compute_n_factorial(
    int &     _nfact, // Value of n!
    const int _n)     // Value of n

{

    #if SHOW_TRACE
        std::cout << "Executing ... 05" << std::endl;
    #endif

    for (int i = 1; i <= _n; ++i)
        _nfact *= i;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     clear_the_screen()
PURPOSE:           Clears the screen by writing blank lines
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

void clear_the_screen()

{

    #if SHOW_TRACE
        std::cout << "Executing ... 06" << std::endl;
    #endif

    skip_some_lines(NUM_LINES_PER_SCREEN);

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     get_input()
PURPOSE:           Gets the value of 'n' from the user
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

int get_input()

{

    int n;

    #if SHOW_TRACE
        std::cout << "Executing ... 07" << std::endl;
    #endif

    std::cout << std::endl
              << "Enter a positive integer: ";

    std::cin  >> n;

    return n;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     print_error_message()
PURPOSE:           Prints error messages
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

void print_error_message(
    std::stringstream & _ss,  // Output message(s)
    const std::string   _str) // String that gets inserted into the error message

{

    #if SHOW_TRACE
        std::cout << "Executing ... 08" << std::endl;
    #endif

    _ss << std::endl
        << "You were told to enter a positive integer."
        << std::endl
        << std::endl
        << "You didn't."
        << std::endl
        << std::endl
        << "Goodbye from "
        << _str
        << '.'
        << std::endl
        << std::endl;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     report_result()
PURPOSE:           Computes and reports the factorial value
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

void report_result(
    std::stringstream & _ss,         // Output message(s)
    const int           _n,          // Value of n
    const int           _nfact,      // Value of n!
    const std::string   _programmer) // Programmer's name

{

    #if SHOW_TRACE
        std::cout << "Executing ... 09" << std::endl;
    #endif

    _ss << std::endl
        << "The value of "
        << _n
        << "! is: "
        << _nfact
        << std::endl
        << std::endl
        << "This program was written by "
        << _programmer
        << '.'
        << std::endl
        << std::endl
        << "Goodbye."
        << std::endl
        << std::endl;

}

/* -----------------------------------------------------------------------------
FUNCTION NAME:     skip_some_lines()
PURPOSE:           Writes some blank lines
RETURNS:           Void
NOTES:             None
----------------------------------------------------------------------------- */

void skip_some_lines(
    const int _num_lines) // Number of lines to skip

{

    #if SHOW_TRACE
        std::cout << "Executing ... 10" << std::endl;
    #endif

    for (int i = 1; i <= _num_lines; ++i)
        std::cout << std::endl;

}

/* -----------------------------------------------------------------------------

FUNCTION NAME:     verify_input()

PURPOSE:           Data validation on the value of 'n'

RETURNS:           TRUE/FALSE

                       TRUE=input is good
                       FALSE=otherwise

NOTES:             This has to happen before we try to compute n!

----------------------------------------------------------------------------- */

bool verify_input(
    std::stringstream & _ss,         // Output message(s)
    const int           _n,          // Value of n
    const std::string   _programmer) // Programmer's name

{

    bool input_verifies = true;

    #if SHOW_TRACE
        std::cout << "Executing ... 11" << std::endl;
    #endif

    if (_n <= 0)
    {
        #if SHOW_TRACE
            std::cout << "Executing ... 12" << std::endl;
        #endif
        print_error_message(_ss, _programmer);
        input_verifies = false;
    }

    return input_verifies;

}
