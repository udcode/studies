#ifndef __STUDENT_H
#define __STUDENT_H
#include<iostream>
using namespace std;
struct Student{
    int id;
    char firstName[20];
    char lastName[20];
    char courses[5];
    Student(int id,char *firstName ,char * lastName);
	bool  operator>(const Student& rhs);
	static Student emptyStudent;
};

istream &operator>>(istream&input, Student &s);
#endif //__STUDENT_H
