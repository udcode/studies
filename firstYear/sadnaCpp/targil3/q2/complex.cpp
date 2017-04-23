/*
File: complex.cpp
Description: This is the file for maintain the complex numbers
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include "complex.h"
#include "rational.h"
#include <cmath>

Complex& complexCtor(float real, float im) {
    Complex * z =new Complex;//create dynamic stract
    z->real=real;
    z->imaginary=im;
    return *z;//return the value of it
}
Complex &complexCtor(Rational & r){
    return complexCtor(r.numerator/r.denominator);//send to cTor
}
//return the abs value of Complex number. abs(z)=sqrt(a^2+b^2)
float abs(const Complex & z){
    //|z|=sqrt(a^2+b^2)
    return (sqrt(pow(z.real,2)+pow(z.imaginary,2)));
}
Complex operator+(const Complex &z1, const Complex &z2){
    //add complex number like: z+z=(a+c)+(b+d)i
    Complex tmp;
    tmp.imaginary=z1.imaginary+z2.imaginary;
    tmp.real=z1.real+z2.real;
    return tmp;
}
Complex operator-(const Complex &z1, const Complex &z2){
    //sub complex number like: z-z=(a-c)+(b-d)i
    Complex tmp;
    tmp.imaginary=z1.imaginary-z2.imaginary;
    tmp.real=z1.real-z2.real;
    return tmp;
}
Complex operator*(const Complex &z1, const Complex &z2){
    //multyply complex number like: z-z=(ac-bd)+(ad+bc)i
    Complex tmp;
    tmp.imaginary=z1.real*z2.imaginary+z1.imaginary*z2.real;//(adi+bci)
    tmp.real=z1.real*z2.real-z1.imaginary*z2.imaginary;//(ac-bd)
    return tmp;
}
ostream &operator<<(ostream&output, const Complex &z){//Print as Complex object as a+bi with overloaded version
        output << z.real << (z.imaginary > 0 ? "+":"") << z.imaginary << "i";
    return output;//it allows usage as cout<<a<<b<<c
}
istream &operator>>(istream&input, Complex &z){//Get input from the user.
    //get the input like that: 2 3 (real) (im)
    input >> z.real;
    input >> z.imaginary;
    return input;
}
bool operator==(const Complex& z1, const Complex& z2){
    if(abs(z1)==abs(z2))//compare the abs value
        return true;
    return false;
}

bool operator!=(const Complex& z1, const Complex& z2){
    if(z1==z2)//using the == operator
        return false;
    return true;
}

bool operator<(const Complex& z1, const Complex& z2){
    if(z1.real<z2.real)//compare just the real part(the exercise requirement!)
        return true;
    return false;
}

bool operator<=(const Complex& z1, const Complex& z2){
    if(z1<z2||z1==z2)//using the < and the == operator
        return true;
    return false;
}

bool operator>(const Complex & z1, const Complex &z2){
    if(z1!=z2&&!(z1<z2))//using the < and the != operator
        return true;
    return false;
}

bool operator>=(const Complex & z1, const Complex &z2) {
    if(z1>z2||z1==z2)//using the > and the == operator
        return true;
    return false;
}

void addComplex(void * p, const void * z1, const void * z2) {
    //add the z1 with z2 into p.
    //convert them to Complex pointr and get their value
    *static_cast<Complex *>(p) =*static_cast<const Complex *>(z1)+*static_cast<const Complex *>(z2);
}

void subComplex(void * p, const void * z1, const void * z2){
    //sub the z1 with z2 into p.
    //convert them to Complex pointr and get their value
    *static_cast<Complex *>(p) =*static_cast<const Complex *>(z1)-*static_cast<const Complex *>(z2);
}

void multComplex(void * p, const void * z1, const void * z2){
    //sub the z1 with z2 into p.
    //convert them to Complex pointr and get their value
    *static_cast<Complex *>(p) =*static_cast<const Complex *>(z1)*(*static_cast<const Complex *>(z2));
}

int compareComplex(const void * z1, const void * z2){
    Complex **t1 =(Complex**)z1;//convert to pointer to pointer
    Complex **t2 =(Complex**)z2;
    if(**t1==**t2)//if they equel ret 0
        return 0;
    else if(**t1<**t2)//if not equel tell who is the bigger
        return -1;
    else
        return 1;
}
