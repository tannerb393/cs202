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

#include "bankacct.h" // call to header file


 /*--------------------------------------------------------------------------------------
 *FUNCTION NAME: int main ()
 *PURPOSE: Holds main code for running program and calling other functions. first function called
 *RETURNS: 0 for true, 1 for false
 *NOTE: holds two command line parameters and and input to structures StudentGrade
 * --------------------------------------------------------------------------------------*/
int main (int argc, char* argv[])
{/*{{{*/
    int record = 0;
    int choice = 0;

    Bank user[100];
    Bank temp;

  loadStructArray(user, record);

	while (choice == 0)
    {
        switch (mainMenu()) // Switch carries out result returned from mainMenu() function.
		{
		case 1:	newAcct(user, record, &temp);
			break;
		case 2: loadAcct(user, record);
			break;
		case 3:	fullReport(user, record); // if user wants to exit the game from main title.
			break;
		} 
    }

   return 0;
}/*}}}*/

int mainMenu()
{/*{{{*/
  //  system("clear");

	int choice = 0;
	cout << "  ==========BANK ACCOUNT TOOL MAIN MENU============\n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

	// choices used in switch(mainMenu())
	cout << "| [1] REGISTER A NEW BANK ACCOUNT\n"
			"| [2] ACCESS USER BANK ACCOUNT\n"
			"| [3] GENERATE BANK ACCOUNT DATABASE REPORT\n";
	cout << "|-----------> ";
	cin >> choice;
	while (choice < 1 || choice > 3 || cin.fail()) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
    clearIt();
	return (choice);
}/*}}}*/

int acctMenu(Bank user[], int &record)
{/*{{{*/
    system("clear");

	int choice = 0;
    do
    {    
        cout << " ============ ACCOUNT MANAGEMENT MENU ============== \n \n";
        currentUser(user, record);
        cout << "| [1] -DEPOSIT FUNDS\n"
                "| [2] --WITHDRAW FUNDS\n"
                "| [3] ---TRANSFER FUNDS \n"
                "| [4] ----DELETE  ACCOUNT\n"
                "| [5] CLOSE ACCOUNT AND RETURN TO MAIN MENU\n";
        cout << "|-------> ";
        cin >> choice;

        while (choice < 1 || choice > 6) // INCORRECT CHOICE FIXER
            choice = invalidIntChoice();
        switch(choice)
            {
                case 1: depositAcct(user, record);
                    break;
                case 2:	withdrawAcct(user, record);
                    break;
                case 3:	transferAcct(user, record);
                    break;
                case 4: closeAcct(user, record);
                    break;
                case 5: recordCount(record); // reloads full 'record' count
                        saveAcct(user, record);
                        choice = 0;
                    break;
            }


    } while (choice != 0);


    return choice;
}/*}}}*/

void newAcct(Bank user[],int &record, Bank *temp)
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

               saveAcct(user, record);
               acctMenu(user, record);
            }


    }

}/*}}}*/

void loadAcct(Bank user[], int &record)
{ /*{{{*/
    system("clear");
    char loadAcct[6];
    char loadPass[7];
    bool act = false;
    bool pas = false;
	int choice = 0;


    do
    {
        cout << " =================== LOAD ACCOUNT ==================== \n \n";

        cout << "Enter User Account Number\n";
        cout << "-----> ";
        cin.getline(loadAcct, 100);
        
        for(int i = 0; i <= record; i++)
        {
            if (strcmp(user[i].acctnum, loadAcct) == 0)
            {
                record = i;
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
           
            if (strcmp(user[record].passw, loadPass) == 0)
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

    if (act == true && pas == true)
        choice = (acctMenu(user, record));
    else
        recordCount(record);

}/*}}}*/

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
           user[i].acctnum << endl;
    }
       ofile.close();
}/*}}}*/

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

    cout << record << " records \n";
    record--;
    ifile.close();
}/*}}}*/

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

}/*}}}*/

void withdrawAcct(Bank user[], int &record)
{ /*{{{*/
    system("clear");

    cout << " ====================== WITHDRAW FUNDS ====================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void transferAcct(Bank user[], int &record)
{ /*{{{*/
    system("clear");

    cout << " ======================= TRANSFER FUNDS ====================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

int closeAcct(Bank user[], int &record)
{ /*{{{*/
    system("clear");

    cout << " ===================== CLOSE ACCOUNT ======================== \n \n";
    cout << "Please choose from the options below and press [ENTER]: \n \n";

}/*}}}*/

void currentUser(Bank user[], int &record)
{/*{{{*/
   cout << "[ACCOUNT INFO]\n";
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

void passwordCheck()
{ /*{{{*/
   
}/*}}}*/

int invalidIntChoice()
{/*{{{*/
    int choice = 0;
	cout << "Please enter a valid menu choice: ";
	cin.clear();
	cin.ignore(100, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

void clearIt()
{/*{{{*/
	cin.clear();
	cin.ignore(100, '\n');
}/*}}}*/

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



