#include <iostream>
#include <string>
using namespace std;

int main() {
    // Main C++ variable types


    string userName = "Akaisha";
    string applicationName = "Text Adventure Game!";
    float versionNumber = 1.0;

    string characterName = "Imogen";              // text
    int health = 95;                             // whole number
    double gold = 20.5;                           // decimal number
    char rank = 'A';                              // single character
    bool hasHealth = true;                        // true or false
          
    cout << "*******************************" << endl;
    cout << "------WELCOME TO THE GAME------" << endl;
    cout << "*******************************" << endl;
    
    cout << "Username: " << userName << endl;
    cout << "Application Name: " << applicationName << endl;
    cout << "Version Number: " << versionNumber << endl;
    
    cout << "*******************************" << endl;
    cout << "-----CHARACTER INFORMATION-----" << endl;
    cout << "*******************************" << endl;

    
    cout << "Name: " << characterName << endl;
    cout << "Health: " << health << "/100" << endl;
    cout << "Gold: $" << gold << endl;
    cout << "Rank: " << rank << endl;
    cout << "Alive: " << hasHealth << endl;

    return 0;
}