/* -----------------------------------------------------------------------------
FILE: mathGameCS135.CPP
DESCRIPTION : This Program is designed to be a small mostly linear math game that uses new or previously saved user
data to direct the player through a series of math problems which increase in difficulty as each level
is passed. there are different choices for what kind of math problems to work on, feedback for correct
or incorrect answers and chances to switch between problems in between levels.
COMPILER : MSVS
NOTES : 4-digit code to wipe the user data and reset txt files is [8542]
MODIFICATION HISTORY :
Author                   Date                Version
---------------		  ----------          --------------
Tanner Benavides     2017 - 02 - 10       1.0
---------------------------------------------------------------------------- - */

// #INCLUDE LIST 
#include <iostream> // basic
#include <iomanip> // for switches
#include <string> //for string input
#include <cmath> // for advanced math (may not need)
#include <stdlib.h> // for adding random MIGHT NEED <cstdlib>
#include <ctime> // for use with making randoms truly random
#include <cctype> // for check inputs for capitals and lowercase, etc.
#include <fstream> // For saving name and user data	
#include <stdio.h> // for sys(CLR)
#include <limits>
using namespace std;

//------------FUNCTIONS FOR MATHGAME---------------------
int mgNewUser(int[][6], int &, string &);/*{{{*/
int mgLoadUser(int[][6], int &, string &);
void mgArt();
void done();
int mgMain(char, int[][6], int &, string &);
void mgSave(int[][6], string &);
int mgMenu();
int resetData();
void load_mgArray(int[][6]);
void mgPassing(int[][6], int &);
//------------------FUNCTIONS SHARED BY BOTH GAMES--------
void pause(int dur);
int mainMenu();
void spaces(int);
int invalidIntChoice();
void math(char, int &, int &, int &, int &);
//---------------FUNCTIONS FOR Jeopardy GAME -------------
int jepMainMenu();
int jepGame(int &, string[100][3], int[100][4], string[100][2][6][5]);
int jepNewGame(int &, string[100][3], int[100][4], string[100][2][6][5]);
int jepLoadGame(int &, string[100][3], int[100][4], string[100][2][6][5]);
void jepDisplayBoard(int &, string[100][3], int[100][4], string[100][2][6][5], int);
void load_jepArray(int &, string[100][3], int[100][4], string[100][2][6][5]);
void jepSaveGame(int &, string[100][3], int[100][4], string[100][2][6][5]);
void jepArt();
int jepMain();
int jepGameMenu(int &, int &, string[100][3]);
void jepRules();
int jepQuestionCount(string[100][2][6][5], int);/*}}}*/
//--------------------------------------------------------

/* -----------------------------------------------------------------------------
FUNCTION:          int main()
DESCRIPTION:       main function, handles variables needed to pass to and from
menu functions, & refernce variables for saving and loading.
RETURNS:           returns 0; (standard int main() return
NOTES:
----------------------------------------------------------------------------- */
// MAIN FUNCTION // 
int main()
{/*{{{*/
	string userName;
	int playerNumber = 0, endGame = 0, forward = 0;
	int mgArray[200][6];
	string mgNameArray[200][2];

	load_mgArray(mgArray);

	
	do
	{
		switch (mainMenu()) // Switch carries out result returned from mainMenu() function.
		{
		case 1:	forward = mgNewUser(mgArray, playerNumber, userName);
			break;
		case 2: forward = mgLoadUser(mgArray, playerNumber, userName);
			break;
		case 3:	forward = jepMain(); // if user wants to exit the game from main title.
			break;
		case 4: forward = resetData();
			break;
		case 5: forward = 3;
		} 
		spaces(5); // simple space creating function (change int to change spaces)

		if (forward == 1)/*choice to enter menue which allows changing of passing percentage.*/
			mgPassing(mgArray, playerNumber);

		for (int i = 0; i < 4; i++)
			endGame += mgArray[playerNumber][i];

		while (endGame < 50 && forward == 1) 
		{
			switch (mgMenu())  // switch for math menu, decides math type.
			{
			case 1: endGame = mgMain('+', mgArray, playerNumber, userName);
				break;
			case 2: endGame = mgMain('-', mgArray, playerNumber, userName);
				break;
			case 3: endGame = mgMain('*', mgArray, playerNumber, userName);
				break;
			case 4: endGame = mgMain('/', mgArray, playerNumber, userName);
				break;
			case 5: endGame = mgMain('m', mgArray, playerNumber, userName);
				break;
			case 6: forward = 2;
				break;
			}
		}
	} while (forward != 3);

	if (endGame == 50)
	done(); // when endGame == 60, int main() will reach end of program and done() displays end message.

	return 0;
}/*}}}*/

/* ------------------------------MAIN MENU-------------------------------------------
FUNCTION:          int mainMenu()
DESCRIPTION:       Beginning of game menu with choices of New user, Load User, and exit program.
RETURNS:           returns choice; Integer (1,2,3) for Menu choice.
NOTES:
----------------------------------------------------------------------------- */
int mainMenu()
{/*{{{*/
	int choice = 0;
	mgArt();
	cout << "!*! WELCOME TO MATH GAMES 2.0 !*!" << endl;
	cout << "  ! NOW WITH MORE ALEX TREBEK ! \n";
	cout << " ========== MAIN MENU ========== \n \n";
	cout << "Please choose from the options below and press [ENTER]: \n \n";

	/*choice 1-5 used in switch(mainMenu())*/
	cout << "| [1] START AS A NEW USER FOR STUDENT MATH GAME \n"
			"| [2] LOAD PREVIOUS PROGRESS FOR STUDENT MATH GAME\n"
			"| [3] PLAY THE MULTIPLAYER JEOPARDY MATH CHALLENEGE! \n";
	cout << "| [4] RESET ALL USER DATA AND LEVELS FOR MATH GAME (PIN REQUIRED) \n";
	cout << "| [5] EXIT THE PROGRAM \n";
	cout << "|-----------> ";
	cin >> choice;

	while (choice < 1 || choice > 6) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();
	spaces(5);
	return choice;
}/*}}}*/

