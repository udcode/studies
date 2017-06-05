/*
    File: Rectangle.h
    Description: This is the header file for Rectangle class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/

#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include "Polygon.h"
class Rectangle :public Polygan {//inhereting without changing the acceseblty of the parent
public:
	Rectangle(uint smallSide, uint bigSide);//constructor
};
#endif // __RECTANGLE_H

