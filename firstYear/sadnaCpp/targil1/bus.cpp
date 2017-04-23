/*
File: bus.cpp
Description: This is the  file for maintain the buses
Course: 150018 C++ Workshop, Exercise 1, Question 1
Teacher: Dan Zilberstein
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
*/

#include "mytypes.h"
#include "line.h"
#include "bus.h"
using namespace std;
Bus** buses = nullptr;
bool checkBus(int id);
bool addBus(const Bus & bus);
/* this function create a bus object and puting it in an array in a sorted form
*param@ - int id = the id of the bus,int seats = the number of seats in the bus
*the function return nullptr if the number of seats/or the bus id is Illegal
*/
Bus* busCtor(int id, int seats) {
	if ((1>id) || (id>MAX_ID) || (seats>60) || (seats < 8))
		return nullptr;

	if (checkBus(id) == false) {//if there is no such bus id in the fleet
								//declering the bus pointer
		Bus* bus = new Bus;
		//intializing the bus struct values
		bus->_busDriver = nullptr;
		bus->_busLine = 0;
		bus->_busId = id;
		bus->_busSeats = seats;

		if (addBus(*bus))//if the adding to the fleet went well return the bus
			return bus;
	}
	else
	{
		cout << setw(10) << "" << "this bus is already exist and therefore was not created" << endl;
	}
	return nullptr;
}
bool addBus(const Bus & bus) {//this function take a bus object and put it in the buses array

	bool inserted = false;
	if (busFleetCount == 0) {//if it is the first bus in the fleet
		buses = new Bus*[1];//create the bus array(fleet)
		buses[0] = const_cast<Bus*>(&bus);//casting the const to a bus* type
		busFleetCount++;//add the bus that was created to the count of buses
		return true;//return true to say the adding was successful
	}
	Bus** tmpBuses = new Bus*[busFleetCount + 1];//creating a temp bus array
	for (int i = 0, newIndex = 0; i<busFleetCount; ++i) {//inserting the new bus in the right spot
		if (i<busFleetCount) {//as long we didnt pass the size of the fleet
			if (buses[i]->_busId<bus._busId) {//if the new bus id is bigger then the busid in the array
				tmpBuses[newIndex++] = buses[i];//insert the old array to the new one up until the corrent bus
			}
			else if (bus._busId<buses[i]->_busId && (!inserted)) {//if we found the spot to insert(and we havn't done it yet
				tmpBuses[newIndex++] = const_cast<Bus*>(&bus);//insert the bus(after casting) in the right spot
				tmpBuses[newIndex++] = buses[i];//insert the next bus to the next spot
				inserted = true;//the bus was inserted and therefore don't enter this if again
				continue;//skip to the next iteration(we allready inserted the bus of the iteration)
			}
			else if (buses[i]->_busId>bus._busId) {//if the new bus id is smaller then the old one
				tmpBuses[newIndex++] = buses[i];//insert the old array into the new one
			}
		}
	}
	if (bus._busId>buses[busFleetCount - 1]->_busId) {//if the new bus id is the biggest insert it last
		tmpBuses[busFleetCount] = const_cast<Bus*>(&bus);
	}
	delete[]buses;//freeing the memory
	buses = tmpBuses;
	++busFleetCount;//increasing the number of buses in the fleet

	return true;
}
void busDtor(const Bus* bus) {
	if (bus->_busDriver != nullptr)//delete the driver name if there is
		delete[] bus->_busDriver;
	delete bus;//delete the bus itself
	bus = nullptr;
}

bool busLine(Bus& bus, int line) {
	if (line>MAX_LINES || line<0) {//if the line is invalid set line to 0
		bus._busLine = 0;
		return false;//return false(nothing has been done
	}
	else if (line == 0) {//if line to be inserted is 0
		bus._busLine = 0;
		lineDelBus(bus._busId, line);//delete the original line from the bus
	}
	else {
		if (lineAddBus(line, bus._busId))//if everything is valid
			bus._busLine = line;//insert the line to the bus
		else
			return false;
	}
	return true;
}

int busLine(const Bus& bus) {//return the bus line of a given bus
	return bus._busLine;
}

bool busDriver(Bus& bus, const cstring driver) {//add the name of a driver to a bus
	if (driver == nullptr || driver == "") {//if a name was not given
		return false;
	}
	else {//if a name was given
		delete[] bus._busDriver;//delete the old name
		bus._busDriver = driver;//insert the name to the bus
		return true;
	}
}

cstring busDriver(const Bus& bus) {//return the name of the driver of a given bus
	return bus._busDriver;
}

void busPrint(const Bus& bus) {
	//print all the data about the given bus
	cout << "- " << bus._busId << endl;
	cout << "- " << bus._busSeats << endl;
	//print the line of the bus if exist
	if (bus._busLine>0)
		cout << "- " << bus._busLine << endl;
	else
		cout << "No line is assigned" << endl;
	if (bus._busDriver != nullptr)
		cout << "- " << bus._busDriver << endl;
}
void busFleetDtor() {
	delLines();//free the lines memory
	for (int i = 0; i<busFleetCount; ++i) {
		busDtor(buses[i]);//delete the bus
	}
	delete[]buses;//free the memory
	buses = nullptr;//avoid dungling pointer
}

uint* getBusList() {
	if (busFleetCount>0) {//the fleet have buses
		uint * arr = new uint[busFleetCount];
		for (int i = 0; i<busFleetCount; ++i) {//fill the array with the id's
			arr[i] = buses[i]->_busId;
		}
		return arr;
	}
	return nullptr;
}

bool checkBus(int id) { //it was bool
	Bus * bus = getBus(id);//get the index of the id
	if (bus != nullptr) {//if found return pointer to the buss
		return true;
	}
	return false;
}

Bus* getBus(int id) {
	int left = 0, middle, right = busFleetCount - 1;
	//check if the id is in the range of the searchand the arry is not empty
	if (busFleetCount>0 && id >= buses[0]->_busId&&id <= buses[busFleetCount - 1]->_busId) {
		while (left <= right) {//while the bounds are correct
							   //set the middle
			middle = left + (right - left) / 2;
			if (id == buses[middle]->_busId) {// found
				return buses[middle]; //it was true
			}
			else {
				if (id > buses[middle]->_busId) {//move left
					left = middle + 1;
				}
				else {//move the right
					right = middle - 1;
				}
			}
		}
	}
	return nullptr;//not found. return nullptr
}

bool delBus(int id) {
	Bus * bus = getBus(id);//get the index of the id
	if (bus != nullptr) {//bus found. lets delete it
		if (bus->_busLine>0) {//the bus has line
			lineDelBus(bus->_busLine, bus->_busId);//delete from line array
		}
		//shrink the array
		Bus ** tmpBuses = new Bus *[busFleetCount - 1];//declare new array to fill, smaller by 1
													   //move over the old array and copy al of them exept the deleted one
		for (int i = 0, j = 0; i<busFleetCount; ++i) {
			if (buses[i]->_busId != id) {
				tmpBuses[j++] = buses[i];
			}
			else//the entry should be deleted so skip it
				continue;
		}
		busDtor(bus);//delete the bus
		delete[]buses;//delete the old array
		buses = tmpBuses;//get the pointer to the new array
		--busFleetCount;//decrease the number of the buses
		return true;
	}
	return false;
}