/* -----------------------------RESET DATA-----------------------------------------
FUNCTION:          int resetData()
DESCRIPTION:      given a Pin Code (8542)to teacher, she can reset all data
----------------------------------------------------------------------------- */
int resetData()
{/*{{{*/
	string reset_jepBoard[100][2][6][5]= { { { { "  +<1>+ ","  -<2>- ","  *<3>* ","  /<4>/ ","  ?<5>? " },
													{ " 100"," 100"," 100"," 100"," 100" },
													{ " 200"," 200"," 200"," 200"," 200" },
													{ " 300"," 300"," 300"," 300"," 300" },
													{ " 400"," 400"," 400"," 400"," 400" },
													{ " 500"," 500"," 500"," 500"," 500" } },

													{ { "  +<1>+ ","  -<2>- ","  *<3>* ","  /<4>/ ","  ?<5>? " },
													{ " 600"," 600"," 600"," 600"," 600" },
													{ " 700"," 700"," 700"," 700"," 700" },
													{ " 800"," 800"," 800"," 800"," 800" },
													{ " 900"," 900"," 900"," 900"," 900" },
													{ "1000","1000","1000","1000","1000" } } } };
	int passcode = 0;
	cout << "ENTER 4-DIGIT PIN CODE TO ERASE ALL USER DATA: \n";
	cout << "-----> ";
	cin >> passcode;

	if (passcode == 8542)
	{
		ofstream outputFile;
		outputFile.open("saveList.txt", ios::trunc); // clears all saved names for main math game
		outputFile.close();

		//outputFile.open("jepPlayersList.txt", ios::trunc); // clears all saved names for main math game
		//outputFile.close();

		outputFile.open("mgScoreList.txt"); // clear scores for every player
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (j == 5)
				{
					outputFile << 7;
					outputFile << " ";
				}

				else
				{
					outputFile << 0;
					outputFile << " ";
				}
			}
			outputFile << endl;
		}
		outputFile.close();

		outputFile.open("jepScores.txt"); // clear scores for Jeopardy game array
		outputFile << 0; // sets game variable to 0 - 0 games played
		outputFile << endl;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				{
					outputFile << 0;
					outputFile << " ";
				}
			}
			outputFile << endl;
		}
		outputFile.close();

		outputFile.open("users.txt"); // clear scores for Jeopardy game array
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				{
					outputFile << "X";
					outputFile << " ";
				}
			}
			outputFile << endl;
		}
		outputFile.close();

		outputFile.open("jepDisplayBoard.txt"); // clears all Jeopardy display boards for all saved games
		for (int h = 0; h < 100; h++)
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						outputFile << reset_jepBoard[0][i][j][k];
						outputFile << " ";
					}
					outputFile << endl;
				}
				outputFile << endl;
			}
			outputFile << endl;
		}
		outputFile.close();

		outputFile.close();
		cout << "USER DATA RESET SUCCESSFULLY!";
		pause(3);
	}

	return 2;
}/*}}}*/

/* -----------------------------LOAD MGARRAY-----------------------------------------
FUNCTION:          void load_mgArray()
DESCRIPTION:      Loads MathGame Array saved data from mgScoreList.txt at beginning of program
----------------------------------------------------------------------------- */
void load_mgArray(int mgArray[][6])
{/*{{{*/
	ifstream inputFile;
	inputFile.open("mgScoreList.txt");
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 6; j++)
			inputFile >> mgArray[i][j];
	inputFile.close();

	/*
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << mgArray[i][j];
			cout << " ";
		}
		cout << endl;
	}
	*/
}/*}}}*/

/* -----------------------------NEW USER-----------------------------------------
FUNCTION:          int mgNewUser()
DESCRIPTION:       function handles creation of New User Profile where progress
for math levels is saved.
RETURNS:           return firstLast; string value of user's filname, sent to main
and then referenced from there.
NOTES:			   minimum error checking for name input right now, needs further
work to prevent multiple words being entered for first & last name inputs
----------------------------------------------------------------------------- */
int mgNewUser(int mgArray[][6], int &playerNumber, string & userName)
{/*{{{*/
	string first, last, line, saveList = "saveList.txt";
	int choice;

	system("cls");

	//------ counts user's number in list ---------
	playerNumber = 0;
	string cast;
	ifstream myfile("saveList.txt");

	while (getline(myfile, cast))
		++playerNumber;
	//------------------------------------------


	cout << "| [][][] NEW USER CREATION [][][] \n";
	cout << "| **Single word input - No spaces** \n"; // user must enter only one word for first or last name
	cout << "| ENTER FIRST NAME: ";
	cin >> first;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* this line will remove all strings that come after
														 the first one, essentialy limiting name input for first
														 or last name to one word*/
	cout << "| **Single word input - No spaces** \n";
	cout << "| ENTER LAST NAME: ";
	cin >> last;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "| \n";
	cout << "| WELCOME TO THE GAME " << first << " " << last << "!" << "\n"; // displays name of user/
	spaces(5);

	//fileName = (first + "_" + last + "_" + "math" + ".txt"); // sets up filename(.txt) to be used during user's session
	userName = (first + " " + last);

	ofstream outputFile; //creates outputFile for user profile
	outputFile.open("saveList.txt", ios::app);
	outputFile << userName << endl;
	outputFile.close();

	cout << "| NEW PROFILE CREATED \n";
	cout << "| \n";
	cout << "| [1] CONTINUE WITH NEW GAME \n"
			"| [2] RETURN TO MATH GAME MAIN MENU \n";
	cout << "|-----------> ";
	cin >> choice;

	return choice;
}/*}}}*/

/* -----------------------------LOAD USER------------------------------------------
FUNCTION:          int main()
DESCRIPTION:       main function, handles variables needed to pass to and from
menu functions, & refer nce variables for saving and loading.
RETURNS:           returns 0; (standard int main() return
NOTES:
----------------------------------------------------------------------------- */
int mgLoadUser(int mgArray[][6], int &playerNumber, string & userName)
{/*{{{*/
	string first, last, saveList = "saveList.txt", line, cast;
	int choice; int nameRow = 0, nameCount = 0;

	system("cls");

	ifstream inputFile;

	cout << "| Hello, Returning User! \n";
	cout << "| List of users with saved Data: \n";
	cout << "| ********************************** \n";
	inputFile.open(saveList.c_str());	 // Open savelist.txt
	while (inputFile >> line)  // while not at the bottom of the list of names
	{
		cout << "| ["; cout << (nameRow++); cout << "] ";
		cout << line << " ";
		inputFile >> line;
		cout << line << endl;
	}
	inputFile.close();
	cout << "| ********************************** \n"
		"| \n";
	cout << "| TO LOAD USER PROFILE ABOVE (Press 1) \n";
	cout << "| IF NO USER DATA EXIST (Press 2) \n"; // choice two for no user data and to create new data
	cout << "| ------------> ";

	cin.clear();
	cin >> choice;

	while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
		choice = invalidIntChoice();

	if (choice == 1) 
	{
		spaces(5);
		cout << "| Enter First Name: \n| --------> ";
		cin >> first;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "| Enter Last Name: \n| --------> ";
		cin >> last;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "| Enter Number Next To Player's Name: \n| --------> ";
		cin >> playerNumber;
		while (playerNumber > (nameRow - 1)) // INCORRECT CHOICE FIXER
			playerNumber = invalidIntChoice();

		userName = (first + " " + last);

		cout << "| PROFILE LOADED \n";
		cout << "| \n";
		cout << "| [1] CONTINUE WITH LOADED GAME \n"
				"| [2] RETURN TO MATH GAME MAIN MENU \n";
		cout << "|-----------> ";
		cin >> choice;
	}
	else
		choice = mgNewUser(mgArray, playerNumber, userName);

	return choice;
}/*}}}*/

