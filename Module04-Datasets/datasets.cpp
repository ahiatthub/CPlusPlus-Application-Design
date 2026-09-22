#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Function prototype
void printArrays(string*, string*, double*, int);


int main() {

   ifstream inputFile;
   inputFile.open("artists_subset.csv");
  
   int SIZE = 10;
   
   //create arrays
   string artists[SIZE];
   string tags[SIZE];
   double listeners[SIZE];
   
   //pointers
   string* artistPtr = artists;
   string* tagPtr = tags;
   double* listenerPtr = listeners;
   
   //clear first line from .csv file to skip the column headings
   string line;
   getline(inputFile, line);
   
   //for loop to put info from .csv file into arrays
   for (int i = 0; i < SIZE; i++)
   {
      getline(inputFile, artists[i], ',');
      getline(inputFile, tags[i], ',');
      inputFile >> listeners[i];
      
      inputFile.ignore();
   }
   
   printArrays(artistPtr, tagPtr, listenerPtr, SIZE);
   
   cout << "First artist through pointer: " << *artistPtr << endl;
   cout << "First artist tags through pointer: " << *tagPtr << endl;
   cout << "First artist listeners through pointer: " << *listenerPtr << endl;
   cout << "First artist memory address: " << artistPtr << endl;
   cout << endl;
   
   cout << "Second artist through pointer: " << *(artistPtr + 1) << endl;
   cout << "Second artist tags through pointer: " << *(tagPtr + 1) << endl;
   cout << "Second artist listeners through pointer: " << *(listenerPtr + 1) << endl;
   cout << "Second artist memory address: " << artistPtr + 1 << endl;
   cout << endl;
   
   return 0;
 
   }
}

//print arrays using pointers as input
void printArrays(string* artistPtr, string* tagPtr, double* listenerPtr, int size)
{
   //i dislike the scientific notation haha
   cout << fixed << setprecision(0);
   
   //for loop to display each element of the array
   for(int i = 0; i < size; i++)
   {
       cout << *(artistPtr + i) << endl;
       cout << *(tagPtr + i)<< endl;
       cout << *(listenerPtr + i) << endl;
       cout << endl;
   }
}
