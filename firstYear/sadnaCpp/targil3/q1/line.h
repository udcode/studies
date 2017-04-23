/*
File: line.h
Description: This is the header files with all the declarations for managing the lines in the fleet
Course: 150018 C++ Workshop, Exercise 3, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#ifndef __LINE_H_
#define __LINE_H_
#include "mytypes.h"

const uint MAX_BUSES_IN_LINE = 5;
const uint MAX_LINES = 9;

struct line {
	uint numBuses;
	uint * busIds;
};

//Add bus to line. evrey line has limit of MAX_BUSES_IN_LINE, if there is no space for
//another bus in the line this function return false
//@param line number
//@param id number
//@retern true if all gets right. else return false
void lineAddBus(int, int);

//Delete bus from the line if exist. otherwise return false
//@param line number
//@param id number
//@retern true if all gets right. else return false
void lineDelBus(int, int);

//Get pointer to the list of id's of the buses in the line
//@param line number
//@retern pointer to list of id's
uint * lineGetBuses(int);

//Get the number of the buses in the line
//@param line number
//@retern number of buses
uint lineGetNumBuses(int);

//Delete all the memory in the line.busIds.
//@param line number
//@retern pointer to list of id's

//@note it is more logical to do it from line module
void delLines();

#endif // __LINE_H_
