/*
    File: clock.h
    Description: This is the header file for clock class
    Course: 150018 C++ Workshop, Exercise 4, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __CLOCK_H
#define __CLOCK_H

#include<iostream>
using namespace std;
//Clock class
class Clock {
private:
	int hour, minute, seconds;	
public:
	//constructors
	Clock(int hour = 00, int minute = 00, int seconds = 00);
	Clock(const Clock& cCpy);
	//geters and setters
	void setHour(int hour);
	void setMinute(int minute);
	void setSeconds(int seconds);
	int getHour();
	int getMinute();
	int getSeconds();

	//function
 void checktime(int hour, int min, int seconds);//helper function

	//operators overloading
	 Clock & operator +=(int seconds);
	 Clock & operator ++();
	 Clock  operator ++(int );
	 friend ostream& operator <<(ostream& out,const Clock & clock);
	 friend istream& operator >>(istream& in, Clock & clock);
};
//global operators
ostream& operator <<(ostream& out, const Clock & clock);
istream& operator >> (istream& in, Clock & clock);
#endif // __CLOCK_H
