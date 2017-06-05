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
