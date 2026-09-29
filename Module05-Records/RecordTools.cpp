#include <iostream>
#include "RecordTools.h"
using namespace std;

void showMessage() {
    cout << "Record system ready!" << endl;
}

void addRecord(string records[], int &recordCount)
{
   string record;
   cout << "Please enter a record you would like to add: ";
   cin >> record;
   cout << "You chose " + record;
   records[recordCount] = record;
   recordCount++;
   
}

void displayRecords(string records[], int recordCount)
{
   cout << "\n========Record List========" << endl;
   for(int i = 0; i < recordCount; i++)
   {
      cout << i+1 << ". " + records[i] << endl;
   }
   
}

int calculateCharacters(string records[], int recordCount)
{
   int charCount = 0;
  
   
   for(int i = 0; i < recordCount; i++)
   {
      charCount += records[i].length();
   }

   
   return charCount;
}
