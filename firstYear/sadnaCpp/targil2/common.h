/*
File: common.h
Description: This is the header file to manage function that in common use for few moduls
Course: 150018 C++ Workshop, Exercise 2, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#ifndef __COMMON_H_
#define __COMMON_H_

//type for function
using Func =void (*)(void*, const void*, const void*);
/*
    call for Func by the given void pointers
    @param p the pointer for the result
    @parm first pointer to the first element
    @parm second pointer to the second element
    @parm func the function to call
*/
void operation(void *, const void *, const void * ,Func);

#endif // __COMMON_H_
