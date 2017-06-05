/*
    File: Polygon.h
    Description: This is the header file for Polygon class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __POLYGON_H
#define __POLYGON_H
#include <iostream>
#include "mytypes.h"
using namespace std;
class Polygan {
protected:
	//protected fieldes for sun classes
	uint  numSides;
	uint* sides;
public:
	//constructors
	Polygan(uint sides);
	Polygan(const Polygan& rhs);//copy constructor
	Polygan(const Polygan&&rhs);//moover
	~Polygan();//distructor
	uint* getSides();//get the array of sides for outer classes
	uint getNumSides()const;//get the number of sides for outer classes
	uint sumScale(const Polygan & pol);//suming the scale of the polygan
	bool operator ==(const Polygan &Rhs);//boolean operator over loading

};
#endif // __POLYGON_H

