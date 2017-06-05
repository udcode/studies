/*
    File: student.h
    Description: This is the header file for Student class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __STUDENT_H
#define __STUDENT_H
#include <iostream>
#include <string>
using namespace std;

//the base abstract class Student
class Student{
    //data
    int id;
    string firstName;
    string lastName;
    int numCourses;
public:
    Student(int id =0,string firstName="",string lastName = "",int numCourses=0) ;//Ctor with the data
    //seters
    void setId(int);//set id
    void setFirstName(string);//set first name
    void setLastName(string);//set last name
    void setNumCourses(int);// set number of courses
    //getters
    int getNumCourses();//get the number of courses
    //Non Virtual Interface for printing the data
    void print();
    void virtual printMore()=0;//pure vitual print
    virtual bool stipend()=0;//pure virtual func to check if student stipend

    virtual ~Student();//Dtor
};

#endif //__STUDENT_H
