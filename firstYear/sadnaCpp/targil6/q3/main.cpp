/*
    File: main.cpp
    Description: This is the  file for using student base class for inhereition to BA MA PHD
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include <iostream>
#include "phd.h"
#include "ma.h"
using namespace std;

int main(){
    //create the student array like the targil says
    Student * student[7];
    //grades
	int grades1[3] = { 90,100,90 };
	int grades2[10] = { 100,100,90,100,90,100,90,100,90,100};
	int grades3[7] = { 90,100,90,100,90,100,90 };
	int grades4[7] = { 90,100,90,100,90,100,90 };
    //students
	student[0] = new BA(123, "Abe", "Avraham", 3, grades1, 3);
	student[1] = new BA(234, "Yitzhak", "Avrahamson", 10, grades2, 10);
    student[2]=new MA(false,345,"Yaacov","Jacobson",7,grades3,7);
    student[3] = new MA(true, 456, "Sara", "Emanu", 7, grades4, 7);
	student[4] = new PHD(30, 567, "Rivka", "Imanu", 1);
	student[5] = new PHD(20, 678, "Rachel", "Jacobs", 2);
	student[6] = new PHD(30, 789, "Leah", "Jacobs", 2);
    //print and delete the student
	for (int i = 0; i < 7; i++) {
        if(student[i]->stipend())//the student is stipend
		student[i]->print();
		delete student[i];
	}    
    return 0;
}
