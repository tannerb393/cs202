/*   ----------------------------------------------------------------------------
FILE NAME:     ch11.cpp
DESCRIPTION:   chapter 11, structures
----------------------------------------------------------------------------- */
//**Library**///*{{{*/
#include <iostream> // main
#include <string> // string input
#include <cstring> // for cstring input
#include <cstdlib> // char libraby
#include <cctype> // for char mods
#include <iomanip> // for set mods
#include <fstream> // for file work/*}}}*/

using namespace std;

struct Player // structure name always Capitalized
{
    string name; // member of structure
    string classes; //enumerator class
    int level; // member of struct
    double str; // member
    double def; // member  
    double spd; // member

}; // DONT FORGET the ; for the end of a structure


int main ()/*{{{*/

{
    Player hero = {"cloud", "Soldier", 1, 10, 10, 10};
    
    // defines a variable (hero) to be used in int main with datatype Player
    // '= {' begins the initialization of hero members in the Player structure (not necessary) 

   
    Player companion[3] = {{"biggs","Barbarian", 1, 10, 10, 10}, 
                           {"wedge", "Barbarian", 1, 10, 10, 10}, 
                           {"sephiroth", "Barbarian", 1, 10, 10, 10}};// initializes array spot 1 for 
                                                                   //Player companion (and 2 and 3 below) 
    

    cout << "Welcome to the start of your journey!, Please type the  name of your hero: ";
    getline(cin, hero.name); // get full name for string if they enter two words
    cout << "Choose your Class!\n";
    cin >> hero.classes;
    cout << fixed << showpoint << setprecision(2);
    cout << "Starting stats: Strength " << hero.str << ", Defense " << hero.def << ", Speed " << hero.spd << endl;

    for (int i = 0 ; i < 3 ; i ++)
    {
        cout << "Please type the  name of Companion #" << i+1 << endl;
        cin.ignore();
        getline(cin, companion[i].name); // get full name for string if they enter two words
        cout << "Choose their class: \n";
        cin >> companion[i].classes;
        cout << fixed << showpoint << setprecision(2); // force two digits past . 
        cout << "Starting stats: Strength " << hero.str << ", Defense " << hero.def << ", Speed " << hero.spd << endl;
    }
    cout << "welcome to the game " << hero.name << ", you are a " << hero.classes << " at level "
        << hero.level << " ,you will start with " << hero.str << " strength, " << hero.def << " defense, and "
        << hero.spd << " speed.\n";
    for (int i = 0; i < 3; i++)
    {
            cout << "companion " << i << ": " << companion[i].name  << ", "<< companion[i].classes << ", "
                << companion[i].level << ", "<< companion[i].str  << ", " << companion[i].def
                << ", "<< companion[i].spd << endl;
    }

    fstream dataFile; // fstream object name 'dataFile'
    cout << "saving information... ";
    dataFile.open("ch12.txt", ios::out);
    dataFile << companion[1].name;
    dataFile.close();


   return 0;
}/*}}}*/
