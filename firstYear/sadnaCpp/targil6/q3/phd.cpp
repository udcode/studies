/*
    File: phd.cpp
    Description: This is the  file for PHD class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "phd.h"

PHD::PHD(int hoursOfResearch, int id, string firstName, string lastName, int numCourses)
    :Student(id,firstName,lastName,numCourses),hoursOfResearch ( hoursOfResearch){}//set the data

bool PHD::stipend(){
    if (getNumCourses() >= 2 && getHoursOfResearch()>25)//the student is stipend
		return true;
	return false;
}

void PHD::printMore(){
    cout <<"Research houres: "<< getHoursOfResearch() << endl;//print
}

int PHD::getHoursOfResearch()const{
    return hoursOfResearch;//get the number of houer search
}

