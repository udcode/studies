/*
File: line.cpp
Description: This is the file for maintain the lines
Course: 150018 C++ Workshop, Exercise 1, Question 1
Teacher: Dan Zilberstein
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
*/
#include "mytypes.h"
#include "line.h"

line lines[MAX_LINES] = { 0 };

bool lineAddBus(int line, int id) {
	bool isCopied = false;//flag for is copied
	if (lines[line - 1].numBuses == 0) {//it is the first bus
										//insert to the first place
		lines[line - 1].busIds = new uint[1];
		lines[line - 1].busIds[0] = id;
		lines[line - 1].numBuses = 1;
		return true;
	}
	if (lines[line - 1].numBuses<MAX_BUSES_IN_LINE) {//check if there is a place for another bus
		if (lines[line - 1].numBuses>0) {//it is not the first bus
										 //we need to copy them all to the new array and put the new bus id to the right place
			uint * tmpBusIds = new uint[lines[line - 1].numBuses + 1];
			int j = 0;
			for (int i = 0; i<lines[line - 1].numBuses; ++i) {
				if (lines[line - 1].numBuses>i) {//check if we are in the list
					if (lines[line - 1].busIds[i]<id)//before the new id
						tmpBusIds[j++] = lines[line - 1].busIds[i];
					else {//after the id and the id
						if (!isCopied) {//put the id and the next
							tmpBusIds[j] = id;
							tmpBusIds[++j] = lines[line - 1].busIds[i];
							isCopied = true;
						}
						else {//after the id
							tmpBusIds[j] = lines[line - 1].busIds[i];
						}
					}
				}
			}
			if (!isCopied) {//copy to the last place
				tmpBusIds[j] = id;
			}
			delete[](lines[line - 1].busIds);//free the memory
			lines[line - 1].busIds = tmpBusIds;//get pointer
			++lines[line - 1].numBuses;//increas the num of the buses
		}
		return true;
	}
	return false;
}
bool checkBus(int line, int id) {
	int left = 0, middle, right = lines[line - 1].numBuses - 1;
	//check if the id is in the range of the searchand the arry is not empty
	if (lines[line - 1].numBuses>0 && id >= lines[line - 1].busIds[0]
		&& id <= lines[line - 1].busIds[lines[line - 1].numBuses - 1]) {
		while (left <= right) {//while the bounds are correct
							   //set the middle
			middle = left + (right - left) / 2;
			if (id == lines[line - 1].busIds[middle]) {// found
				return true;
			}
			else {
				if (id > lines[line - 1].busIds[middle]) {//move left
					left = middle + 1;
				}
				else {//move the right
					right = middle - 1;
				}
			}
		}
	}
	return false;
}

bool lineDelBus(int line, int id) {
	if (checkBus(line, id)) {//bus id exist
		if (lines[line - 1].numBuses>1) {//not the last bus id in this line
										 //create tmp array
			uint * tmpBusIds = new uint[lines[line - 1].numBuses - 1];
			//move over the array and copy them all exept the entry to delete
			for (int i = 0, j = 0; i<lines[line - 1].numBuses; ++i) {
				if (lines[line - 1].busIds[i] != id)//copy
					tmpBusIds[j++] = lines[line - 1].busIds[i];
				else//delete
					continue;
			}
			//delete the old array and set the new
			delete[]lines[line - 1].busIds;
			lines[line - 1].busIds = tmpBusIds;
		}
		else {//the last bus in this line
			  //!!avoid dungling pointer!!
			delete[]lines[line - 1].busIds;
			lines[line - 1].busIds = nullptr;
		}
		--lines[line - 1].numBuses;//decrease the buses number
		return true;
	}
	return false;
}

uint * lineGetBuses(int line) {
	return lines[line - 1].busIds;//return pointer to the bus id's
}

uint lineGetNumBuses(int line) {
	return lines[line - 1].numBuses;//return the buses number
}

void delLines() {
	for (int i = 0; i<MAX_LINES; ++i) {
		if (lines[i].numBuses>0) {//if the line has buses
			delete[]lines[i].busIds;//free the memory
			lines[i].busIds = nullptr;//avoid dungling pointer
		}
	}
}

