#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <cstring>
Student Student::emptyStudent={0,"",""};
Student::Student(int id, char *firstName, char *lastName):id(id){
    //copy the name
    //TODO: check for size
    strncpy(this->firstName,firstName,20);
    strncpy(this->lastName,lastName,20);
    for(int j=0;j<5;++j)//fill with empty courses
       courses[j]='N';
}

bool Student::operator>(const Student & rhs){
	if (this->id > rhs.id)return true;
	return false;
}
istream &operator>>(istream&input, Student &s){//Get input from the user.
    input>>s.id;
    input>>s.firstName;
    input>>s.lastName;
    return input;
}