/* ------------------------------MATH MENU------------------------------------------
FUNCTION:          int mgMenu()
DESCRIPTION:       Menu for math choices or to return to main menu.
RETURNS:           return choice; choice (1 through 6) returns to switch in int main()
to send to Math Function.
NOTES:			   int main() will countinue to return here after profile selection
and in between math levels until all levels are passed.
----------------------------------------------------------------------------- */
int mgMenu()
{/*{{{*/
	int choice;

	system("cls");
	spaces(5);

	cout << "|*** MATH GAMES - MATH SELECTOR *** \n";
	cout << "| \n";
	cout << "| Please make your choice From the Menue below and Press ENTER: \n";
	spaces(3);
	cout << "| [1] ADDITION PROBLEMS \n"
			"| [2] SUBTRACTION PROBLEMS \n"
			"| [3] MULTIPLICATION PROBLEMS \n"
			"| [4] DIVISION PROBLEMS \n"
			"| [5] MIX-O-MATH PROBLEMS \n"
			"| [6] RETURN TO MAIN MENU AND PROFILE SELECT \n";
	cout << "|------------------> ";
	cin >> choice;

	while (choice < 1 || choice > 6) // INCORRECT CHOICE FIXER
	{
		cout << "Please enter a valid menu choice: ";
		cin.clear();
		cin.ignore(10, '\n');
		cin >> choice;
	}
	cout << string(10, '\n');

	return choice;
}/*}}}*/

/* -------------------------------!! MATH LEVEL FOR MATH GAME !!-----------------------------------------
FUNCTION:          int mgMain()
DESCRIPTION:       Math Level handler
RETURNS:           void, no return;
----------------------------------------------------------------------------- */
int mgMain(char sym, int mgArray[][6], int & playerNumber, string &userName)
{/*{{{*/
	int added = 0, subtracted = 0, divided = 0, level = 0; // hold amounts for math questions
	int right, remainder, remainderAnswer, totalLevelCount, randIndex;
	int randTerm1, randTerm2;
	int answer, results, multiplied = 0, mixed = 0, seed;
	long lvlA[10] = { 9,9,99,99,999,999,9999,9999,99999,99999 }; // used for giving + or - numbers to terms
	string correct[5] = { "Very good!", "Excellent!", "Nice work!", "Keep up the good work!", "Awesome!" };
	string incorrect[4] = { "No, Please try again.", "Incorrect, Let's try another.", "Don't give up! Really focus, one more time.", "Sorry Keep trying." };
	char currentLevel, mixedMath[4] = { '+', '-', '*','/' };

	switch (sym) // SWITCH DECIDES BEGINNING LEVEL OF CHOSEN MATH TYPE
	{
	case '+': level = mgArray[playerNumber][0];
		break;
	case '-': level = mgArray[playerNumber][1];
		break;
	case '*': level = mgArray[playerNumber][2];
		break;
	case '/': level = mgArray[playerNumber][3];
		break;
	case 'm': level = mgArray[playerNumber][4];
		break;
	}

	currentLevel = sym;

	if (level < 10) // LEVELS GO 0 THRU 9 (LEVEL COUNT WILL DISPLAY +1 TO BE 1 THRU 10
	{
		system("cls");
		spaces(5);
		cout << "| YOU ARE NOW ON LEVEL " << level + 1 << "! \n \n";
		seed = time(0);
		srand(seed);
		right = 0;

		for (int i = 0; i < 10; i++) // BEGINNING OF 'FOR' STATEMENT FOR ASKING QUESTIONS
		{
			randTerm1 = (rand() % lvlA[level]) + 1;
			randTerm2 = (rand() % lvlA[level]) + 1;
			if ((level % 2) != 0) // For xB levels, creates odd integers
				randTerm1 = -randTerm1;
			randIndex = rand() % 4; // Random (0-3) symbol choice for mixed math
			if (currentLevel == 'm') // for mixed math, randomizes symbol
				sym = mixedMath[randIndex];
			if (abs(randTerm2) > abs(randTerm1)) //FLIPS TERMS IF 2nd term (or Denom) is bigger (ABSOLUTE VALUE)
			{
				randTerm1 = randTerm1 + randTerm2;
				randTerm2 = randTerm1 - randTerm2;
				randTerm1 = randTerm1 - randTerm2;
			}
			remainder = 0;
			remainderAnswer = 0;


			math(sym, randTerm1, randTerm2, results, remainder);

			cout << "\n --------- \n";
			cout << randTerm1 << " " << sym << " " << randTerm2 << "? \n"; // display current math question
			cout << "--------->>  ";

			if (sym == '/')
				cout << " \n please enter Quotient now, \n and Remainder in next input box: \n --------->>  ";
			cin >> answer;
			while (cin.fail()) // error correction for non-int input
				invalidIntChoice();
			if (sym == '/') // IF STATEMENT FOR DIVISION ONLY
			{
				cout << "--------->>  "; cin >> remainderAnswer;
			}

			answer += remainderAnswer;
			if (answer == (results + remainder))
			{
				right++; // increases each time a answer is right (up to 10)
				cout << correct[rand() % 5] << endl; // random correct answer message
				cout << "Correct answer is [ " << results << " ] ";
				if (sym == '/')
					cout << "R" << remainder << " ] ";
			}
			else
			{
				cout << incorrect[rand() % 4] << endl; // random incorrect answer message
				cout << "Correct answer is [ " << results << " ] ";
				if (sym == '/')
					cout << "R" << remainder << " ] ";
			}


		}

		system("cls");
		spaces(5);
		cout << "| --------- \n";
		cout << "| ------------- \n";
		cout << "| NUMBER CORRECT: " << right << " OF 10 \n"; // number of correct answers
		cout << "| ------------- \n";
		cout << "| --------- \n";



		if (right >= mgArray[playerNumber][5]) // will be 70% unless parent/teacher menu is entered
		{
			spaces(5);
			cout << "| LEVEL PASSED. CONGRATULATIONS "; cout << userName; cout << "! \n"; // message for passing level
			cout << "|       PROGRESS WILL BE SAVED. YOU WILL BE \n";
			cout << "| RETURNED TO MATH SELECTION SCREEN FOR NEXT LEVEL";
			pause(5); // pause so user can read message

			level = level + 1; // increases passed level by 1

			switch (currentLevel) /* switch (based on character of current level) adds +1 to that level and then sends to mgSave()
								  to save results and start a new level*/
			{
			case '+': mgArray[playerNumber][0]++;
				mgSave(mgArray, userName);
				break;
			case '-': mgArray[playerNumber][1]++;
				mgSave(mgArray, userName);
				break;
			case '*': mgArray[playerNumber][2]++;
				mgSave(mgArray, userName);
				break;
			case '/': mgArray[playerNumber][3]++;
				mgSave(mgArray, userName);
				break;
			case 'm': mgArray[playerNumber][4]++;
				mgSave(mgArray, userName);
			}
		}
		else
		{
			spaces(5);
			cout << "| **********************************  \n";
			cout << "| **** YOU FAILED THE LEVEL, PLEASE SEE TEACHER **** \n"; // failed level message
			cout << "| ********************************** \n";
			pause(6);
		}
	}
	totalLevelCount = (mgArray[playerNumber][0] + mgArray[playerNumber][1] + mgArray[playerNumber][2] + mgArray[playerNumber][3] + mgArray[playerNumber][4]);
	// adds up total 1-10 of each level and returns to endGame variable
	return totalLevelCount;
}/*}}}*/

