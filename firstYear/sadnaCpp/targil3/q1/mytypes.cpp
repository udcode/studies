/*
   File: mytypes
   Description: This is the header file for our personal types
   Course: 150018 C++ Workshop, Exercise 3, Question 1
   Teacher: Dan Zilberstein
   Student1: Avi margali 305645137
   Student2: Yeuda Nuiman 301759692
*/
#include "mytypes.h"
string convert;//using global vaiable we are saving few memory allocations
char * converNumToString(int num) {
    stringstream t;
    t << num;
    t >> convert;
    const char * a = convert.c_str();
    return const_cast<char *>(a);
}
