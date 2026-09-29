#include <iostream>
#include "RecordTools.h"
using namespace std;

string records[10];
int recordCount = 0;

int main()
{
   int choice = 0;
   
   showMessage();
   while (choice != 4) 
   {
        cout << "\n=== RECORD SYSTEM ===" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Character Count in Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord(records, recordCount);
                break;
            case 2:
                displayRecords(records, recordCount);
                break;
            case 3:
                cout << "The number of characters in all records is: " << calculateCharacters(records, recordCount) << endl;
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
     }

}