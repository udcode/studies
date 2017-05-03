/*
    File: indexException.h
    Description: This is the header file for exeptions
    Course: 150018 C++ Workshop, Exercise 4, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __INDEX_EXSEPTION_H
#define  __INDEX_EXSEPTION_H
//struct for exeptions
struct IndexException {
   unsigned int index;//current index
   unsigned int maxIndex;//the max index
   IndexException(int ind, int max) : index(ind), maxIndex(max) {}//ctor
};

#endif //__INDEX_EXSEPTION_H