/* -------------------------------!! ART !!-----------------------------------------
FUNCTION:          int mgArt()
DESCRIPTION:       ASCII art -- MATH --
RETURNS:           void, no return;
----------------------------------------------------------------------------- */
void mgArt()
{/*{{{*/
	system("cls");
	cout << " \n";
	cout << "                     888   888      \n";
	cout << "                     888   888      \n";
	cout << "                     888   888      \n";
	cout << "88888b.d88b.  8888b. 88888888888b.  \n";
	cout << "888 '888 '88b    '88b888   888 '88b \n";
	cout << "888  888  888.d888888888   888  888 \n";
	cout << "888  888  888888  888Y88b. 888  888 \n";
	cout << "888  888  888'Y888888 'Y888888  888 \n";
	cout << " \n";

/*
	    cout <<  " d8b                                                 888 \n";
		cout <<  " Y8P                                                 888 \n";
		cout <<  "  			                            d888 \n";
		cout <<  " 8888  .d88b.   .d88b.   88888b.  8888b. 888d888.  d8888 888  888 \n";
		cout <<  " '888 d8P  Y8b d88''88b 888 '88b    '88b 888P'  d88' 888 888  888 \n";
		cout <<	 "  888 88888888 888  888 888  888.d888888 888    888  888 888  888 \n";
		cout <<	 "  888 Y8b.     Y88..88P 888 d88P888  888 888    Y88b 888 Y88b 888 \n";
		cout <<	 "  888  'Y8888   'Y88P'  88888P' 'Y888888 888     'Y88888   Y88888 \n";
		cout <<	 "  888                   888                                   888 \n";
	    cout <<  " d88P                   888                              Y8b d88P \n";
		cout <<  "888P'                   888                               'Y88P' \n"; 
*/
		return;
}/*}}}*/

/* ------------------------------- SAVE -----------------------------------------
FUNCTION:          char mgSave()
DESCRIPTION:       Save function which saves user's progress. five reference integers for
saving current level for each type of math problem. string reference to return filename. 
RETURNS:           returns sym; returns symbol to mathchoice Menu.
NOTES:
----------------------------------------------------------------------------- */
void mgSave(int mgArray[][6], string & userName)
{/*{{{*/

	ofstream outputFile;

	outputFile.open("mgScoreList.txt"); // below outputFile commands save current math level and passing % to 'filename'
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			outputFile << mgArray[i][j];
			outputFile << " ";
		}
		outputFile << endl;
	}

	outputFile.close();

	system("cls");
	spaces(5);
	cout << "| Saving game progress for " << userName << ": ---> ";
	cout << " Saving";
	for (int i = 0; i < 5; i++)
	{
		pause(1); cout << "."; // just look like its saving :/
	}
	cout << "| \n";

}/*}}}*/

/* ------------------------------MATH FUNCTION-----------------------------------------
FUNCTION:          int math()
DESCRIPTION:       math function which handles all math problems, answers, correct
percentages and level increase. contains radom arrays for each math
term and answers.
RETURNS:           returns totalLevelCount; integer which when sent to main determins if math
menu/function will be called again or if the game (and all levels) are complete.
NOTES:             most code is handled in this function.
----------------------------------------------------------------------------- */
void math(char sym, int &randTerm1, int &randTerm2, int &results, int &remainder)
{/*{{{*/
	int added = 0, subtracted = 0, divided = 0, multiplied = 0;

	added = (randTerm1 + randTerm2); //addition math
	subtracted = (randTerm1 - randTerm2); //subtracton math
	multiplied = (randTerm1 * randTerm2); //multiplied math
	divided = (randTerm1 / randTerm2); // division math
	if (sym == '/')
		remainder = (randTerm1 % randTerm2); // for remainder on division problem

	switch (sym) // SWITCH FOR MATH CHOICE
	{
	case '+': results = added;
		break;
	case '-': results = subtracted;
		break;
	case '*': results = multiplied;
		break;
	case '/': results = divided;
		break;
	}
}/*}}}*/

/* -------------------------------PASSING %-----------------------------------------
FUNCTION:          int mgPassing()
DESCRIPTION:       function for inputting the passing % for the mathgame
RETURNS:           void, no return;
----------------------------------------------------------------------------- */
void mgPassing(int mgArray[][6], int & playerNumber)
{/*{{{*/
	int choice;

	cout << "| WOULD YOU LIKE TO ENTER TEACHER MENU FOR CHANGING PASSING PERCENTAGE?: \n";
	cout << "| [1] YES \n";
	cout << "| [2] NO \n"; // if NO, passing is always set at 70%
	cout << "|-----------> "; cin >> choice;
	while (choice < 1 || choice > 2) // error correction for incorrect input
		choice = invalidIntChoice();

	if (choice == 1)
	{
		spaces(3);
		cout << "| Please Enter Number [1-10] to set Passing Percentage \n";
		cout << "| [1]0% [2]0% [3]0% [4]0% [5]0% [6]0% [7]0% [8]0% [9]0% [10]0% \n";
		cout << "|-----------> "; cin >> mgArray[playerNumber][5];
		while (mgArray[playerNumber][5] < 1 || mgArray[playerNumber][5] > 10) // Invalid Choice Correction
			mgArray[playerNumber][5] = invalidIntChoice();
		spaces(3);
	}
}/*}}}*/

/* ---------------------------GAME COMPLETE----------------------------------------------
FUNCTION:          void done()
DESCRIPTION:       game complete message.
RETURNS:           void, no return
NOTES:
----------------------------------------------------------------------------- */
void done()
{/*{{{*/
	cout << "----------------------------------------------------------- \n";
	cout << "*********************************************************** \n";
	cout << "   CONGRATULATIONS!! YOU HAVE FINISHED ALL MATH LEVELS! \n"
		"THE PROGRAM WILL NOW EXIT, IF YOU WOULD LIKE TO PLAY AGAIN, \n"
		"   PLEASE RELOAD THE PROGRAM AND 'START AS A NEW USER' \n"
		"                      GOOD BYE!!                         \n";
	cout << "*********************************************************** \n";
	cout << "----------------------------------------------------------- \n";
}/*}}}*/

