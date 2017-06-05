/*
    File: ma.h
    Description: This is the header file for MA class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __MA_H
#define __MA_H
#include "ba.h"
class MA :public BA {//MA class driven from BA
    bool doingResearch;
public:
    MA(bool research, int id, string firstName, string lastName, int numCourses, int *arrGrades, int numGrades);
    bool stipend();//check if the student is stipend
    void printMore();//NVI print
};
#endif // __MA_H
