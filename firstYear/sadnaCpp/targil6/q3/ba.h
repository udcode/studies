/*
    File: ba.h
    Description: This is the header file for BA class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __BA_H
#define __BA_H

#include "student.h"
class BA : public Student{//BA class driven from Student
protected:
    //data
    int numGrades;
    int * arrGrades;
public:
    BA(int id =0,string firstName="",string lastName = "",int numCourses=0,int * arrGrades=nullptr,int numGrades=0);
    //copy constractor. not using in this program
    BA(const BA& ba);
	BA(BA&& ba);

    void setGrades(int * arr , int size);//set the grades
    double getAvgGrades()const;//get the avg
    bool stipend();//check if the student is stipend
    void printMore();//NVI print
    ~BA();
};

#endif // __BA_H