/* ------------------------------- PAUSE -----------------------------------------
FUNCTION:          void pause()
DESCRIPTION:       just creates a pause between certain areas.
NOTES:
----------------------------------------------------------------------------- */
void pause(int dur)
{/*{{{*/
	int temp = time(NULL) + dur;
	while (temp > time(NULL));
}/*}}}*/

/* ---------------------------InvalidIntChoice----------------------------------------------
FUNCTION:          int invalidIntChoice()
DESCRIPTION:       Error handling for non-integer input for User-Input integer requests.
RETURNS:           returns choice; integer
NOTES:			   ask for integer on loop until integer amount is received.
----------------------------------------------------------------------------- */
int invalidIntChoice()
{/*{{{*/
	int choice;
	cout << "Please enter a valid menu choice: ";
	cin.clear();
	cin.ignore(10, '\n');
	cin >> choice;
	return choice;
}/*}}}*/

/* ---------------------------Spaces----------------------------------------------
FUNCTION:          int space()
DESCRIPTION:       spaces by count
----------------------------------------------------------------------------- */
void spaces(int reps)
{/*{{{*/
	for (int i = 0; i < reps; ++i)
		std::cout << "| \n";
}/*}}}*/

/* -------------------------------Jeopardy Menu-----------------------------------------
FUNCTION:          int jepMainMenu()
DESCRIPTION:       Main menu for Jeopardy game selections including new, load, return
RETURNS:           choice;
----------------------------------------------------------------------------- */
int jepMainMenu()
{/*{{{*/
	int choice;

	jepArt();
	cout << "        ===== WELCOME TO THE JEOPARDY MATH GAME! ====== \n";
	cout << "PLEASE MAKE YOUR SELECTION FROM THE CHOICE BELOW AND PRESS ENTER \n";
	spaces(3);
	cout << "| [1] START A NEW GAME OF JEOPARDY (UP TO 3 PLAYERS!) \n"
			"| [2] LOAD AND CONTINUE PREVIOUSLY SAVED GAME OF JEOPARDY\n"
		    "| [3] RETURN TO MAIN MENU SELECTION \n";
	cout << "|-----------> ";
	cin >> choice;

	return choice;
}/*}}}*/

/* -------------------------------load Jep array-----------------------------------------
FUNCTION:          void load_jepArray()
DESCRIPTION:       preloads informatio for text files into arrays for game (** this is not for loading a specific user game,
			       this is just for loading all information into arrays before selection of saved game, or new game creation)
RETURNS:           void, no return;
----------------------------------------------------------------------------- */
void load_jepArray(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5])
{/*{{{*/
	string cast;
	ifstream inputFile;

//===================LOADS NUMBER OF SAVE GAMES ==================================	
	inputFile.open("jepScores.txt");
	inputFile >> game;
	inputFile.close();
//================LOADS TXT FILE OF DISPLAY BOARD FOR SAVED GAMES=================
	inputFile.open("jepDisplayBoard.txt"); 
	for (int h = 0; h < 100; h++)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					inputFile >> jepBoard[h][i][j][k];
				}
			}
		}
	}
	inputFile.close();
//=========================LOADS PLAYER'S SCORES FOR SAVED GAMES=================
	inputFile.open("jepScores.txt");
	inputFile.ignore(4, '\n');
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			{
				inputFile >> jepScores[i][j];
			}
		}

	}
	inputFile.close();
//====================== LOADS LIST OF SAVED USER NAMES TO ARRAY ================
	inputFile.open("users.txt");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			{
				inputFile >> users[i][j];
			}
		}

	}
	inputFile.close();
//===============================================================================

}/*}}}*/

/* -------------------------------jeopardy art-----------------------------------------
FUNCTION:          void jepArt()
DESCRIPTION:       cool Jeopardy Art for the game ;)
RETURNS:           void, no return;
----------------------------------------------------------------------------- */
void jepArt()
{/*{{{*/
	system("cls");

	
	cout <<  " d8b                                                 888 \n";
	cout <<  " Y8P                                                 888 \n";
	cout <<  "  			                            d888 \n";
	cout <<  " 8888  .d88b.   .d88b.   88888b.  8888b. 888d888.  d8888 888  888 \n";
	cout <<  " '888 d8P  Y8b d88''88b 888 '88b    '88b 888P'  d88' 888 888  888 \n";
	cout <<	 "  888 88888888 888  888 888  888.d888888 888    888  888 888  888 \n";
	cout <<	 "  888 Y8b.     Y88..88P 888 d88P888  888 888    Y88b 888 Y88b 888 \n";
	cout <<	 "  888  'Y8888   'Y88P'  88888P' 'Y888888 888     'Y88888   Y88888 \n";
	cout <<	 "  888                   888                                   888 \n";
	cout <<  " d88P                   888                              Y8b d88P \n";
	cout <<  "888P'                   888                               'Y88P' \n";
	cout << " \n \n";
}	 /*}}}*/

/* -------------------------------jep main-----------------------------------------
FUNCTION:          int jepMain()
DESCRIPTION:       main switch for calling to other functions after making choice in jepMainMenu()
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
int jepMain()
{/*{{{*/
	int forward, game = 0;
	string users[100][3];
	int jepScores[100][4];
	string jepBoard[100][2][6][5];

	load_jepArray(game, users, jepScores, jepBoard);

	//jepDisplayBoard(game, users, jepScores, jepBoard);

	do // uses choice from mainMenu function in switch
	{
		switch (jepMainMenu())
		{
			case 1: forward = jepNewGame(game, users, jepScores, jepBoard);
			break;
			case 2: forward = jepLoadGame(game, users, jepScores, jepBoard);
			break;
			case 3: forward = 3;
		}
			if (forward == 1)
		 jepGame(game, users, jepScores, jepBoard);

	} while (forward != 3);




	cout << "exiting jeopardy game \n"; // if choice 3 is made, exits back to mgMainMenu
	pause(2);

	return 2;
}/*}}}*/

/* -------------------------------jep new game-----------------------------------------
FUNCTION:          int jepNewGame()
DESCRIPTION:       function for creation of new multiplayer (1-3 people) game
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
int jepNewGame(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5])
{/*{{{*/
	int choice, players;
	string line;

	system("cls");

	
	cout << "| HOW MANY PLAYERS? (1-3)";
	cout << "| ---> "; cin >> players;
	while (players < 1 || players > 3) // INCORRECT CHOICE FIXER
		players = invalidIntChoice();
	jepScores[game][3] = players;
	
