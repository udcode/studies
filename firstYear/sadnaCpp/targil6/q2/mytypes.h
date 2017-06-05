/*
   File: mytypes.h
   Description: This is the header file for our personal types
    Course: 150018 C++ Workshop, Exercise 6, Question 2
   Teacher: Dan Zilberstein
   Student1: Avi margali 305645137
   Student2: Yeuda Nuiman 301759692
*/
#ifndef __MYTYPES_H_
#define __MYTYPES_H_
#include <iostream>
#include<sstream>
#include<string>
#include <iomanip>
#include <cstring>
using namespace std;
//new types for my convenience
using uint = unsigned int;
using cstring = char*;

//helper function to convert int to char *
char *converNumToString(int num);

#endif // __MYTYPES_H_
