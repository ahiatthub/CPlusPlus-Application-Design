#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
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
    string aiBackstory;

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
        aiBackstory = "";
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
        aiBackstory = name + " ";
        
        //First sentence
        if(charClass == "Warrior")
        {
            aiBackstory += "is a fearless warrior from the town of RavenHollow. ";
        }
        else if(charClass == "Cleric")
        {
            aiBackstory += "is a cunning cleric from a village called Willowmere. ";
        }
        else if(charClass == "Ranger")
        {
            aiBackstory += "is a strategic ranger from the isle of Eldermoor. ";
        }
        
        //Second sentence
        if(weapon == "Sword")
        {
            aiBackstory += "They have spent many years mastering the sword to strengthen their skills in combat.";
        }
        else if(weapon == "Crossbow")
        {
            aiBackstory += "They prefer to fight from afar, opting for the crossbow.";
        }
        else if(weapon == "Dagger")
        {
            aiBackstory += "They like to take a stealthy approach, favoring the dagger as their weapon.";
        }
        
        

        
    }
    // Load from file constructor
    Character(int id, string characterName, string characterClass, string characterWeapon, int characterLevel, int characterHealth, double characterGold, string characterAiBackstory)
    {
        name = characterName;
        characterID = id;
        charClass = characterClass;
        weapon = characterWeapon;
        level = characterLevel;
        health = characterHealth;
        gold = characterGold;
        aiBackstory = characterAiBackstory;
        
        nextCharacterID = max(nextCharacterID, id + 1);

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
        cout << "AI Backstory: " << aiBackstory << endl;
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
    string getAiBackstory() {
        return aiBackstory;
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
    void setAiBackstory(string newBackstory) {
        aiBackstory = newBackstory;
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

//Choose name
void chooseName() {
    
    cout << "\nPlease enter character name: ";
    getline(cin >> ws, inputName);
    cout << "\nYou chose " + inputName + "\n";
}


//Choose class from list
void chooseClass() {
    int classChoice = 0;
    
    cout << "\nPlease choose a class:" << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Cleric" << endl;
    cout << "3. Ranger" << endl;
        
    while (true)
    {
         cout << "Choose an option: ";
         if (cin >> classChoice && classChoice > 0 && classChoice < 4)
         {
            break;
         }
         cout << "Invalid Input. Please enter a new choice.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         
    }
    
    
    
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

// Choose weapon from list
void chooseWeapon() {
    int weaponChoice = 0;
    
    cout << "\nPlease choose a weapon:" << endl;
    cout << "1. Sword" << endl;
    cout << "2. Crossbow" << endl;
    cout << "3. Dagger" << endl;
    
    while (true)
    {
         cout << "Choose an option: ";
         if (cin >> weaponChoice && weaponChoice > 0 && weaponChoice < 4)
         {
            break;
         }
         cout << "Invalid Input. Please enter a new choice.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         
    }

    
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

// Finalize character currently in creation
void finalizeCharacter(Character characters[], int &characterCount) {
    if (characterCount >= 5)
    {
         cout << "Character storage is full!" << endl;
         return;
    }
    characters[characterCount] = Character(inputName, inputClass, inputWeapon);
    cout << endl << "Character created successfully!" << endl;
    
    characterCount++;
    inputName = "[unknown]";
    inputClass = "[unknown]";
    inputWeapon = "[unknown]";
    
}

// View character currently in creation
void viewCharacter() {
    cout << "\n**** Your Character ****\n" << endl;
    cout << "Name: " + inputName << endl;
    cout << "Class: " + inputClass << endl;
    cout << "Weapon: " + inputWeapon << endl;
}

//Display characters
void displayAllCharacters(Character characters[], int characterCount)
{
    cout << endl;
    cout << "Total space occupied by characters: " << sizeof(Character) * characterCount << " bytes" << endl;
    cout << endl;
    for (int i = 0; i < characterCount; i++)
    {
       characters[i].displayCharacter();
       cout << endl;
    }
}

//Binary search used to delete character by id number (effective because this program is designed to keep 
//characters in order by id number, but will need to watch this because I might need to add a sort method in the future if the program grows in complexity)
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

// Delete character
void deleteCharacter(Character characters[], int &characterCount)
{
    int deleteID;
    
    while (true)
    {
         cout << "Enter the ID number of the character you want to delete: ";
         if (cin >> deleteID && deleteID > 0)
         {
            break;
         }
         cout << "Invalid Input. Please enter a new choice.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         
    }

    
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

// Save characters to .txt file
void saveCharacters(Character characters[], int characterCount)
{
    ofstream outFile("characters.txt");
    
    if(!outFile)
    {
         cout << "Error opening file!" << endl;
         return;
    }
    
    for(int i = 0; i < characterCount; i++)
    {
         outFile << characters[i].getCharacterID() << "," << characters[i].getName() << "," << characters[i].getClass() << 
         "," << characters[i].getWeapon() << "," << characters[i].getLevel() << "," << characters[i].getHealth() << "," << characters[i].getGold() << "," << 
         characters[i].getAiBackstory() << endl;
    }
    
    outFile.close();
    
    cout << "Characters saved successfully!" << endl;
}

// Load characters from .txt file
void loadCharacters(Character characters[], int &characterCount)
{
    ifstream inFile("characters.txt");
    string line;
    int loadCount = 0;
    
    if (!inFile)
    {
        cout << "Error opening File!" << endl;
        return;
    }
    
    while(loadCount < 5 && getline(inFile, line))
    {
        stringstream ss(line);
        string idTxt, name, characterClass, weapon;
        string levelTxt, healthTxt, goldTxt;
        string aiBackstory;
        
        getline(ss, idTxt, ',');
        getline(ss, name, ',');
        getline(ss, characterClass, ',');
        getline(ss, weapon, ',');
        getline(ss, levelTxt, ',');
        getline(ss, healthTxt, ',');
        getline(ss, goldTxt, ',');
        getline(ss, aiBackstory, ',');
        
        
        int id = stoi(idTxt);
        int level = stoi(levelTxt);
        int health = stoi(healthTxt);
        double gold = stoi(goldTxt);
        
        characters[loadCount] = Character(id, name, characterClass, weapon, level, health, gold, aiBackstory);
        
        loadCount++;
        
    }
    
    characterCount = loadCount;
    inFile.close();
    
    cout << "You loaded " << characterCount << " characters successfully!" << endl;
    
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
    
    // Select user type
    int userType;
    
    cout << "Select a user type:" << endl;
    cout << "1. Regular User" << endl;
    cout << "2. Administrator" << endl;
    
    while (true)
    {
         cout << "Choose an option: ";
         if (cin >> userType && userType > 0 && userType < 3)
         {
            break;
         }
         cout << "Invalid Input. Please try again.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         
    }
    
    if(userType ==2)
    {
       currentUser = &adminUser;
    }
    else
    {
       currentUser = &regularUser;
    }
    
    // Load previous save
    int loadChoice; 
    
    cout << "\nWould you like to load characters from your last visit?" << endl;
    cout << "Warning: Selecting 'No' will cause future saves to overwrite past characters." << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    
    while (true)
    {
         cout << "Choose an option: ";
         if (cin >> loadChoice && loadChoice > 0 && loadChoice < 3)
         {
            break;
         }
         cout << "Invalid Input. Please enter a new choice.\n";
         cin.clear();
         cin.ignore(10000, '\n');
         
    }
    
    if(loadChoice ==1)
    {
        loadCharacters(characters,characterCount);
    }

    
    // Main menu for user
    while (choice != 9) {
        cout << "\n=== MY CHARACTER CREATION ===" << endl;
        cout << "1. Name" << endl;
        cout << "2. Class" << endl;
        cout << "3. Weapon" << endl;
        cout << "4. View Character" << endl;
        cout << "5. Finalize Character" << endl;
        cout << "6. Display All Characters" << endl; 
        cout << "7. Delete Character" << endl;
        cout << "8. Save Characters to File" << endl;
        cout << "9. Exit" << endl;
        
        while (true)
        {
            cout << "Choose an option: ";
            if (cin >> choice && choice > 0 && choice < 10)
            {
               break;
            }
            cout << "Invalid Input. Please enter a new choice.\n";
            cin.clear();
            cin.ignore(10000, '\n');
         
        }


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
                if(currentUser->canView())
                {
                  saveCharacters(characters,characterCount);
                }
                else
                {
                  cout << "Access Denied!" << endl;
                }
                break;
            case 9:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    

    return 0;
}


//------------------------------------------------------------------------

