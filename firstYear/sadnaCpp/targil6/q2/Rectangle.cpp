/*
    File: Rectangle.cpp
    Description: This is the  file for Rectangle class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "Rectangle.h"

Rectangle::Rectangle(uint smallSide, uint bigSide):Polygan(4)//constructing the parent class with size accordinly
{
	//setting the rectangle parallel sides accordinly
	sides[0] = smallSide;
	sides[1] = bigSide;
	sides[2] = smallSide;
	sides[3] = bigSide;

}
