/*
    File: student.cpp
    Description: This is the header file for Student class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "student.h"

Student::Student(int id, string firstName, string lastName, int numCourses)
    :id(id),firstName(firstName),lastName(lastName),numCourses(numCourses){}//initialize the data

void Student::setId(int id){
    this->id=id;//set id
}
void Student::setFirstName(string name){
    this->firstName=name;//set name
}

void Student::setLastName(string name){
    this->lastName=name;//set name
}

void Student::setNumCourses(int num){
    this->numCourses=num;//set number of courses
}

int Student::getNumCourses(){
    return numCourses;//get the number of courses
}

void Student::print(){
    //print the data
    cout<< "ID: " << id <<endl;
    cout<< "First name: " << firstName <<endl;
    cout<< "Last Name: " << lastName <<endl;
    cout<< "Number of courses: " << numCourses <<endl;
    printMore();//call for more printing base on the driven classes
	cout << "=========================================="<<endl;
}

Student::~Student(){}
