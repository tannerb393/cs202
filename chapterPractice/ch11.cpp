/*   ----------------------------------------------------------------------------
FILE NAME:     Pointer2.CPP
DESCRIPTION:   Describe file
PURPOSE:       Describe purpose of file
USAGE:         give instructions for running the program from command line
EXAMPLES:      give examples on how to run the program
PARAMETERS:    List command line parameters and their purposes
EXIT CODES:    0 = success other = error
COMPILATION:   Tell another programmer what tools development you used to build the .exe
NOTES:         if any
MODIFICATION HISTORY:
Author              Date        Modification(s)
-------------   -----------    ---------------
Tanner_Benavides  09-05-2017     1.0 / like test_v1.cpp
Tanner_Benavides  09-05-2017     2.0 / like test_v2.cpp
----------------------------------------------------------------------------- */
#include <iostream> // main
#include <string> // string input
#include <cstring> // for cstring input
#include <cstdlib> // char libraby
#include <cctype> // for char mods
#include <iomanip> // for set mods

using namespace std;

struct Player // structure name always Capitalized
{
    string name; // member of structure
    int classes;
    int level; // member of structure
    double str; // members
    double def; // member  
    double spd; // member


}; // DONT FORGET the ; for the end of a structure


int main ()

{
    Player hero = {"cloud", 1, 1, 10, 10, 10};
    // defines a variable (hero) to be used in int main with datatype Player
    // '= {' begins the initialization of hero members in the Player structure (not necessary) 

    Player companion[3] = {{"biggs", 1, 1, 10, 10, 10}, // initializes array spot 1 for Player companion (and 2 and 3 below) 
                          {"wedge", 1, 1, 10, 10, 10}, 
                          {"sephiroth", 1, 1, 10, 10, 10}};

    string heroClasses[5] = {"<====|=o Barbarian", "=|== Paladin", "x)----- Summoner", "**** Mage","o====== Priest"};

    cout << "Welcome to the start of your journey!, Please type the  name of your hero: ";
    getline(cin, hero.name); // get full name for string if they enter two words
    cout << "Choose your Class! Pick a number 1-5 \n";
    for (int i = 0 ; i < 5; i++)
        cout << (i + 1) << " " << heroClasses[i] << endl;
    cin >> hero.classes;
    cout << fixed << showpoint << setprecision(2);
    cout << "Starting stats: Strength " << hero.str << ", Defense " << hero.def << ", Speed " << hero.spd << endl;

    for (int i = 0 ; i < 3 ; i ++)
    {
        cout << "Please type the  name of Companion #" << i+1 << endl;
        cin.ignore();
        getline(cin, companion[i].name); // get full name for string if they enter two words
        cout << "Choose their class (pick 1-5): \n";
        for (int i = 0 ; i < 5; i++)
            cout << (i + 1) << " " << heroClasses[i] << endl; // shows list of classes
        cin >> companion[i].classes;
        cout << fixed << showpoint << setprecision(2); // force two digits past . 
        cout << "Starting stats: Strength " << hero.str << ", Defense " << hero.def << ", Speed " << hero.spd << endl;
    }





   return 0;
}
