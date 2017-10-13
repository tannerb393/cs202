/*{{{*/

/* --------------------------------FILE HEADER------------------------------------
* FILE NAME:     banking.h
* DESCRIPTION:   .h file that is the header file for the .cpp file holding the library definitions
                the structure definition and the function prototypes.
PURPOSE:       This files helps to contain parts of the .cpp file which may be used by multiple 
                .cpp files, saving time and cleaning up the code.
USAGE:         included in the beginning of the .cpp by adding "#include 
EXAMPLES:      #include "banking.h"
PARAMETERS:    none 
EXIT CODES:    NA
COMPILATION:   used vim and makefile which includes (.cpp :
	            g++ -o $* $*.cpp -std=c++11 -std=gnu++11
NOTES:         
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-28-2017     1.0 / banking.h
Tanner_Benavides  10-1-2017     2.0 / banking.h
Tanner_Benavides  10-12-2017     3.0 / banking.h
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

struct Para 
{
    char ok[100];
    char go[100];
};



 // Function prototypes go here
  int invalidIntChoice();
  void clearIt();
  int mainMenu();
  void recordCount(int &);
  void acctMenu(Bank [100], int &, int &);
  void newAcct(Bank [100], int &, int &, Bank *);
  void loadAcct(Bank [100], int &, int &);
  void saveAcct(Bank [100], int &);
  void cmdLoop(int &, char[]);
  int parameter(int&, char *[], Bank[100], int &);
  //------ acct functions -----------
  void depositAcct(Bank [100], int &);
  void withdrawalAcct(Bank [100], int &);
  void transferAcct(Bank [100], int &, int &);
  int deleteAcct(Bank [100], int &, int &);
  void currentUser(Bank [100], int &);
  void fullReport(Bank [100], int &);
  void loadStructArray(Bank[100], int &);
  //---- data check functions --------
  void balanceFormCheck(Bank *);
  void acctFormCheck(Bank *);
  void passFormCheck(Bank *);
  void firstFormCheck(Bank *);
  void lastFormCheck(Bank *);
  void middleFormCheck(Bank *);
  void ssFormCheck(Bank *); 
  void phoneFormCheck(Bank *);
 // ------COMMAND FUNCTIONS ----------
  void help ();
  void loadAcctP(Bank[100], int &, char[], char[], char[]);


#endif /* __BANKACCT_H__ */

