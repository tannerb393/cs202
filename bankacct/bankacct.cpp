//HEADER  /*{{{*/
/*   --------------------------------FILE HEADER ---------------------------------------
FILE NAME:     structures_v1.CPP
DESCRIPTION:   .cpp file written to use examples of structures and file input/output
PURPOSE:       holds code that is compiled with makefie to run the structures program
USAGE:         compile this file into an executable by using the make file in Lab3, run the 
                compiled file along with inputs for variable when prompted. or using the '<input.txt' file.
EXAMPLES:      'make structure_v1' followed by './structures_v1' or './structures_v1.cpp < input.txt '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         Frst version of the structures .cpp file, holds a 5 var structures and basic call for input to and output
		from the structure 'StudentGrade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-21-2017     1.0 / structures_v1.cpp
----------------------------------------------------------------------------- 
/*}}}*/

#include <bankacct.h> // call to header file


 /*--------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and and input to structures StudentGrade
 * --------------------------------------------------------------------------------------*/
int main (int argc, char* argv[])
{/*{{{*/
    int record;

    Bank = user[1000];
    Bank *userptr = nullptr;
    userptr = &user;

    // loadStructArray(&user);

	while (choice = 0)
    {
        switch (mainMenu()) // Switch carries out result returned from mainMenu() function.
		{
		case 1:	choice = newAcct();
			break;
		case 2: choice = loadAcct();
			break;
		case 3:	choice = reportAcct(); // if user wants to exit the game from main title.
			break;
		case 4: choice = resetData();
			break;
		} 
    }

   return 0;
}/*}}}*/

int mainMenu()
{/*{{{*/
    system("clear");

	int choice = 0;
	cout << "  ==========BANK ACCOUNT TOOL MAIN MENU============\n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

	// choices used in switch(mainMenu())
	cout << "| [1] REGISTER A NEW BANK ACCOUNT \n"
			"| [2] LOG IN TO EXISTING BANK ACCOUNT\n"
			"| [3] GENERATE BANK ACCOUNT DATABASE REPORT\n";
	cout << "| [4] FULL FORMAT (PIN REQUIRED) \n";
	cout << "|-----------> ";
	cin >> choice;
	while (choice < 1 || choice > 4) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();

	return (choice);
}/*}}}*/

int acctMenu()
{/*{{{*/
    system("clear");


	int choice = 0;
    cout << " ============ ACCOUNT MANAGEMENT MENU ============== \n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

    do
    {
	//choices used switch(acctMenu())
    cout << "| [1] DISPLAY ACCOUNT INFORMATION\n"
            "| [2] DEPOSIT FUNDS INTO ACCOUNT\n"
			"| [3] WITHDRAW FUNDS FROM ACCOUNT\n"
			"| [4] TRANSFER FUNDS TO ANOTHER ACCOUNT\n";
	        "| [5] CLOSE OUT THIS BANK ACCOUNT\n"
            "| [6] CLOSE ACCOUNT AND RETURN TO MAIN MENU\n";
	cout << "|-----------> ";
	cin >> choice;

	while (choice < 1 || choice > 6) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
    switch
        {
            case 1: userReport();
                break;
            case 2: depositAcct();
                break;
            case 3:	withdrawAcct();
                break;
            case 4: transferAcct();
                break;
            case 5: choice = closeAcct(); // return a 0 if acct closed to goto mainMenu
                break;
        }
        if (choice == 6)
            choice = 0;

    } while (choice != 0);


    return choice;
}/*}}}*/

int newAcct()
{ /*{{{*/
    system("clear");

	int choice = 0;
    cout << " ==================== NEW ACCOUNT =================== \n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

    cout << "| [1] CREATE NEW ACCOUNT\n"
            "| [2] RETURN TO PREVIOUS MENU\n"
	cout << "|-----------> ";
	cin >> choice;
	//choices used switch(acctMenu())
   
	while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();

    if (choice == 1)
    {
    // all the stuff to get new info, add to array and check for format here
    //
    //choice = (acctMenu);
    }

    else 
        choice = 0;



	return choice;
}/*}}}*/

int loadAcct()
{ /*{{{*/
    system("clear");

	int choice = 0;
    cout << " ===================== LOG IN ====================== \n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

    cout << "| [1] ENTER LOG-IN INFORMATION\n"
            "| [2] RETURN TO PREVIOUS MENU\n"
	cout << "|-----------> ";
	cin >> choice;
	//choices used switch(acctMenu())
   
	while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();

    if (choice == 1)
    {
    // check for format
    // load array and find account
    // check password
    // if all checks out pass user# onto acctMenu()
    //

    //  choice = (acctMenu);
    }

    else 
        choice = 0;

	return choice;
}/*}}}*/

void fullReport()
{ /*{{{*/
    system("clear");

    int choice = 0;
    cout << " ================ GENERATE BANK TOOL REPORT ================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void loadStructArray()
{ /*{{{*/
    system("clear");

    int choice = 0;
    cout << " ====================ACCOUNT INFORMATION  =================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

/***************************************ACCOUNT FUNCTIONS*******************************/

void userReport()
{ /*{{{*/
    system("clear");

    cout << " ==================== ACCOUNT INFORMATION =================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void depositAcct()
{ /*{{{*/
    system("clear");

    cout << " ======================== DEPOSIT FUNDS ====================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void withdrawAcct()
{ /*{{{*/
    system("clear");

    cout << " ====================== WITHDRAW FUNDS ====================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void transferAcct()
{ /*{{{*/
    system("clear");

    cout << " ======================= TRANSFER FUNDS ====================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void closeAcct()
{ /*{{{*/
    system("clear");

    cout << " ===================== CLOSE ACCOUNT ======================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

/************************************DATA CHECK FUNCTIONS******************************/

float balanceCheck()
{ /*{{{*/


}/*}}}*/

char ssCheck()
{ /*{{{*/

}/*}}}*/

char acFormCheck()
{ /*{{{*/
 

}/*}}}*/

char paFormCheck()
{ /*{{{*/
    
}/*}}}*/

char passwordCheck()
{ /*{{{*/
   
}/*}}}*/

int invalidIntChoice()
{/*{{{*/
	int choice;
	cout << "Please enter a valid menu choice: ";
	cin.clear();
	cin.ignore(10, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

