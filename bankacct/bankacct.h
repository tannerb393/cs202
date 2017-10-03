/*   --------------------------------FILE HEADER------------------------------------/*{{{*/
FILE NAME:     structures_v6.h
DESCRIPTION:   .h file that is the header file for the .cpp file holding the library definitions
                the structure definition and the function prototypes.
PURPOSE:       This files helps to contain parts of the .cpp file which may be used by multiple 
                .cpp files, saving time and cleaning up the code.
USAGE:         included in the beginning of the .cpp by adding "#include structures_vx.h" "
EXAMPLES:      #include "structures_v6.h"
PARAMETERS:    none 
EXIT CODES:    NA
COMPILATION:   used vim and makefile which includes (.cpp :
	            g++ -o $* $*.cpp -std=c++11 -std=gnu++11
NOTES:         v6 includes new functions prototypes for 'get_average' and 'get_grade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v4.h
Tanner_Benavides  09-25-2017     2.0 / structures_v5.h
Tanner_Benavides  09-25-2017     3.0 / structures_v6.h
----------------------------------------------------------------------------- *//*}}}*/

#ifndef __BANKACCT_H__
#define __BANKACCT_H__

#include <iostream> // main
#include <cstring> // for cstring input
#include <stdlib.h> // for system("clear");
#include <cstdlib> //for char comparisons: atoi, atof, etc
#include <cctype> //for testing characters

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) // may not work for struct arrays
//#define MAX(x,y) ((x) ? (x) : (y) ) ''

struct Bank 
{
    char last[30+ 1]; 
    char first[30+ 1];
    char middle;
    char ss[11 + 1];
    char phone[15 + 1];
    float balance;
    char acctNum[5 + 1];
    char passw[7];
};

 // Function prototypes go here
 /* ---- main functions -----------
  * int mainMenu();
  * int acctMenu();
  * int newAcct();
  * int loadAcct();
  * ------ acct functions -----------
  * void depositAcct();
  * void withdrawAcct();
  * void transferAcct();
  * int closeAcct();
  * void userReport();
  * void fullReport();
  * void resetData();
  * void loadStructArray(Bank *);
  * ---- data check functions --------
  * float balanceCheck();
  * char ssCheck();
  * char acFormCheck();
  * char paFormCheck();
  * char passwordCheck();
  * int invaidIntChoice();
  */  

#endif /* __BANKACCT_H__ */


