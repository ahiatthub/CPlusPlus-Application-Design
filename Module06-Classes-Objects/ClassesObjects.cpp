#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    string name;
    string charClass;
    string weapon;
    int level;
    int health;
    double gold;

public:
    // Constructor
    Character(string characterName, string characterClass, string characterWeapon, int characterLevel, int characterHealth, double characterGold) {
        name = characterName;
        charClass = characterClass;
        weapon = characterWeapon;
        level = characterLevel;
        health = characterHealth;
        gold = characterGold;
    }

    // Member function
    void displayCharacter() {
        cout << "Name: " << name << endl;
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

    // Getter
    string getName() {
        return name;
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

int main() {
    Character character1("Thomas", "Cleric", "LongSword", 12, 98, 24.5);
    Character character2("Harrison", "Warrior", "BattleAxe", 20, 74, 32.8);

    character1.displayCharacter();
    cout << endl;
    character2.displayCharacter();
    cout << endl;
    character1.duelCharacters(character2);

    return 0;
}