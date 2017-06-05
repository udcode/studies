/*
    File: main.cpp
    Description: This is the  file for tring the list class
    Course: 150018 C++ Workshop, Exercise 5, Question 2, part 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
//===== this file was given by the teacher!! ===//
#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List lst;
    int choice, val;
    cout << "enter the list values\n";//get the values
    cin >> lst;
    cout << "choose 0-2\n";//get the operation
    cin >> choice;
    while (choice) {
        switch (choice) {
        case 1://insert value
            cout << "enter a value to insert\n";
            cin >> val;
            lst.insert(val);
            break;
        case 2://delete value
            cout << "enter a value to remove\n";
            cin >> val;
            try {
                lst.remove(val);
            }catch(const char* msg) {//not found
                cout << msg << endl;
            }
            break;
        default:
            cout << "ERROR\n";
        }
        cout << lst << endl;
        cout << "choose 0-2\n";
        cin >> choice;
    }
    return 0;
}
