#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "string.h"
using namespace std;

enum Action {
   STOP,
   INSERT_TWO_STRINGS,
   COMPARE,
   INSERT_AT_NTH_LOCATION,
   SEARCH_FOR_B_IN_A

};

Action menu() {
   cout << "enter 1 to insert two strings" << endl;
   cout << "enter 2 to compare the two strings" << endl;
   cout << "enter 3 to insert at Nth location" << endl;
   cout << "enter 4 to search for b in a" << endl;
   cout << "enter 0 to stop" << endl;
   int x;
   cin >> x;
   return (Action)x;
}

int main() {
   String aString,bString;
   char * pStr=nullptr;
   char str[80];
   int index;
   unsigned int length=0;
   Action ac = menu();
   while (ac) {
	   switch (ac) {
	   case INSERT_TWO_STRINGS: {
		   cout << "insert first word" << endl;
		   cin >> str;
		   length = strlen(str) + 1;
		   pStr = new char[length];
		   strncpy(pStr, str, length);            // copy the content
		   String tmpA(pStr);
		   aString = tmpA;
		   delete[]pStr;
		   pStr = nullptr;
		   cout << "insert second word" << endl;
		   cin >> str;
		   length = strlen(str) + 1;
		   pStr = new char[length];
		   strncpy(pStr, str, length);            // copy the content
		   String tmpB(pStr);
		   bString = tmpB;
		   delete[]pStr;
		   pStr = nullptr;
		   break;
	   }
	   case COMPARE:
           if (aString.length() == 0||bString.length()==0) {
               cout << "Error: 1 or none of the strings were created" << endl;
           }
           else if (aString == bString)
			   cout << "a=b" << endl;
		   else if (aString < bString)
			   cout << "a<b" << endl;
		   else if (aString > bString)
			   cout << "a>b" << endl;
		   break;
	   case  INSERT_AT_NTH_LOCATION: {
		   if (length == 0) {
			   cout << "error: no string was created!" << endl;
		   }
		   else {
			   cout << "insert index" << endl;
			   cin >> index;
			   try {
				   char* tempChar = bString.getString();
				   String tempC = aString.insert(index, tempChar);
				   delete[] tempChar;
				   tempChar = nullptr;
				   tempChar = tempC.getString();
				   cout << tempChar << " " << endl;
				   delete[] tempChar;
				   tempChar = nullptr;
				   tempChar = aString.getString();
				   tempC = bString.insert(index, tempChar);
				   delete[] tempChar;
				   tempChar = nullptr;
				   tempC.print();
				   delete &tempC;
			   }
			   catch (IndexException b) {
				   cout << "error inserting at index: " << b.index << " " << "original string size: " << b.maxIndex << endl;
			   }
		   }
	   }
									 break;
	   case SEARCH_FOR_B_IN_A: {
		   if (length == 0) {
			   cout << "Error: 1 or none of the strings were created" << endl;
		   }
		   else {
			   try {
				   cout << aString[bString.getString()] << endl;
			   }
			   catch (const char * notfound) {
				   cout << notfound << ": " << "was not found " << endl;
				   delete[]notfound;
			   }
		   }
	   }
	   }


      ac = menu();
   }

   return 0;
}
