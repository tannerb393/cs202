/*{{{*/

/* --------------------------------FILE HEADER------------------------------------
* FILE NAME:     structures_v6.h
* DESCRIPTION:   .h file that is the header file for the .cpp file holding the library definitions
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
//----------------------------------------------------------------------------- 
*//*}}}*/

#ifndef __BANKACCT_H__
#define __BANKACCT_H__

#include <iostream> // main
#include <cstring> // for cstring input
#include <stdlib.h> // for system("clear");
#include <cstdlib> //for char comparisons: atoi, atof, etc
#include <cctype> //for testing characters
#include <fstream> //file stream
#include <limits>
#include <iomanip>

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) // may not work for struct arrays
//#define MAX(x,y) ((x) ? (x) : (y) ) ''

	const int NAME_MAX = 31;
	const int SS_MAX = 12;
	const int PHONE_MAX = 14;
	const int ACCTN_MAX = 6;
	const int PASS_MAX = 7;

struct Bank 
{
    char last[NAME_MAX]; 
    char first[NAME_MAX];
    char middle;
    char ss[SS_MAX];
    char phone[PHONE_MAX];
    double balance;
    char acctnum[ACCTN_MAX];
    char passw[PASS_MAX];
};

 // Function prototypes go here
  int invalidIntChoice();
  void clearIt();
  int mainMenu();
  int acctMenu();
  int newAcct(Bank [100], int &, Bank *);
  int loadAcct(Bank [100], int &);
  void saveAcct(Bank [100], int &);
  //------ acct functions -----------
  void depositAcct();
  void withdrawAcct();
  void transferAcct();
  int closeAcct();
  void userReport();
  int fullReport(Bank [100], int &);
  void loadStructArray(Bank[100], int &);
  //---- data check functions --------
  void balanceFormCheck(Bank *);
  void acctFormCheck(Bank *);
  void passFormCheck(Bank *);
  void passwordCheck();
  void firstFormCheck(Bank *);
  void lastFormCheck(Bank *);
  void middleFormCheck(Bank *);
  void ssFormCheck(Bank *); 
  void phoneFormCheck(Bank *);

#endif /* __BANKACCT_H__ */

// c123a
// z52c42
//
