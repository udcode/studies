/*
    File: Triangle.cpp
    Description: This is the  file for Triangle class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "Triangle.h"

Triangle::Triangle(uint f, uint s, uint th):Polygan(3)//constructing the parent class with size accordinly
{
	//setting the sizes of the triangle
	sides[0] = f;
	sides[1] = s;
	sides[2] = th;
}