//===== GETS PLAYERS NAMES =========
	cout << "| **Single word input - No spaces** \n"; // user must enter only one word for first or last name
	cout << "| PLAYER 1 FIRST NAME: ";
	cin >> users[game][0];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (players > 1)
	{
		cout << "| **Single word input - No spaces** \n"; // user must enter only one word for first or last name
		cout << "| PLAYER 2 FIRST NAME: ";
		cin >> users[game][1];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (players > 2)
	{
		cout << "| **Single word input - No spaces** \n"; // user must enter only one word for first or last name
		cout << "| PLAYER 3 FIRST NAME: ";
		cin >> users[game][2];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
//==================================

	cout << "| WELCOME TO THE GAME - ";
		for (int i = 0; i < players; i++)
			cout << users[game][i] << " - ";
		cout << endl;
	spaces(5);

	jepSaveGame(game, users, jepScores, jepBoard);

	cout << "| New game profile has been created and saved! \n \n";
	cout << "| [1] CONTINUE WITH NEW GAME \n"
			"| [2] RETURN TO JEOPARDY MAIN MENU \n";
	cout << "|-----------> ";
	cin >> choice;
	
	return choice;
}/*}}}*/

/* -------------------------------jep load game-----------------------------------------
FUNCTION:          int jepLoadGame()
DESCRIPTION:       this function loads all name lists (from users[][]) and based on numerical choice sets game#
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
int jepLoadGame(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5])
{/*{{{*/

	string saveList = "jepPlayersList.txt", cast, castUser;
	int choice, grabGame; 
	int nameRow = 0;

	system("cls");

	ifstream inputFile;

	load_jepArray(game, users, jepScores, jepBoard);

	cout << "| Hello, Returning User! \n";
	cout << "| List of users with saved Data: \n";
	cout << "| ********************************** \n";
	for (int i = 0; i < game; i++)
	{
		cout << "| GAME[" << i << "] ";
		for (int j = 0; j < 3; j++)
		{
			castUser = users[i][j];
			if (castUser == "X")
				castUser = "";
			cout << castUser << " ";
		}
		cout << endl;
	}
	cout << "| ********************************** \n"
		"| \n";
	cout << "| TO LOAD USER PROFILE ABOVE (Press 1) \n";
	cout << "| IF NO USER DATA EXIST (Press 2) \n"; // choice two for no user data and to create new data
	cout << "| ------------> ";

	cin.clear();
	cin >> choice;
		while (choice < 1 || choice > 2) // INCORRECT CHOICE FIXER
			choice = invalidIntChoice();

	if (choice == 1)
	{
		cout << "| Enter Game Number: \n";
		cin >> grabGame;
		while (grabGame < 0 || grabGame > game) // INCORRECT CHOICE FIXER
			grabGame = invalidIntChoice();
		game = grabGame;
		cout << "| Your previous game has been loaded! \n \n";
		cout << "| [1] CONTINUE WITH LOADED GAME \n"
				"| [2] RETURN TO MATH GAME MAIN MENU \n";
		cout << "|-----------> ";
		cin >> choice;
	}

	return choice;
}/*}}}*/

