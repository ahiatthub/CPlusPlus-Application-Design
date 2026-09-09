#include <iostream>
#include <string>
using namespace std;

string characterClass;
string name;
string weapon;
string ability;

void chooseName() {
    
    cout << "\nPlease enter character name: ";
    cin >> name;
    cout << "\nYou chose " + name + "\n";
}

void chooseClass() {
    int classChoice = 0;
    
    cout << "\nPlease choose a class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Cleric" << endl;
    cout << "3. Ranger" << endl;
    cout << "Choose an option: ";
    cin >> classChoice;
    
    switch (classChoice) {
            case 1:
                characterClass = "Warrior";
                cout << "\nYou chose " + characterClass + "\n";
                break;
            case 2:
                characterClass = "Cleric";
                cout << "\nYou chose " + characterClass + "\n";
                break;
            case 3:
                characterClass = "Ranger";
                cout << "\nYou chose " + characterClass + "\n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
    }

}

void chooseWeapon() {
    int weaponChoice = 0;
    
    cout << "\nPlease choose a weapon:" << endl;
    cout << "1. Sword" << endl;
    cout << "2. Crossbow" << endl;
    cout << "3. Dagger" << endl;
    cout << "Choose an option: ";
    cin >> weaponChoice;
    
    switch (weaponChoice) {
            case 1:
                weapon = "Sword";
                cout << "\nYou chose " + weapon + "\n";
                break;
            case 2:
                weapon = "Crossbow";
                cout << "\nYou chose " + weapon + "\n";
                break;
            case 3:
                weapon = "Dagger";
                cout << "\nYou chose " + weapon + "\n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
    }

}
void chooseAbility() {
    int abilityChoice = 0;
    
    cout << "Please choose an ability:" << endl;
    cout << "1. Invisibility" << endl;
    cout << "2. Healing" << endl;
    cout << "3. Summoning" << endl;
    cout << "Choose an option: ";
    cin >> abilityChoice;
    
    switch (abilityChoice) {
            case 1:
                ability = "Invisibility";
                cout << "\nYou chose " + ability + "\n";
                break;
            case 2:
                ability = "Healing";
                cout << "\nYou chose " + ability + "\n";
                break;
            case 3:
                ability = "Summoning";
                cout << "\nYou chose " + ability + "\n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
    }

}
void viewCharacter() {
    cout << "\n**** Your Character ****\n" << endl;
    cout << "Name: " + name << endl;
    cout << "Class: " + characterClass << endl;
    cout << "Weapon: " + weapon << endl;
    cout << "Ability: " + ability << endl;
}



int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== MY CHARACTER CREATION ===" << endl;
        cout << "1. Name" << endl;
        cout << "2. Class" << endl;
        cout << "3. Weapon" << endl;
        cout << "4. Ability" << endl;
        cout << "5. View Character" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                chooseName();
                break;
            case 2:
                chooseClass();
                break;
            case 3:
                chooseWeapon();
                break;
            case 4:
                chooseAbility();
                break;
            case 5:
                viewCharacter();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}