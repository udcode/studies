/*
File: complex.h
Description: This is the file for maintain the complex numbers
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#ifndef __COMPLEX_H_
#define __COMPLEX_H_
#include <iostream>
#include "rational.h"
using namespace std;

//struct for complex number
// - real for the real part
// - imaginary for the "imaginary" part
struct Complex{
    float real;
    float imaginary;
};
//create a Complex struct by given real and im (default is 0)
//return the struct by ref
//@note you must delete the struct after using him!
Complex &complexCtor(float real, float im =0);

//create a Complex struct by Rational struct
//return the struct by ref
//@note you must delete the struct after using him!
Complex &complexCtor(Rational&);

//======operators=======
//calculate oprerators, add, sub, multiply.
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
//logic operaturs, equel, not equel, bigger, smaller.
bool operator==(const Complex&, const Complex&);
bool operator!=(const Complex&, const Complex&);
bool operator<(const Complex&, const Complex&);
bool operator<=(const Complex&, const Complex&);
bool operator>(const Complex&, const Complex&);
bool operator>=(const Complex&, const Complex&);
//io stream operators
ostream &operator<<(ostream&, const Complex&);
istream &operator>>(istream&, Complex&);

//add tow elements into another get them as [const] void pointer.
void addComplex(void *,const void *,const void *);
//sub tow elements into another get them as [const] void pointer.
void subComplex(void *,const void *,const void *);
//multiply tow elements into another get them as [const] void pointer.
void multComplex(void *,const void *,const void *);
//compare tow elements get them as void pointer.
//return 0 if they are equel. if the first is bigger 1, if the seconde is bigger -1
int compareComplex(const void *,const void *);

#endif // __COMPLEX_H_
