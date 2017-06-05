/*
    File: main.cpp
    Description: This is the main file for string class
    Course: 150018 C++ Workshop, Exercise 4, Question 1
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#define _CRT_SECURE_NO_WARNINGS //@note this is for vs2015 to avoid errors on cstring functions
#include <iostream>
#include <cstring>

#include "String.h"
using namespace std;
//enum for the menu
enum Action {
	STOP,//0
	INSERT_TWO_STRINGS,//1
	COMPARE,//2
	INSERT_AT_NTH_LOCATION,//3
	SEARCH_FOR_B_IN_A//4

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
	String aString, bString;//setting the String objs
	char * pStr = nullptr;//setting a cstring
	char str[80];//setting a char array to get input from user
	int index;//index for the thrird option
	unsigned int length = 0;//length of cstrings
	Action ac = menu();
	while (ac) {
		switch (ac) {
		case INSERT_TWO_STRINGS: {
			cout << "insert first word" << endl;//asking the user to input the first word
			cin >> str;//getting the word from the user
			length = strlen(str) + 1;//setting the right size of the cstrting
			pStr = new char[length];//...
			strncpy(pStr, str, length);            // copy the content
			String tmpA(pStr);//constructing the temp string incase there are exception the global obj wont be initialized
			aString = tmpA;//assigning the Astring obj to the temp one
			delete[]pStr;//releasing the memory of the tmp cstring
			pStr = nullptr;//avoiding dangling pointer
			cout << "insert second word" << endl;//asking the user to input the second word
			cin >> str;//getting the word from the user
			length = strlen(str) + 1;//setting the right size of the cstrting
			pStr = new char[length];//...
			strncpy(pStr, str, length);            // copy the content
			String tmpB(pStr);//constructing the temp string incase there are exception the global obj wont be initialized
			bString = tmpB;//assigning the Bstring obj to the temp one
			delete[]pStr;//releasing the memory of the tmp cstring
			pStr = nullptr;//avoiding dangling pointer
			break;
		}
		//this function compare between two Strings and returning which one is bigger
		case COMPARE:
            if (aString.length() == 0 || bString.length() == 0){//the sizes of one or both of the strings is 0(their are empty)
				cout << "Error: 1 or none of the strings were created" << endl;//incase no string was created
            }else if (aString == bString)//using the compareing overloaded operator to determine if they are equal
				cout << "a=b" << endl;//printing the resault
			else if (aString < bString)//using the compareing overloaded operator to determine if b is bigger then a
				cout << "a<b" << endl;//printing the resault
			else if (aString > bString)//using the compareing overloaded operator to determine if a is bigger then b
				cout << "a>b" << endl;//printing the resault
			break;
		case  INSERT_AT_NTH_LOCATION:
		{
            if (aString.length() == 0 || bString.length() == 0){//the sizes of one or both of the strings is 0(their are empty)
				cout << "Error: 1 or none of the strings were created" << endl;//incase no string was created
            }else {
				cout << "insert index" << endl;//asking the user to input of ware he/she wants to insert the b string
				cin >> index;//getting the input from the user
				try {
					char* tempChar = bString.getString();//setting a temp cstring to be able relaeasing the memory agter use
                    String * tempC = &aString.insert(index, tempChar);//setting a temp String obj to print the action to user
					delete[] tempChar;//releasing the memory
					tempChar = nullptr;//avoiding dangling pointer
                    tempC->print();//printing the resault
                    delete tempC;
                    tempChar = aString.getString();////setting the temp cstring to be able relaeasing the memory agter use
                    tempC = &bString.insert(index, tempChar);//setting the temp String obj to print the action to user
					delete[] tempChar;//releasing the memory
					tempChar = nullptr;//avoiding dangling pointer
                    tempC->print();//printing the resault
                    delete tempC;
                }catch (IndexException b){//if the action faild tell the user
					cout << "error inserting at index: " << b.index << " " << "original string size: " << b.maxIndex << endl;
				}
			}
		}
		break;
		case SEARCH_FOR_B_IN_A: {
            if (aString.length() == 0 || bString.length() == 0){//the sizes of one or both of the strings is 0(their are empty)
				cout << "Error: 1 or none of the strings were created" << endl;//incase no string was created
            }else{
				const char* tempb = bString.getString();//setting a temp variable to be able releasing the memory
				try {
					cout << aString[tempb] << endl;//using the index operator overloading to find a match			
				}catch (const char * notfound) {
					cout << notfound << ": " << "was not found " << endl;					
				}
				delete[] tempb;//releasing the memory
				tempb = nullptr;//avoiding dangling pointer
			}
		}
		}
		ac = menu();
	}
	return 0;
}
