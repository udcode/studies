/*
File: common.cpp
Description: This is the file to manage function that in common use for few moduls
Course: 150018 C++ Workshop, Exercise 2, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include "common.h"

void operation(void * p, const void * first, const void * second, Func func){
   func(p,first,second);//send the arguments to the func
}
