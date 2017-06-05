/*
    File: Polygon.cpp
    Description: This is the  file for Polygon class
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "Polygon.h"

Polygan::Polygan(uint sides)
{
	if (sides != 3 && sides != 4) //if the polygan is nor triangle or rectangle
	{
		cout << "enter number of sides for polygon"<<endl;//asking the user to input the sizes of the sides
		this->sides = new uint[sides];//creating the side-sized array
		for(uint i = 0;i<sides;++i)//filling the array of sides with values
		{
			cin >> this->sides[i];
		}
		this->numSides = sides;
	}
	else//if the polygan is indeed a triangle or a rectangle
	{
		this->sides = new uint[sides];//creating the side-sized array
		this->numSides = sides;//assigning the the fields
	}
	
}

Polygan::Polygan(const Polygan & rhs)//deep copy
{
	for (uint i = 0; i < rhs.getNumSides(); ++i)//copying the the values one by one (insted of just setting the pointer)
	{
		sides[i] = rhs.sides[i];
	}
}

Polygan::Polygan(const Polygan && rhs)//moover
{
	for (uint i = 0; i < rhs.getNumSides(); ++i)//copying the the values one by one (insted of just setting the pointer)
	{
		sides[i] = rhs.sides[i];
	}
	delete &rhs;//deleting the redandent
}

Polygan::~Polygan()
{
		delete[] sides;//avi is this right?
}

uint* Polygan::getSides()
{
	return this->sides;//returning the sides pointer(array)
}

uint Polygan::getNumSides()const
{
	return this->numSides;//returning the number of sides of the polygan
}

uint Polygan::sumScale(const Polygan & pol)//summing the size of the polygan
{
	uint sum = 0;
	for (int i = 0; i < pol.getNumSides(); ++i)
		sum += const_cast<Polygan&>(pol).getSides()[i];
	return sum;
}

bool Polygan::operator==(const Polygan & Rhs)//boolean operator over loading
{
	if (numSides == Rhs.getNumSides()) {//if the number of sides of both of the polygans are equal
		if (sumScale(*this) == sumScale(const_cast<Polygan&>(Rhs))) return true;//if the size of both of the polygans are equal return true
	}
	return false;//if the polygans are not equal
}
