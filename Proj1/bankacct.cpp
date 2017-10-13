//HEADER
/*--------------------------------FILE HEADER ---------------------------------------
FILE NAME:     banking.CPP
DESCRIPTION:   .cpp file written to use create a banking program 
PURPOSE:       holds code that is compiled with makefie to run the banking program
USAGE:         compile this file into an executable by using the make file in Proj1, run the 
                compiled file along any command line actions.
EXAMPLES:      'make banking' followed by './banking '
PARAMETERS:    int argc - holds count of paramenters on the command line / char *argv[] holds an array of the pointers
EXIT CODES:    0 = success other = error
COMPILATION:   vim to write, and make file to compile: (CPP: g++ -o $* $*.cpp -std=c++11 -std=gnu++11)
NOTES:         large project file that contains most processes in individual functions
		from the structure 'StudentGrade'
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-28-2017     1.0 / banking.cpp
Tanner_Benavides  10-8-2017     2.0 / banking.cpp
Tanner_Benavides  10-11-2017     3.0 / banking.cpp
Tanner_Benavides  10-12-2017     4.0 / banking.cpp
//----------------------------------------------------------------------------- 
*/

#include "bankacct.h" // call to header file


/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and and input to structures StudentGrade
 * --------------------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{/*{{{*/
    int record = 0;
    int choice = 0;
    int recordhold;

    Bank user[100];
    Bank temp;

        loadStructArray(user, record);
    if (argc > 1)
       choice = (parameter(argc, argv, user, record));

	while (choice == 0)
    {
        loadStructArray(user, record);
        switch (mainMenu()) // Switch carries out result returned from mainMenu() function.
		{
		case 1:	newAcct(user, record, recordhold, &temp);
                acctMenu(user, record, recordhold);
			break;
		case 2: loadAcct(user, record, recordhold);
                acctMenu(user, record, recordhold);
			break;
		case 3:	fullReport(user, record); // if user wants to exit the game from main title.
			break;
        case 4: choice = 1;
			break;
		} 
    }

   return 0;
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: int mainMenu()
 *PURPOSE: Holds visual menu dispaly
 *RETURNS: 0 for return to main;
 * --------------------------------------------------------------------------------------*/
int mainMenu()
{/*{{{*/

  //  system("clear");
	int choice = 0;
	cout << "  ==========BANK ACCOUNT TOOL MAIN MENU============\n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

	// choices used in switch(mainMenu())
	cout << "| [1] REGISTER A NEW BANK ACCOUNT\n"
			"| [2] LOAD ACCOUNT & ACCESS ACCOUNT MENU\n"
			"| [3] GENERATE BANK ACCOUNT DATABASE REPORT\n"
            "| [4] CLOSE BANKING PROGRAM\n";
	cout << "|-----------> ";
	cin >> choice;
	while (choice < 1 || choice > 4 || cin.fail()) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
    clearIt();
	return (choice);
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: acctMenu ()
 *PURPOSE: Menu used after a Bank account is loaded or created
 *RETURNS: 0 for return
 *NOTE: holds switch and call to 4 banking functions
 * --------------------------------------------------------------------------------------*/
void acctMenu(Bank user[], int &record, int &recordhold)
{/*{{{*/
    system("clear");

	int choice = 1;
    
    if (recordhold == 101)
        choice = 0;

    record = recordhold;

    while (choice != 0)
    {    
        cout << " ============ ACCOUNT MANAGEMENT MENU ============== \n \n";
        currentUser(user, record);
        recordhold = record;
        cout << "| [1] -DEPOSIT FUNDS\n"
                "| [2] --WITHDRAW FUNDS\n"
                "| [3] ---TRANSFER FUNDS \n"
                "| [4] ----DELETE  ACCOUNT\n"
                "| [5] CLOSE ACCOUNT AND RETURN TO MAIN MENU\n";
        cout << "|-------> ";
        cin >> choice;

        while (choice < 1 || choice > 5) // INCORRECT CHOICE FIXER
            choice = invalidIntChoice();
        clearIt();
        switch(choice)
            {
                case 1: depositAcct(user, record);
                    break;
                case 2:	withdrawalAcct(user, record);
                    break;
                case 3:	transferAcct(user, record, recordhold);
                    break;
                case 4: choice = deleteAcct(user, record, recordhold);
                    break;
                case 5: recordCount(record); // reloads full 'record' count
                        saveAcct(user, record);
                        choice = 0;
                    break;
            }
    } 

}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME:newAcct()
 *PURPOSE: Function that calls the data check functions to aggregate correct new user info
 *RETURNS: void
 *NOTE: runs though Bank structure in order
 * --------------------------------------------------------------------------------------*/
void newAcct(Bank user[],int &record, int &recordhold, Bank *temp)
{ /*{{{*/
    system("clear");

    char approve = 'x';
    int choice = 0;
    cout << " ==================== NEW ACCOUNT =================== \n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";
    cout << "| [1] CREATE NEW ACCOUNT\n"
            "| [2] RETURN TO PREVIOUS MENU\n";
	cout << "|-----------> ";
	cin >> choice;
	while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
    clearIt();

    if (choice == 1)
    {
            (lastFormCheck(temp));
            (firstFormCheck(temp));
            (middleFormCheck(temp));
            (ssFormCheck(temp));
            (phoneFormCheck(temp));
           // (balanceFormCheck(temp));
            temp->balance = 0.00;
            (acctFormCheck(temp));
            (passFormCheck(temp));
            cout << endl;

            cout << "[Bank Account Data Collected]\n";
            cout << temp->last << endl;
            cout << temp->first << endl;
            cout << temp->middle << endl;
            cout << temp->ss << endl;
            cout << temp->phone << endl;
            cout << fixed; 
            cout << setprecision(2) << temp->balance << endl;
            cout << temp->acctnum << endl;
            cout << temp->passw << endl;
            cout <<endl;

            cout << "Add Account To Database?? (Y/N)\n";
            cin >> approve;
            clearIt();

             while(approve != 'Y' && approve != 'y' && approve != 'N' && approve != 'n'){
                cin >> approve;
                clearIt();}

            if (approve == 'y' || approve == 'Y')
            {
                record ++;
               strcpy(user[record].last, temp->last);
               strcpy(user[record].first, temp->first);             
                      user[record].middle = temp->middle;
               strcpy(user[record].ss, temp->ss);
               strcpy(user[record].phone, temp->phone);
                      user[record].balance = temp->balance;
               strcpy(user[record].acctnum, temp->acctnum);
               strcpy(user[record].passw, temp->passw);
               
               recordhold = record;
               saveAcct(user, record);
            }
            else 
                recordhold = 101;
    }
    else
        recordhold = 101;

}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: loadAcct ()
 *PURPOSE: search for existing banking accounts by account number and password, then loads
 *RETURNS: void
 *NOTE: is no longer case sensitive
 * --------------------------------------------------------------------------------------*/
void loadAcct(Bank user[], int &record, int &recordhold)
{ /*{{{*/
    char loadAcct[6];
    char lowerUserAcct[6];
    char lowerLoadAcct[6];
    char loadPass[7];
    char lowerLoadPass[7];
    char lowerUserPass[7];
    bool act = false;
    bool pas = false;
    int choice;

    recordCount(record);

    do
    {
    	choice = 2;
        cout << " =================== LOAD ACCOUNT ==================== \n \n";

        cout << "Enter User Account Number\n";
        cout << "-----> ";
        cin.getline(loadAcct, 100);
        
        for(int i = 0; i <= record; i++)
        {
            for (int j = 0; j < 6; j++){
                lowerUserAcct[j] = tolower(user[i].acctnum[j]);
                lowerLoadAcct[j] = tolower(loadAcct[j]);}
            if (strcmp(lowerUserAcct, lowerLoadAcct) == 0)
            {
                recordhold = i;
                act = true;
            }
        }

        if (act == false)
        {
         cout << "No Matching Account Number\n";
         cout << "| [0] Return to Main Menu\n";
         cout << "| [1] Re-Enter Account Information\n";
         cin >> choice;
       	while (choice < 0 || choice > 1 || cin.fail()) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
        clearIt();
        }
        if (act == true)
        {
            cout << "Enter User Password\n";
            cout << "-----> ";
            cin.getline(loadPass, 100);
            for (int j = 0; j < 7; j++){
               lowerUserPass[j] = tolower(user[recordhold].passw[j]);
               lowerLoadPass[j] = tolower(loadPass[j]);}          
            if (strcmp(lowerUserPass, lowerLoadPass) == 0)
               pas = true;

        }
         if (pas == false && act == true)
         {
             cout << "No Matching Password Number\n";
             cout << "| [0] Return to Main Menu\n";
             cout << "| [1] Re-Enter Information\n";
             cin >> choice;
            while (choice < 0 || choice > 1 || cin.fail()) // INCORRECT CHOICE FIXER
            choice = invalidIntChoice();
            clearIt();
         }

    }while (choice == 1);

    if (choice == 0)
        recordhold = 101;

}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: fullReport ()
 *PURPOSE: creates the BankDB.Rpt report formatted for user viewig
 *RETURNS: void
 *NOTE: runs through array and send out info
 * --------------------------------------------------------------------------------------*/
void fullReport(Bank user[], int &record)
{ /*{{{*/

   char YN = 'x';
   char reportDefault[] = "BankAcct.Rpt";
   char reportName[31];
   char Rpt[] = ".Rpt";
   int hold;

   cout << "BankAcct.Rpt is the default name, would you like to choose a different file name?\n";
   while(YN != 'Y' && YN != 'y' && YN != 'N' && YN != 'n')
        cin >> YN;
   if (YN == 'Y' || YN == 'y')
   {
       clearIt();
       cout << "Please Select a file name (Letters/Numbers Only): \n";
       cin.getline(reportName, 30);
       strcat(reportName, Rpt);
   }
   else
       strcpy(reportName, reportDefault);
    
    ofstream ofile;
    ofile.open(reportName, ios::out);

   ofile << "--------  -----        -----        --   -----------   -------------   ----------" << endl;
   ofile << "Account   Last         First        MI   SS            Phone           Account   " << endl;
   ofile << "Number    Name         Name              Number        Number          Balance   " << endl;
   ofile << "--------  -----        -----        --   -----------   -------------   ----------" << endl;

   for (int i = 0; i <= record; i ++)
    {  
       ofile << left << setw(10) << user[i].acctnum <<  setw(13) << user[i].last << setw(13) << user[i].first
           << setw(5) << user[i].middle << setw(14) << user[i].ss << setw(16) << user[i].phone << 
           user[i].balance << endl;
    }
       ofile.close();
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: loadStructArray ()
 *PURPOSE: intially loads save file into array, also creates file if not present
 * --------------------------------------------------------------------------------------*/
void loadStructArray(Bank user[], int &record)
{ /*{{{*/

    fstream checkf; //opening and then closing banksave file to check create if not present 
    checkf.open("banksave.txt", ios::out | ios::app);
    checkf.close();
    if (checkf.fail()) // checks for file present.
        cout << "file was not created or found\n";

    ifstream ifile; // 'ifile' for inputting banksave.txt to struct array 'user'
    ifile.open("banksave.txt", ios::in);
    for (int i = 0; i < 100; i ++)
    {
       ifile >> user[i].last;
       ifile >> user[i].first;
       ifile >> user[i].middle;
       ifile >> user[i].ss;
       ifile >> user[i].phone;
       ifile >> user[i].balance;
       ifile >> user[i].acctnum;
       ifile >> user[i].passw;
    }
   ifile.close(); //close 'banksave' written to struct array
   
   recordCount(record);

}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: recordCount ()
 *PURPOSE: simply for re-obtaining full record count for use in program
 *NOTE: record counts are used in many save and display functions
 * --------------------------------------------------------------------------------------*/
void recordCount(int &record)
{/*{{{*/
    char cur = '\0';
    char last= '\0';
    int lines = 0;
   ifstream ifile; // 'ifile' for inputting banksave.txt to struct array 'user'

    ifile.open("banksave.txt", ios::in);
    while (ifile.get(cur)) // while used to count number of lines in save file.
    { if (cur == '\n' || 
            (cur == '\f' && last == '\r'))
        lines++;
    }
 
    record = (lines/9);

    //cout << record << " records \n";
    record--;
    ifile.close();
}/*}}}*/

/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: saveAcct ()
 *PURPOSE: rewrites array to banksave.txt file for updating new info
 *NOTE: changes saved after new user, and exiting acctMenu
 * --------------------------------------------------------------------------------------*/
void saveAcct(Bank user[], int &record)
{ /*{{{*/

    ofstream sfile; //opening and then closing banksave file to check create if not present 

    sfile.open("banksave.txt", ios::out);
    for (int i = 0; i <= record; i ++)
    {
       sfile << setprecision(2) << fixed; 
       sfile << user[i].last << endl;
       sfile << user[i].first << endl;
       sfile << user[i].middle << endl;
       sfile << user[i].ss << endl;
       sfile << user[i].phone << endl;
       sfile << user[i].balance << endl;
       sfile << user[i].acctnum << endl;
       sfile << user[i].passw << endl;
       sfile << endl;
    }
   sfile.close(); //close 'banksave' written to struct array

}/*}}}*/


/***************************************ACCOUNT FUNCTIONS*******************************/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: depositAcct()
 *PURPOSE: for adding money to loaded account
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
void depositAcct(Bank user[], int &record)
{ /*{{{*/

    double deposit = 0;
    cout << "Deposit amount: \n";
    cout << "---> ";
    cin >> deposit;
    while (deposit < 0 || cin.fail())
    {
        cout << "Invalid Deposit Amount, Enter a Positive Dollar Amount: \n";
        cout << "---> ";
        clearIt();
        cin >> deposit;
    }

    user[record].balance += deposit;
    clearIt();

}/*}}}*/


/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: withdrawalAcct()
 *PURPOSE: to remove money from the loaded account
 *NOTE: wont allow negative amounts in account
 * --------------------------------------------------------------------------------------*/
void withdrawalAcct(Bank user[], int &record)
{ /*{{{*/
    double withdrawal = 0;
    cout << "Withdrawal Amount: \n";
    cout << "---> ";
    cin >> withdrawal;
    while (withdrawal < 0 || cin.fail() || (user[record].balance - withdrawal) < 0)
    {
        cout << "Invalid Deposit Amount, Enter a Positive Dollar Amount: \n";
        cout << "Final Account Balance Cannot Be Less than Zero\n";
        cout << "---> ";
        clearIt();
        cin >> withdrawal;
    }

    user[record].balance -= withdrawal;
    clearIt();

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME:transferAcct ()
 *PURPOSE:transfer money
 *NOTE: transfer from loaded account to 2nd selected account
 * --------------------------------------------------------------------------------------*/
void transferAcct(Bank user[], int &record, int &recordhold)
{ /*{{{*/
    int mainrec = record;
    loadAcct(user, record, recordhold);
    double transfer;
    int choice;
    do
    {   choice = 0;
        system ("clear");
        cout << "[ACCOUNT 1]\n";
        currentUser(user, mainrec);
        cout << endl;
        cout << "[ACCOUNT 2]\n";
        currentUser(user, recordhold);
        cout << endl;

        cout << "TRANSFER [ACCOUNT 1] ---> [ACCOUNT 2]\n";
        cout << "Transfer Amount: ";
        cin >> transfer;

        while (transfer < 0 || (user[mainrec].balance < transfer) || cin.fail())
            {
                cout << "Invalid Amount, Enter a Positive Dollar Amount That is Present in [ACCOUNT 1]: \n";
                cout << "---> ";
                clearIt();
                cin >> transfer;
            }
            clearIt();

        user[mainrec].balance -= transfer;
        user[recordhold].balance += transfer;

        cout << "[ACCOUNT 1]\n";
        currentUser(user, mainrec);
        cout << endl;
        cout << "[ACCOUNT 2]\n";
        currentUser(user, recordhold);
        cout << endl;
        
        cout << "[1] Transfer Again\n";
        cout << "[2] Go Back\n";
        cin >> choice;
        while (choice < 1 || choice > 2 || cin.fail()) // INCORRECT CHOICE FIXER
            choice = invalidIntChoice();
        clearIt();

    }while(choice == 1);

    record = mainrec;

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME:deleteAcct ()
 *PURPOSE:delete account
 *NOTE: basically resaves file omitting the chosen account
 * --------------------------------------------------------------------------------------*/
int deleteAcct(Bank user[], int &record, int &delAccount)
{ /*{{{*/
    system ("clear");
    int currentRecord = record;
    recordCount(record);
    int choice;

    cout << "*** Permanently Delete Accout? ***\n";
    cout << "[1] YES\n";
    cout << "[2] NO\n";
    cin >> choice;
    while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
        choice = invalidIntChoice();
    clearIt();

    if(choice == 1)
    {
        ofstream sfile; //opening and then closing banksave file to check create if not present 

        sfile.open("banksave.txt", ios::out);
        for (int i = 0; i <= record; i ++)
        {
            if(i == delAccount)
                i++;

            sfile << setprecision(2) << fixed; 
            sfile << user[i].last << endl;
            sfile << user[i].first << endl;
            sfile << user[i].middle << endl;
            sfile << user[i].ss << endl;
            sfile << user[i].phone << endl;
            sfile << user[i].balance << endl;
            sfile << user[i].acctnum << endl;
            sfile << user[i].passw << endl;
            sfile << endl;
        }
       sfile.close(); //close 'banksave' written to struct array
       choice = 0;
    }
    else
        record = currentRecord;
   return choice;

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME:currentUser()
 *PURPOSE:shows current account info
 *RETURN: 0
 *NOTE: shows info for current loaded account
 * --------------------------------------------------------------------------------------*/
void currentUser(Bank user[], int &record)
{/*{{{*/
   cout << "-----------------\n";
   cout << setprecision(2) << fixed;
   cout << user[record].last << endl;
   cout << user[record].first << endl;
   cout << user[record].middle << endl;
   cout << user[record].ss << endl;
   cout << user[record].phone << endl;
   cout << user[record].balance << endl;
   cout << user[record].acctnum << endl;
   cout << user[record].passw << endl;
   cout << "-----------------\n";
   cout << endl;
}/*}}}*/

/************************************DATA CHECK FUNCTIONS******************************/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: passwordCheck ()
 *PURPOSE: checks validity of enter password
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
void passwordCheck()
{ /*{{{*/
   
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: invalidIntChoice ()
 *PURPOSE: if wrong number entered
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
int invalidIntChoice()
{/*{{{*/
    int choice = 0;
	cout << "Please enter a valid menu choice: ";
	cin.clear();
	cin.ignore(100, '\n');
	cin >> choice;
	return choice;
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: clearIt ()
 *PURPOSE: basic cin.ignore and clear functtion
 *NOTE: 
 * --------------------------------------------------------------------------------------*/

void clearIt()
{/*{{{*/
	cin.clear();
	cin.ignore(100, '\n');
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: lastFormCheck ()
 *PURPOSE:checks validity ofentered name 
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
void lastFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter Last Name: " << endl;
       cin.getline(temp->last, 100);

       for (int i = 0; i < strlen(temp->last); i++)
           if(!isalpha(temp->last[i]))
               retry = 1;

       if (strlen(temp->last) == 0 || cin.fail())
            retry = 1;

       if(retry == 1)
            cout <<"Bad Format! Enter Last Name, single word using A-Z\n"; 
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: firstFormCheck ()
 *PURPOSE: checks validity of entered first name
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
void firstFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter First Name: " << endl;
       cin.getline(temp->first, 100);

       for (int i = 0; i < strlen(temp->first); i++)
           if(!isalpha(temp->first[i]) || cin.fail())
               retry = 1;

        if (strlen(temp->first) == 0)
            retry = 1;

       if(retry == 1)
            cout <<"Bad Format! Enter First Name, single word using A-Z\n"; 
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: middleFormCheck ()
 *PURPOSE: checks validity of entered middle initial
 *NOTE: 
 * --------------------------------------------------------------------------------------*/
void middleFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter Middle Inital: " << endl;
       cin >> temp->middle;
       clearIt();
           
       if(!isalpha(temp->middle) || cin.fail())
           retry = 1;
       if (temp->middle == ' ')
           retry = 1;
       if(retry == 1)
            cout <<"Bad Format!\n"; 
    }while (retry == 1);

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: ssFormCheck()
 *PURPOSE: validity of Social Security number
 *NOTE: checks for proper form
 * --------------------------------------------------------------------------------------*/
void ssFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter Social-Security Number [xxx-xx-xxxx format]:\n";
       cin.getline(temp->ss, 100);
 
       if (strlen(temp->ss) == 0
               || strlen(temp->ss) > 11 
               || temp->ss[3] != '-'
               || temp->ss[6] != '-'
               || (!isdigit(temp->ss[0]))
               || (!isdigit(temp->ss[1]))
               || (!isdigit(temp->ss[2]))
               || (!isdigit(temp->ss[4]))
               || (!isdigit(temp->ss[5]))
               || (!isdigit(temp->ss[7]))
               || (!isdigit(temp->ss[8]))
               || (!isdigit(temp->ss[9]))
               || (!isdigit(temp->ss[10])))
               retry = 1;

   //    cout << temp->ss << endl;

       if(retry == 1)
            cout <<"Bad Format!:\n"; 
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: phoneFormCheck ()
 *PURPOSE: validation of phone number
 *NOTE: checks for symbols and size
 * --------------------------------------------------------------------------------------*/
void phoneFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;

        cout << "Enter Phone Number [(xxx)xxx-xxxx format]:\n";
        cin.getline(temp->phone, 100);
 
       if (strlen(temp->phone) == 0
               || strlen(temp->phone) > 13 
               || temp->phone[0] != '('
               || temp->phone[4] != ')'
               || temp->phone[8] != '-'
               || (!isdigit(temp->phone[1]))
               || (!isdigit(temp->phone[2]))
               || (!isdigit(temp->phone[3]))
               || (!isdigit(temp->phone[5]))
               || (!isdigit(temp->phone[6]))
               || (!isdigit(temp->phone[7]))
               || (!isdigit(temp->phone[9]))
               || (!isdigit(temp->phone[10]))
               || (!isdigit(temp->phone[11]))
               || (!isdigit(temp->phone[12])))
               retry = 1;

   //    cout << temp->phone << endl;

       if(retry == 1)
            cout <<"Bad Format!\n"; 
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: balanceFormCheck ()
 *PURPOSE: adds 0.0 to account beginning
 *NOTE: can be changed to allow entering money 
 * --------------------------------------------------------------------------------------*/
void balanceFormCheck(Bank *temp)
{/*{{{*/
    cout << "Please Enter An Amount (Dollars.Cents). Amounts will be rounded to cents place" << endl;
    cin >> temp->balance;
    clearIt();

    while (cin.fail())
    {
        cout << "Bad Format!\n";
        cin >> temp->balance;
        clearIt();
    }
  //  clearIt();

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: acctFormCheck ()
 *PURPOSE: validation of acct number
 *NOTE: checks for right size and letter/number use
 * --------------------------------------------------------------------------------------*/
void acctFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter Account Number Using Letters (A-Z)\n"
               "and Numbers (1-9), Must be 5 Characters Long. *Not Case Sensitive\n";
       cin.getline(temp->acctnum, 100);
       
       for (int i = 0; i < strlen(temp->acctnum); i++)
           if(!isalnum(temp->acctnum[i]) || cin.fail())
               retry = 1;

       if (strlen(temp->acctnum) == 0 ||strlen(temp->acctnum) != 5)
            retry = 1;

       if(retry == 1)
       cout << "Bad Format!\n"; 
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: passFormCheck ()
 *PURPOSE: validation of password
 *NOTE: checks for right size and use
 * --------------------------------------------------------------------------------------*/
void passFormCheck(Bank *temp)
{/*{{{*/
   int retry;
    do  
    {
       retry = 0;
       cout << "Enter Account Password Using Letters (A-Z)\n"
               " and Numbers (1-9), Must be 6 Characters Long. *Not Case Sensitive\n";
       cin.getline(temp->passw, 100);

       for (int i = 0; i < strlen(temp->passw); i++)
           if(!isalnum(temp->passw[i]) || cin.fail())
               retry = 1;

       if (strlen(temp->passw) == 0 ||strlen(temp->passw) != 6)
            retry = 1;

       if(retry == 1)
       cout << "Bad Format!\n";
    }while (retry == 1);
}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: parameters ()
 *PURPOSE: The main function for use in using paremeters/command line actions
 *NOTE: checks for proper form and adds variables to right conditions
 * --------------------------------------------------------------------------------------*/
int parameter(int &argc, char *argv[], Bank user[], int &record) // char arg[] obtains argv[] array.
{/*{{{*/
    char buf[100]; 
    char Ocheck[] = "banksave.txt";
    const char SLASH = '/';
    char validOptions[] = "?ACDFILMNOPRSTW";
    double money;
    int A, C, D, F, I, L, M, N, O, P, R, S, T, W;
    bool OO = false;
    bool AA = false;
    bool PP = false;
    int choice = 0;
    char *p = validOptions; // pointer to beginning address of validOptions
    char *pstart = validOptions;
    bool firstChar = true; // Test paramenter's 1st char
    bool secondChar = true; // test parameter's 2nd char
    Para meter[50];


    for (int i = 1; i < argc; i++) 
    {
       p = pstart;
       strcpy(meter[i].ok, argv[i]);
       cout << meter[i].ok << endl;
       if ((meter[i].ok[0]) != SLASH){
           cout << "NO SLASH - INVALID COMMAND\n";
           choice = 1;
           break;}
        for (; *p !=0; p++) 
        {   
            secondChar = false;
            secondChar = meter[i].ok[1] == *p;
            if (secondChar == true) break;
        }
        if (secondChar == false){
            cout << "INVALID COMMAND\n";
            choice = 1;}
        strcpy(meter[i].go, argv[i]+2);
        cout << meter[i].go << endl;
    }

    if (choice == 1)
        return choice;
    
 

        if (meter[1].ok[1] == '?')
            help();

         for (int i = 1; i < argc; i++) 
        {
          if((meter[i].ok[1]) == 'A')
              A = i;
          if((meter[i].ok[1]) == 'C')
              C = i;
          if((meter[i].ok[1]) == 'D')
              D = i;
          if((meter[i].ok[1]) == 'F')
              F = i;
          if((meter[i].ok[1]) == 'I')
              I = i;
          if((meter[i].ok[1]) == 'L')
              L = i; 
          if((meter[i].ok[1]) == 'M')
              M = i;
          if((meter[i].ok[1]) == 'N')
              N = i;
          if((meter[i].ok[1]) == 'O')
              O = i;    
          if((meter[i].ok[1]) == 'P')
              P = i; 
          if((meter[i].ok[1]) == 'R')
              R = i;
          if((meter[i].ok[1]) == 'S')
              S = i;
          if((meter[i].ok[1]) == 'T')
              T = i;   
          if((meter[i].ok[1]) == 'W')
              W = i;       
        }


        for (int i = 1; i < argc; i++) 
        {
          if((meter[i].ok[1]) == 'O')
              OO = true;
          if((meter[i].ok[1]) == 'A')
              AA = true;
          if((meter[i].ok[1]) == 'P')
              PP = true;   
        }


        if (strcmp(meter[O].go, Ocheck) != 0)
        {
            OO = false;
            cout << "/O SAVE FILE NAME INCORRECT, 'banksave.txt' IS CORRECT NAME, EXITING";
            choice = 1;
        }

        if (OO == true && AA == true && PP == true)
        {
            for (int i = 1; i < argc; i++) 
            {

              if((meter[i].ok[1]) == 'D')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                   money = atoi (meter[D].go);
                   user[record].balance += money,
                   currentUser(user, record);
                   recordCount(record);
                   saveAcct(user, record);

                }
              if((meter[i].ok[1]) == 'F')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                   strcpy(user[record].first, meter[F].go);
                   currentUser(user, record);
                   recordCount(record);
                   saveAcct(user, record);

                }
              if((meter[i].ok[1]) == 'I')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                }

              if((meter[i].ok[1]) == 'L')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                   strcpy(user[record].last, meter[L].go);
                   currentUser(user, record);
                   recordCount(record);
                   saveAcct(user, record);
                   
                }

              if((meter[i].ok[1]) == 'M')
                  M = i;
              if((meter[i].ok[1]) == 'N')
                  N = i;
              if((meter[i].ok[1]) == 'R')
                  R = i;
              if((meter[i].ok[1]) == 'S')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                   strcpy(user[record].ss, meter[F].go);
                   recordCount(record);
                   saveAcct(user, record);
                }
              if((meter[i].ok[1]) == 'T')
                  T = i;   
              if((meter[i].ok[1]) == 'W')
                {
                   loadAcctP(user, record, meter[A].go, meter[P].go, meter[O].go);
                   money = atoi (meter[W].go);
                   user[record].balance -= money,
                   currentUser(user, record);
                   recordCount(record);
                   saveAcct(user, record);

                }     
            }


        }
























        

    return 1;

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: help ()
 *PURPOSE: help
 *NOTE: displays help message for user using /?
 * --------------------------------------------------------------------------------------*/
void help()
{/*{{{*/
    cout << "-----------------HELP OPTION------------------\n";
    cout << "To run Program, three basic files are required:\n";
    cout << "        bankacct.cpp\n";
    cout << "        bankacct.h\n";
    cout << "        Makefile\n\n\n";


    cout << "commands to run Program fom the Linux Command Line\n";
    cout << "-----------------------------------------------\n";
    cout << "$ make bankacct <-- To make the .cpp file\n";
    cout << "$ ./bankacct <-- To run the created bankaccount program\n\n\n";


    cout << "./bankacct can also ran with the follow command line parameters:\n";
    cout << "-----------------------------------------------\n";
    cout << " /? /Llast_name  /Ffirst_name /Minitial /Sssn /Nphone_num /Aacct_num\n";
    cout << " /Ppassword  /Cnew_password  /Ddeposit_amt  /Wwithdraw_amt  /Ttransfer_amt\n";
    cout << " /Odb_file /Rrp \n";

}/*}}}*/
/* --------------------------------------------------------------------------------------
 *FUNCTION NAME: loadAcctP ()
 *PURPOSE: like the loadAcct function above
 *NOTE: This function is stripped for use with the parameters funcions
 * --------------------------------------------------------------------------------------*/
void loadAcctP(Bank user[], int &record, char sentAcct[], char sentPassw[], char file[])
{ /*{{{*/
    bool act = false;
    bool pas = false;
    int choice;

    recordCount(record);
        for(int i = 0; i <= record; i++)
        {
           if (strcmp(user[i].acctnum, sentAcct) == 0)
            {
                record = i;
                act = true;
            }
        }
          for(int i = 0; i <= record; i++)
        {      
            if (strcmp(user[i].passw, sentPassw) == 0)
               pas = true;

        }

       if (pas == true && act == true)
           currentUser(user, record); 
       else
           cout << "Wrong username or Password";



}/*}}}*/

