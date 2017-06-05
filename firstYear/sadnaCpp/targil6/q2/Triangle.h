/*
    File: Triangle.h
    Description: This is the (header) file for Triangle class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __TRIANGLE_H
#define __TRIANGLE_H
#include "Polygon.h"
class Triangle:public Polygan {//inhereting without changing the acceseblty of the parent
public:
	Triangle(uint f, uint s, uint th);//constructor
	//no need for any over-riding or any getters or seeters)(the parent class has the getters and setters)
};
#endif // __TRIANGLE_H
