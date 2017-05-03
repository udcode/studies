#include "clock.h"
#include<math.h>
Clock::Clock(int hour , int minute , int seconds) {
	try{//using a helper function to check if the time format is o.k
		checktime(hour, minute, seconds);
		this->hour = hour; this->minute = minute; this->seconds = seconds;//if every thing is o.k set the time
	}
	catch(const char * error) {//if there is an exception tell it to the user
		cout << error;
		this->hour = 0; this->minute = 0; this->seconds = 0;//and set the time to 00:00:00
	}
	
}
//copy constructor
Clock::Clock(const Clock & cCpy) {//copy constructor(not used)
	hour = cCpy.hour;
	minute = cCpy.minute;
	seconds = cCpy.seconds;
}
void Clock::setHour(int hour)//setter for the hour
{
	this->hour = hour;
}

void Clock::setMinute(int minute)//setter for the minutes
{
	this->minute = minute;
}
void Clock::setSeconds(int seconds)//setter for the seconds
{
	this->seconds = seconds;
}

int Clock::getHour()//getter for the hour
{
	return this->hour;
}

int Clock::getMinute()//getter fot the minutes
{
	return this->minute;
}

int Clock::getSeconds()//getter for the seconds
{
	return this->seconds;
}

Clock & Clock::operator+=(int insertdseconds)
{
	int tempH = insertdseconds / 3600;//saving the value of the hour for futre use
	this->hour += tempH;
	this->minute += (insertdseconds - (tempH * 3600)) / 60;//using the saved hour value to calculate the minutes
	this->seconds += insertdseconds % 60;//adding the remaining seconds to the obj
	if (this->seconds > 60) {//if there is more then one minute(if the seconds was allready high
		this->seconds %= 60;//set the correct seconds
		this->minute++;//add 1 minute
	}
	if (this->minute > 59)//if there is more then one hour 
	{
		this->hour++;//add 1 hour
		if (this->hour > 23)this->hour = 0;//if the hour is to high set the hour to zero
		this->minute = 0;//and then set the minute to zero
	}
	return *this;
}

Clock & Clock::operator++()//prefix
{		
		return *this +=1;//using the += operator to add the time to the clock
}
Clock  Clock::operator++(int ) {//post fix
	Clock temp = *this;
	*this += 1;//using the += operator to add the time to the clock
	return temp;//returning a temp obj
}

ostream & operator<<(ostream & out, const Clock & clock)//output operator overloading
{
	if (clock.hour < 10) { out << "0" << clock.hour << ":"; }//if the hour is not in correct format,add a zero befor
	else { out << clock.hour << ":"; }//adding the  col
	if(clock.minute<10){ out << "0" << clock.minute<< ":"; }//if the minutes is not in correct format,add a zero befor
	else { out << clock.minute << ":"; }//adding the  col
	if(clock.seconds<10) { out << "0" << clock.seconds; }//if the seconds is not in correct format,add a zero befor
	else { out << clock.seconds; }
	out << endl;
	return out;
	
}
 void Clock::checktime(int hour, int min, int seconds){//helper function to check time format
	if (hour > 23)throw"Invalid time - more than 23 hours.\n";//self explanatory
	if (hour< 0)throw "Invalid time - negative number of hours.\n";//self explanatory
	if (min > 59)throw"Invalid time - more than 59 minutes.\n";//self explanatory
	if (min< 0)throw "Invalid time - negative number of minutes.\n";//self explanatory
	if (seconds > 59)throw"Invalid time - more than 59 seconds.\n";//self explanatory
	if (seconds < 0)throw "Invalid time - negative number of seconds.\n";//self explanatory
}
istream & operator >> (istream & in, Clock & clock)//input operator overloading
{
	int h, m, s;
	char a;
	in >> h;
	in >> a;
	if (a != ':') throw "Wrong time format";//if the user didn't add the col
	in >>m;
	in >> a;
	if (a != ':') throw "Wrong time format";//if the user didn't add the col
	in >> s;
	try {
		clock.checktime(h, m, s);//using the helper function to check the time format
		clock.hour = h; clock.minute = m; clock.seconds = s;
	}
	catch (const char * error) //if the helper function throwed an exception(not handeled in the main for ease of use
	{
		cout << error;
		clock.hour = 0; clock.minute = 0; clock.seconds = 0;//setting the clock to zero
	}
	return in;
}