/* -------------------------------jep game-----------------------------------------
FUNCTION:          int jepGame()
DESCRIPTION:       function that handles all the question askings, level changing, and code which handles the final round
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
int jepGame(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5])
{/*{{{*/
	int choice = 0, lvl = 0, playerUp = 0, col, seed, right = 0, level = 0, xTotal = 0, jep3 = 0, winner;
	int row, dd = 0, doubler = 1, ddrow = 0, ddcol = 0;
	int remainder, remainderAnswer, randIndex, randUser;
	int randTerm1, randTerm2;
	int answer, results, multiplied = 0, mixed = 0;
	long lvlA[10] = { 9,9,99,99,999,999,9999,9999,99999,99999 };
	int bet[3];
	bool lvlUp = true;
	char sym, mixedMath[4] = { '+', '-', '*','/' };
	string jep3Questions[4] = { "Who was the 1st president of the united states??",
								"Who was the 2nd president of the united states??",
								"Who was the 3rd president of the united states??",
								"Who was the 4th president of the united states??" };
	string jep3Answers[4] = { "George Washington", "John Adams", "Thomas Jefferson", "James Madison" };
	seed = time(0);
	srand(seed);
	randUser = rand() % jepScores[game][3]; // pick random user to start 
	randIndex = rand() % 4;

	xTotal = jepQuestionCount(jepBoard, game);
	if (xTotal > 24 && xTotal < 50)
	{
		level = 1;
		lvl = 5;
	}
	if (xTotal > 49)
		jep3 = 1;

	jepDisplayBoard(game, users, jepScores, jepBoard, level);

	while (choice != 3 && jep3 < 1)
	{
		
		jepDisplayBoard(game, users, jepScores, jepBoard, level);
		choice = jepGameMenu(game, randUser, users);

		if (choice == 2)
			jepRules();

		if (choice == 1 && jep3 < 1)
		{
			ddrow = ((rand() % 5) + 1);
			ddcol = ((rand() % 5) + 1);

			
			if (xTotal > 24 && lvlUp == true)
			{
				dd = 0; lvlUp = false;
			}

			//cout << " ddcol: " << ddcol << "ddrow: " << ddrow;

			cout << "Math Type \n" << "----> ";
			cin >> col; col--;
			cout << "For \n" << "----> ";
			cin >> row; row--;

			while (jepBoard[game][level][row + 1][col] == "X")
			{
				cout << "That Question has already been answered, Please make another selection. \n";
				cout << "Math Type \n" << "----> ";
				cin >> col; col--;
				cout << "For \n" << "----> ";
				cin >> row; row--;
			}

			if ((row + 1) == ddrow && (col + 1) == ddcol && dd < 2)
			{
				doubler = 2;
				dd++;
			
				cout << "DAILY DOUBLE!! DAILY DOUBLE!! \n"; pause(1);
				cout << "DAILY DOUBLE!! DAILY DOUBLE!! \n"; pause(1);
				cout << "DAILY DOUBLE!! DAILY DOUBLE!! \n"; pause(1);
				cout << "DAILY DOUBLE!! DAILY DOUBLE!! \n"; pause(1);
				cout << "DAILY DOUBLE!! DAILY DOUBLE!! \n"; pause(1);

				spaces(2);
				cout << "| THE FOLLOWING QUESTION IS NOW WORTH DOUBLE THE POINTS TO THE CONTESTANT WHO ANSWERS IT CORRECTLY! \n";
			}




			switch (col)
			{
			case 0: sym = '+';
				break;
			case 1:	sym = '-';
				break;
			case 2:	sym = '*';
				break;
			case 3:	sym = '/';
				break;
			case 4:	sym = 'm';
				break;
			}


			randTerm1 = (rand() % lvlA[(row + lvl)]) + 1;
			randTerm2 = (rand() % lvlA[(row + lvl)]) + 1;


			if ((row % 2) != 0) // For xB levels, creates odd integers
				randTerm1 = -randTerm1;
			randIndex = rand() % 4; // Random (0-3) symbol choice for mixed math
			if (sym == 'm') // for mixed math, randomizes symbol
				sym = mixedMath[randIndex];
			if (abs(randTerm2) > abs(randTerm1)) //FLIPS TERMS IF 2nd term (or Denom) is bigger (ABSOLUTE VALUE)
			{
				randTerm1 = randTerm1 + randTerm2;
				randTerm2 = randTerm1 - randTerm2;
				randTerm1 = randTerm1 - randTerm2;
			}
			remainder = 0;
			remainderAnswer = 0;


			math(sym, randTerm1, randTerm2, results, remainder);

			cout << endl;
			cout << "--------- \n";
			cout << randTerm1 << " " << sym << " " << randTerm2 << "? \n"; // display current math question


			cout << "PRESS YOUR BUZZ IN KEY FIRST TO ANSWER! ----> \n";
			char key = 'q';
			while (!(key == 'a' || key == 'A' || key == 'g' || key == 'G'
				|| key == 'l') || key == 'L')
			{

				//see if it's a char you want to recognize 
				switch (key) 
				{ 
				case 'a': case 'A': cout << users[game][0] << " has Chimed In, Please answer the math question: \n" << endl;
					randUser = 0;
					break;
				case 'g': case 'G': cout << users[game][1] << " has Chimed In, Please answer the math question: \n" << endl;
					randUser = 1;
					break;
				case 'l': case 'L': cout << users[game][2] << " has Chimed In, Please answer the math question: \n" << endl;
					randUser = 2;
					break;
				}
			}

			playerUp = randUser;

			if (sym == '/')
				cout << " \n please enter Quotient now, \n and Remainder in next input box: \n --------->>  ";
			else
				cout << "--------->";
			cin >> answer;

			while (cin.fail()) // error correction for non-int input
				invalidIntChoice();
			if (sym == '/') // IF STATEMENT FOR DIVISION ONLY
			{
				cout << "--------->>  "; cin >> remainderAnswer;
			}

			answer += remainderAnswer;
			if (answer == (results + remainder))
			{
				cout << "CORRECT!, " << users[game][randUser] << "! \n";
				cout << "You Have Been awarded " << ((row + 1) * 100 * doubler) << " Points!, You make choose again! \n";
				jepScores[game][randUser] += ((row + 1) * 100 * doubler);
				jepBoard[game][level][row + 1][col] = "X";
				xTotal++;
			}
			else
			{
				cout << "ooooooooohhh I am sorry that is INCORRECT... \n";
				while (randUser == playerUp)
					randUser = rand() % jepScores[game][3];
				cout << users[game][playerUp] << ", has been deducted " << (row * 100) << " Points \n" << users[game][randUser] << ", Please choose next \n";
				jepScores[game][playerUp] -= ((row + 1) * 100);
			}

			doubler = 1;
			jepSaveGame(game, users, jepScores, jepBoard);

			}

			if (xTotal > 24)
			{
				level = 1;
				lvl = 5;
			}
			
			if (xTotal > 49)
				jep3 = 1;

		}

	if (jep3 == 1)
	{
	
		cout << endl;
		cout << "         --==  WELCOME TO FINAL Jeopardy!  ==-- \n"; pause(2);
		cout << "| You will be asked one final question. Please write your answer and the amount you wager on a sheet of paper \n"; pause(2);
		cout << "| the category is: \n"; pause(2);
		cout << "| US PRESIDENTS!! \n"; pause(2);

		for (int i = 0; i < jepScores[game][3]; i++)
		{
			cout << "| " << users[game][i] << ", please wager an amount: ";
			cin >> bet[i];
			while (bet[i] > jepScores[game][i])
			{
				cout << "| " << users[game][i] << ", please wager less that you earned total of " << jepScores[game][i] << endl;
				cout << "| If you are at a negative score, please enter 0 \n";
				cout << "| ----> "; cin >> bet[i];
				
			}
		}

		cout << "| the questions is...\n"; pause(2);
		cout << "| " << jep3Questions[randIndex] << endl;
		cout << "| You have 15 seconds to answer!" << endl; pause(2);
		cout << "| ";
		for (int i = 0; i < 15; i++)
		{
			pause(1); cout << (i + 1) << " "; // just look like its saving :/
		}
		cout << "Time is UP!! \n"; pause(3);
		cout << "The correct answer is: " << jep3Answers[randIndex] << endl;

		for (int i = 0; i < jepScores[game][3]; i++)
		{
			char fCorrect;
			spaces(2);
			cout << "| " << users[game][i] << ", did you answer correctly? (y/n) \n";
			cout << "| ----> "; cin >> fCorrect;
			if (fCorrect == 'y' && 'Y')
			{
				cout << "| Great Work " << users[game][i] << ", " << bet[i] << " has beed added to your score!! \n";
				jepScores[game][i] += bet[i];
			}
			else
			{
				cout << "| Sorry " << users[game][i] << ", " << bet[i] << " has beed removed from your score \n";
				jepScores[game][i] -= bet[i];
			}
		}

		cout << "| that is the end of our Jeopardy Math Game!!";
		spaces(2);
		cout << "| [" << setw(10); cout << users[game][0] << " :" << setw(5); cout << jepScores[game][0] << "] [" << setw(10); cout << users[game][1] << " :" << setw(5); cout << jepScores[game][1] << "] [" << setw(10); cout << users[game][2] << " :" << setw(5); cout << jepScores[game][2] << "]|" << endl;

		int temp = 0;
		for (int i = 0; i < 3; i++)
		{
			if (jepScores[game][i] > temp)
			{
				temp = jepScores[game][i];
				winner = i;
			}			
		}

		if (temp == 0)
		{
			cout << "All scores below 0, there are no winners here\n";
		}
		else
		{
			cout << "| The winner with the highest score of " << jepScores[game][winner] << ", is " << users[game][winner] << "!!"; pause(5);
			spaces(2);
			cout << "| Goodbye and please play again! \n"; pause(10);
		}

	}

	jepSaveGame(game, users, jepScores, jepBoard);

	return 1;
}/*}}}*/

/* -------------------------------jep question counter-----------------------------------------
FUNCTION:          int jepQuestionCount()
DESCRIPTION:      used in jepGame, counts the number of questions answered which determines current level.
RETURNS:           xTotal (int);
----------------------------------------------------------------------------- */
int jepQuestionCount(string jepBoard[][2][6][5], int game)
{/*{{{*/
	int xTotal = 0;

	for(int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 5; k++)
			{
				if (jepBoard[game][i][j][k] == "X")
					xTotal++;
			}

	return xTotal;
}/*}}}*/

