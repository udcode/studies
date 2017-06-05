/*
    File: ma.cpp
    Description: This is the file for MA class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "ma.h"

MA::MA(bool research, int id, string firstName, string lastName, int numCourses, int *arrGrades, int numGrade)
    :BA(id, firstName, lastName, numCourses, arrGrades, numGrade),doingResearch(research){}//set the data

bool MA::stipend(){
    if (getNumCourses() >= 7 && getAvgGrades()>90&&doingResearch==true)//the student is stipend
		return true;
	return false;
}

void MA::printMore(){
    BA::printMore();//print the BA data
    //print the reaserch status
    if (doingResearch == true)
        cout << "Research: yes"<<endl;
    else
        cout << "Research: no"<<endl;
}



