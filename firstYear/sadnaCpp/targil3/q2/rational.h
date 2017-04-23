/*
File: rational.h
Description: This is the header file to manage the Rational module
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#ifndef __RATIONAL_H_
#define __RATIONAL_H_
#include "mytypes.h"
#include <iostream>
#include <cmath>
using namespace std;

struct Rational {
	int numerator;
	uint denominator;
};
//create Rational object
//do not forget to delete the memory of this object!
Rational &rationalCtor(const int q1,const uint q2 =1);

//======operators=======
//calculate oprerators, add, sub, multiply.
Rational operator + (const Rational & a, const Rational & b);
Rational operator - (const Rational &a, const Rational & b);
Rational  operator*(const Rational &q1, const Rational &q2);
//logic operaturs, equel, not equel, bigger, smaller.
bool operator == (const Rational &, const Rational &);
bool operator != (const Rational &, const Rational &);
bool operator  > (const Rational &, const Rational &);
bool operator  < (const Rational &, const Rational &);
bool operator >= (const Rational &, const Rational &);
bool operator <= (const Rational &, const Rational &);
//io stream operators
ostream &operator << (ostream& os, const Rational & q);
istream &operator >> (istream& input, Rational & q);

//add tow elements into another get them as [const] void pointer.
void addRational(void *, const void *, const void *);
//sub tow elements into another get them as [const] void pointer.
void subRational(void *, const void *, const void *);
//multiply tow elements into another get them as [const] void pointer.
void multRational(void *, const void *, const void *);
//compare tow elements get them as void pointer.
//return 0 if they are equel. if the first is bigger 1, if the seconde is bigger -1
int compareRational(const void *, const void *);

#endif // __RATIONAL_H_