/* -------------------------------jep save game-----------------------------------------
FUNCTION:          int jepSaveGame()
DESCRIPTION:       saves game progress from all arrays back to text files
RETURNS:           void;
----------------------------------------------------------------------------- */
void jepSaveGame(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5])
{/*{{{*/
	string cast;
	ofstream outputFile;


	//================SAVES TXT FILE OF DISPLAY BOARD FOR SAVED GAMES=================
	outputFile.open("jepDisplayBoard.txt");
	for (int h = 0; h < 100; h++)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					outputFile << jepBoard[h][i][j][k];
					outputFile << " ";
				}
				outputFile << endl;
			}
			outputFile << endl;
		}
		outputFile << endl;
	}
	outputFile.close();

	//===================SAVES NUMBER OF SAVE GAMES AND SCORES ==================================	
	outputFile.open("jepScores.txt");
	outputFile << (game + 1);  // <<---- adds +1 to 'game' count so that next game created will occupy next empty spot and so that it will load correct amount of 'user' array
	outputFile << endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
				outputFile << jepScores[i][j];
				outputFile << " ";
		}
		outputFile << endl;
	}
	outputFile.close();
	//====================== SAVES LIST OF SAVED USER NAMES TO ARRAY ================
	outputFile.open("users.txt");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
		{
				outputFile << users[i][j];
				outputFile << " ";
		}
		outputFile << endl;
	}
	outputFile.close();
	//===============================================================================

	cout << "| \n" << "| Information Saved \n";
	pause(3);
}/*}}}*/

/* -------------------------------jep display board-----------------------------------------
FUNCTION:          int jepDisplayBoard()
DESCRIPTION:       uses the passed variables and arrays to display information to the Jeopardy board for each level.
RETURNS:           none; void;
----------------------------------------------------------------------------- */
void jepDisplayBoard(int & game, string users[][3], int jepScores[][4], string jepBoard[][2][6][5], int lvl)
{	/*{{{*/

	//cout << "board 1 or 2?: \n";
	//cin >> lvl;
	//cout << "FOR TESTING!: Which game number? \n";
	//cin >> game;
	//lvl--;



	jepArt();

	cout << "   ============================================================== \n";
	cout << "   |||||" << setw(7); cout << jepBoard[game][lvl][0][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][0][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][0][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][0][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][0][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";;
	cout << "   |<1>|" << setw(7); cout << jepBoard[game][lvl][1][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][1][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][1][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][1][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][1][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";
	cout << "   |<2>|" << setw(7); cout << jepBoard[game][lvl][2][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][2][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][2][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][2][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][2][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";
	cout << "   |<3>|" << setw(7); cout << jepBoard[game][lvl][3][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][3][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][3][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][3][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][3][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";
	cout << "   |<4>|" << setw(7); cout << jepBoard[game][lvl][4][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][4][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][4][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][4][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][4][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";
	cout << "   |<5>|" << setw(7); cout << jepBoard[game][lvl][5][0] << "   " << "||" << setw(7); cout << jepBoard[game][lvl][5][1] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][5][2] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][5][3] << "  " << "||" << setw(7); cout << jepBoard[game][lvl][5][4] << "   " << "||" << endl;
	cout << "   ============================================================== \n";
	cout << "   =====[ ANSWERED QUESTIONS: (X) ][ DAILY DOUBLES: (D+D) ]====== \n";
	cout << "   ============================================================== \n";
	cout << "   | " << "PLAYER SCORES:                                             | \n";
	cout << "   | [" << setw(10); cout << users[game][0] << " :" << setw(5); cout << jepScores[game][0] << "] [" << setw(10); cout << users[game][1] << " :" << setw(5); cout << jepScores[game][1] << "] [" << setw(10); cout << users[game][2] << " :" << setw(5); cout << jepScores[game][2] << "]|" << endl;
	cout << "   -------------------------------------------------------------- \n";
	cout << "    **BUZZ IN KEY** " << setw(11); cout << users[game][0] << " [A]" << setw(11); cout << users[game][1] << " [G]" << setw(11); cout << users[game][2] << " [L]";
	cout << endl;
}/*}}}*/

/* -------------------------------jep Game Menu-----------------------------------------
FUNCTION:          int jepGameMenu()
DESCRIPTION:       askes the user by name who is currently selected if they would like to choose another questions, see rules, or go back.
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
int jepGameMenu(int & game, int & randUser, string users[][3])
{/*{{{*/
	int choice;
	cout << "| \n";
	cout << "| PLEASE MAKE YOUR SELECTION FROM THE CHOICE BELOW AND PRESS ENTER \n";
	cout << "|  [1] ANSWER A JEOPARDY QUESTION --> " << users[game][randUser] << ", YOU ARE UP!! \n"
			"|  [2] READ THE RULES OF THE JEOPARDY MATH GAME...\n"
			"|  [3] SAVE PROGRESS AND EXIT TO JEOPARDY MAIN MENU \n";
	cout << "|-----------> ";
	cin >> choice;
	while (choice < 1 || choice > 3)
		choice = invalidIntChoice();

	return choice;
}/*}}}*/

/* -------------------------------jep Rules-----------------------------------------
FUNCTION:          void jepRules()
DESCRIPTION:       displays the rules of how to play to jeopardy game.
RETURNS:           choice (int);
----------------------------------------------------------------------------- */
void jepRules()
{/*{{{*/
	int choice = 0;

	while (choice != 1)
	{
	jepArt();
	cout << "                                              ----==== THE RULES OF MATH JEOPARDY ====---- \n";
	cout << "========================================================================================================================================== \n \n";
	cout << " > A Game of Jeopardy Consist of Three rounds of Jeopardy:\n";
	cout << "       * A Level 1 and level 2 Jeopardy board with math questions based on 5 categories:\n";
	cout << "            * +<1>+ Addition;  -<2>- Subtraction; *<3>* Multiplication;  /<4>/ Division;  ?<5>? Mix-O-Math. \n";
	cout << "            * Select the Math type by inputting the corresponding number.";
	cout << "            * then, select for how many points. \n";
	cout << "       * In the Level 3 of Jeopardy, there will be a final Trivia Question where you can wager your accumulated points before \n"
		    "         the question is presented, correct responses double your points, incorrect responses will lose you the wagered amount...\n \n";
	cout << " > New games and loaded games will start off with a randomly selected player that will choose the next question \n";
	cout << "   the player who buzzes in the fastest will get a chance to answer first. If they answer correct, they will choose the next question \n";
	cout << "   however, if they answer incorrect another random player will be chosen\n \n";
	cout << " > Daily-Double: each level will contain two Daily-Double (DD) questions randomly hidden on the board, finding one will make that \n";
	cout << "   question worth twice as many points to the player who buzzez in and answers correctly\n \n";

	cout << " > You may Save and Quit after each questions and return to your game at any time. HAVE FUN!! \n \n";
	cout << "========================================================================================================================================== \n";
	cout << "Press 1, and enter to return to main menu: "; cin >> choice;

	}



}/*}}}*/

