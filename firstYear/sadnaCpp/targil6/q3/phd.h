/*
    File: phd.h
    Description: This is the header file for PHD class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __PHD_H
#define __PHD_H
#include "student.h"
class PHD :public Student { //PHD class driven from Student
    //data
	int numGrades;
	int * arrGrades;
	int hoursOfResearch;
public:
	PHD(int hoursOfResearch, int id = 0, string firstName = "", string lastName = "", int numCourses = 0);
    bool stipend();//check if the student is stipend
    void printMore();//NVI print
    int getHoursOfResearch()const;//get the number of houer search

};
#endif // __PHD_H
