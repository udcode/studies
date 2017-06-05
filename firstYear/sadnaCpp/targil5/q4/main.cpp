/*
    File: main.cpp
    Description: This is the  file for tring the list class
    Course: 150018 C++ Workshop, Exercise 5, Question 2, part 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
//===== this file was given by the teacher!! ===//
#include <iostream>
#include "list.h"
using namespace std;

int main() {
   List lst1, lst2, mergedList;
   //fil the lists
   cout <<"enter sorted values for the first list:" << endl;
   cin >> lst1;
   cout << "enter sorted values for the second list:"<< endl;
   cin >> lst2;
   //merge the lists
   mergedList = merge(lst1, lst2);
   cout << "the new merged list: " << mergedList <<endl;
    //remove duplicats
   makeSet(mergedList);
   cout<< "the new merged set: " << mergedList << endl;

   return 0;
}
