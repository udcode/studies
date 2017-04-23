/*
File: bus.h
Description: This is the header files with all the declarations for managing a bus fleet
Course: 150018 C++ Workshop, Exercise 3, Question 1
Author: Dan Zilberstein
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
*/

#ifndef __BUS_H_
#define __BUS_H_
#include "mytypes.h"
const uint MAX_SEATS = 60; // Max number of seats in a bus
const uint MAX_ID = 9999;  // Max license id number in our small country

						   /*
						   Bus structure
						   id:     the license number of the bus (1-9999)
						   line:   the line which the bus is assigned to (1-9),
						   0 means that there is no line assigned to the bus
						   sеаts:   amount of sеаts in the bus
						   driver: the name of the driver (each bus holds its own string in dynamic memory)
						   NB: The "_" prefix means that these fields are not for access in other modules than bus.cpp
						   */
struct Bus {
	uint _busId;
	uint _busLine;
	uint _busSeats;
	cstring _busDriver;
};

// Functions for creating (constructing) abus - return nullptr if the id is wrong,
// add the bus to the fleet if it is OK.

Bus* busCtor(int id, int seats = 50);      // Create a bus with id and 50 seats
										   //Bus* busCtor(int, int); // Create a bus with id and given number of seats
										   // returns nullptr if the number of seats is illegal

										   // Setter - Assign (set) the line for a bus (returns false if the line is illegal)
										   // and adds it to the line or unassigns the line for a bus and remove it from the line
										   // if the line number is 0
void busLine(Bus&, int);
// Getter - Return line number assigned to the bus
int busLine(const Bus&);

// Setter - Assign (set) the driver name for a bus
void busDriver(Bus&, const cstring);
// Getter - Return a string with a copy of bus's driver name
cstring busDriver(const Bus&);

// Prints information about the bus:
// - its license id
// - number of seats
// - the line number if it is assigned, "No line is assigned" otherwise
// - The bus driver's name
void busPrint(const Bus&);

// The amount of buses in the fleet
extern uint busFleetCount;

// Destroy the bus fleet with all its buses, unassign the lines and free all the memory
// allocated for the buses and for the fleet management
void busFleetDtor();

// Return the list of all the bus license id numbers in the fleet
//!!!!Don't forget to free the memory
uint* getBusList();

//bool checkBus(int); // Returns true if a bus with given id exists in the fleet
// commented out because it is for use in bus.cpp only

Bus* getBus(int);   // Returns pointer to a bus object with given id, nullptr if the bus
					// does not exist
void delBus(int);   // Removes a bus from the fleet and destroys it (frees its memory),
					// returns false if the bus does not exist or if the bus is assigned
					// to a line
#endif //__BUS_H_
