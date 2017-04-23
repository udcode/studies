/*
File: rational.cpp
Description: This is the  file to manage the Rational module
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include "rational.h"

//get the max common divider
uint gcd(uint a, uint b){
	//according to Euclid algorithm
	if (0 == b)
		return a;
	return gcd(b, a%b);
}
//set the fraction to be the minimum
void reductFraction(Rational & q){
	if (0 == q.numerator) {//if the numerator is 0 set the q to 0/1 
		q.numerator = 0;
		q.denominator = 1;
		return;
	}
        int g =gcd(abs(q.numerator), q.denominator);//converting the uint to int and divides the numerator with the largest divisor possible
        q.numerator /=g;
        q.denominator /=g;
}
Rational operator + (const Rational & q1, const Rational & q2){
	//add Rational number by finding a commen ground and using it
	Rational temp;
	temp.denominator = q1.denominator*q2.denominator;
	temp.numerator = ((temp.denominator / q1.denominator)*q1.numerator) + ((temp.denominator / q2.denominator)*q2.numerator);
	//reductiong the fraction using the reductFraction function
	reductFraction(temp);
	return temp;
}
Rational operator - (const Rational & q1, const Rational & q2){
	//sub Rational number by finding a commen ground and using it
	Rational temp;
	temp.denominator = q1.denominator*q2.denominator;
	temp.numerator = ((temp.denominator / q1.denominator)*q1.numerator) - ((temp.denominator / q2.denominator)*q2.numerator);
	//reductiong the fraction using the reductFraction function
	reductFraction(temp);
	return temp;
}
Rational operator * (const Rational &q1, const Rational &q2){
	//multiplyng rational numbers by multiplying each of the fraction by the other
	Rational temp;
	temp.denominator = q1.denominator * q2.denominator;
    temp.numerator = q1.numerator * q2.numerator;
	//reductiong the fraction using the reductFraction function
	reductFraction(temp);
	return temp;
}
bool operator == (const Rational &q1, const Rational &q2) {
Rational q3 = (q1 - q2);
	if (q3.numerator == 0)//comparing the quotient of the numbers
		return true;
	return false;
}
bool operator != (const Rational &q1, const Rational &q2) {
	if (q1 == q2)//using the == operator
		return false;
	return true;
}
bool operator  > (const Rational &q1, const Rational &q2) {
	Rational q3 = (q1 - q2);
	if (q3.numerator>0 )//comparing the quotient of the numbers
		return true;
	return false;
}
bool operator  < (const Rational &q1, const Rational &q2) {	
	if (q1!=q2&&q2>q1)//comparing the quotient of the numbers
		return true;
	return false;
}
bool operator  >= (const Rational &q1, const Rational &q2) {
	if (q1>q2 || q1 == q2)//using the > and the == operator
		return true;
	return false;
}
bool operator <= (const Rational &q1, const Rational &q2) {
	if (q1<q2 || q1 == q2)//using the < and the == operator
		return true;
	return false;
}
ostream &operator << (ostream& os,const Rational & q) {
	os << q.numerator << "/" << q.denominator;
	return os;
}
istream &operator >> (istream& input,  Rational & q) {//Get input from the user.
	//get the input like that: 2 3 (nume) (denum)
    int d;
	input >> q.numerator;
    input >>d;
    if (d == 0) {//if the user enterd an invalid
        cout << "you enterd an invalid number so we changed it to 1"<<endl;
        q.denominator = 1;
    }else if(d<0){
        q.numerator=q.numerator*(-1);//save the sign in the numerator
        q.denominator=d*(-1);
    }else{
        q.denominator=d;
    }
	reductFraction(q);
	return input;
}
Rational &rationalCtor(const int q1,const uint q2) {
	if (0 == q2) exit(1);//just in case
    Rational* temp = new Rational;//create dinamic object
	temp->numerator = q1;
	temp->denominator = q2;
	reductFraction(*temp);
	return *temp;
}
void addRational(void * p, const void * q1, const void * q2) {
	//add the q1 with q2 into p.
	//convert them to Rational pointr and get their value
	*static_cast<Rational *>(p) = *static_cast<const Rational *>(q1) + *static_cast<const Rational*>(q2);
	reductFraction(*static_cast<Rational *>(p));
}
void subRational(void * p, const void * q1, const void * q2) {
	//sub the q1 with q2 into p.
	//convert them to Rational pointr and get their value
	*static_cast<Rational *>(p) = *static_cast<const Rational *>(q1) - *static_cast<const Rational*>(q2);
	reductFraction(*static_cast<Rational *>(p));
}
void multRational(void * p, const void * q1, const void * q2) {
	//multiply the q1 with q2 into p.
	//convert them to Rational pointr and get their value
	*static_cast<Rational *>(p) = *static_cast<const Rational *>(q1) * *static_cast<const Rational*>(q2);
	reductFraction(*static_cast<Rational *>(p));
}
int compareRational(const void * q1, const void * q2) {
	Rational **t1 = (Rational**)q1;//convert to pointer to pointer
	Rational **t2 = (Rational **)q2;
	if (**t1 == **t2)//if they equel ret 0
		return 0;
	else if (**t1<**t2)//if not equel tell who is the bigger
		return -1;
	else
		return 1;
}
