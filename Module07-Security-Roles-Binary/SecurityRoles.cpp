#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//character creation variables
string inputClass = "[unknown]";
string inputName = "[unknown]";
string inputWeapon = "[unknown]";



//Character Class
//-------------------------------------------------------------------
class Character {
private:
    static int nextCharacterID;
    string name;
    int characterID;
    string charClass;
    string weapon;
    int level;
    int health;
    double gold;

public:
    // Default Constructor
    Character()
    {
        name = "";
        characterID = 0;
        charClass = "";
        weapon = "";
        level = 1;
        health = 100;
        gold = 0;
    }
    // Constructor
    Character(string characterName, string characterClass, string characterWeapon) 
    {
        name = characterName;
        characterID = generateCharacterID();
        charClass = characterClass;
        weapon = characterWeapon;
        level = 1;
        health = 100;
        gold = 0;
    }

    // Member function
    void displayCharacter() 
    {
        cout << "Name: " << name << endl;
        cout << "Character ID: " << setfill('0') << setw(8) << characterID << setfill (' ') << endl;
        cout << "Class: " << charClass << endl;
        cout << "Weapon: " << weapon << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << "/100" << endl;
        cout << "Gold: " << gold << endl;
    }
    void duelCharacters(Character character2)
    {
       if(level > character2.level)
       {
           cout << name << " Wins!" << endl;
       } 
       else
       {
           cout << character2.name << " Wins!" << endl;
       }
    }
    int generateCharacterID()
    {
       return nextCharacterID++;
    }


    // Getter
    string getName() {
        return name;
    }
    int getCharacterID() {
        return characterID;
    }
    string getClass() {
        return charClass;
    }
    string getWeapon() {
        return weapon;
    }
    int getLevel() {
        return level;
    }
    int getHealth() {
        return health;
    }
    double getGold() {
        return gold;
    }



    // Setter
    void setName(string newName) {
        name = newName;
    }
    void setClass(string newClass) {
        charClass = newClass;
    }
    void setWeapon(string newWeapon) {
        weapon = newWeapon;
    }
    void setLevel(int newLevel) {
        level = newLevel;
    }
    void setHealth(int newHealth) {
        health = newHealth;
    }
    void setGold(double newGold) {
        gold = newGold;
    }

};

int Character::nextCharacterID = 1;


//User Class
//------------------------------------------------------------------------


class User {
protected:
    string username;
public:
    User(string name) : username(name) {}
    void displayUsername()
    {
         cout << "Current User: " << username << endl;
    }
    bool canAdd()
    {
         return true;
    }
    bool canView()
    {
         return true;
    }
    virtual bool canDelete()
    {
         return false;
    }

    
};


//Admin Class
//------------------------------------------------------------------------


class Admin : public User {
public:
    Admin(string name) : User(name) {}
    bool canDelete() override
    {
         return true;
    }
};


//Functions for main
//------------------------------------------------------------------------


void chooseName() {
    
    cout << "\nPlease enter character name: ";
    cin >> inputName;
    cout << "\nYou chose " + inputName + "\n";
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
                inputClass = "Warrior";
                cout << "\nYou chose " + inputClass + "\n";
                break;
            case 2:
                inputClass = "Cleric";
                cout << "\nYou chose " + inputClass + "\n";
                break;
            case 3:
                inputClass = "Ranger";
                cout << "\nYou chose " + inputClass + "\n";
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
                inputWeapon = "Sword";
                cout << "\nYou chose " + inputWeapon + "\n";
                break;
            case 2:
                inputWeapon = "Crossbow";
                cout << "\nYou chose " + inputWeapon + "\n";
                break;
            case 3:
                inputWeapon = "Dagger";
                cout << "\nYou chose " + inputWeapon + "\n";
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
    }

}
void finalizeCharacter(Character characters[], int &characterCount) {
    if (characterCount >= 5)
    {
         cout << "Character sorage is full!" << endl;
         return;
    }
    characters[characterCount] = Character(inputName, inputClass, inputWeapon);
    cout << endl << "Character created successfully!" << endl;
    
    characterCount++;
    inputName = "[unknown]";
    inputClass = "[unknown]";
    inputWeapon = "[unknown]";
    
}

void viewCharacter() {
    cout << "\n**** Your Character ****\n" << endl;
    cout << "Name: " + inputName << endl;
    cout << "Class: " + inputClass << endl;
    cout << "Weapon: " + inputWeapon << endl;
}

void displayAllCharacters(Character characters[], int characterCount)
{
    cout << endl;
    for (int i = 0; i < characterCount; i++)
    {
       characters[i].displayCharacter();
       cout << endl;
    }
}

int binarySearch(Character characters[], int characterCount, int targetID)
{
    int left = 0, right = characterCount - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (characters[mid].getCharacterID() == targetID) return mid;
        if (characters[mid].getCharacterID() < targetID) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


void deleteCharacter(Character characters[], int &characterCount)
{
    int deleteID;
    
    cout << endl << "Enter the ID number of the character you want to delete: ";
    cin >> deleteID;
    
    int index = binarySearch(characters, characterCount, deleteID);
    
    if (index == -1)
    {
        cout << "Character not found!" << endl;
        return;
    }
    
    for(int i = index; i < characterCount-1; i++)
    {
        characters[i] = characters[i+1];
    }
    
    characterCount--;
    
    cout << "Character deleted!" << endl;
}


//Main
//-------------------------------------------------------------------



int main() {
    Character characters[5];
    
    int choice = 0;
    int characterCount = 0;
    
    User regularUser("Player");
    Admin adminUser("Administrator");
    
    User* currentUser;
    
    int userType;
    
    cout << "Select a user type:" << endl;
    cout << "1. Regular User" << endl;
    cout << "2. Administrator" << endl;
    cout << "Choose and option: ";
    
    cin >> userType;
    
    if(userType ==2)
    {
       currentUser = &adminUser;
    }
    else
    {
       currentUser = &regularUser;
    }

    while (choice != 8) {
        cout << "\n=== MY CHARACTER CREATION ===" << endl;
        cout << "1. Name" << endl;
        cout << "2. Class" << endl;
        cout << "3. Weapon" << endl;
        cout << "4. View Character" << endl;
        cout << "5. Finalize Character" << endl;
        cout << "6. Display All Characters" << endl;
        cout << "7. Delete Character" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if(currentUser->canAdd())
                {
                  chooseName();
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 2:
                if(currentUser->canAdd())
                {
                  chooseClass();
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 3:
                if(currentUser->canAdd())
                {
                  chooseWeapon();
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 4:
                if(currentUser->canView())
                {
                  viewCharacter();
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 5:
                if(currentUser->canAdd())
                {
                  finalizeCharacter(characters, characterCount);
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 6:
                if(currentUser->canView())
                {
                  displayAllCharacters(characters, characterCount);
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 7:
                if(currentUser->canDelete())
                {
                  deleteCharacter(characters,characterCount);
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 8:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    
    

    return 0;
}


//------------------------------------------------------------------------

