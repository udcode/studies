/*
File: main.cpp
Description: This is the test program (main) for managing a bus fleet
Course: 150018 C++ Workshop, Exercise 3, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include "mytypes.h"
#include "bus.h"
#include "line.h"
//
// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements
enum MenuOption {
    EXIT_MENU,
    ADD_BUS_TO_FLEET,
    ADD_BUS_WITH_N_SEATS_TO_FLEET,
    REMOVE_BUS_FROM_FLEET,
    ASSIGN_LINE_TO_BUS,
    UNASSIGN_LINE_FROM_BUS,
    ASSIGN_NAME_OF_DRIVER_TO_BUS,
    SHOW_BUS,
    SHOW_ALL_BUSES,
    SHOW_ALL_BUSES_IN_LINE,
    SHOW_NUMBER_OF_BUSES_IN_FLEET,
    // a neat trick for for-loop initial and final values
    FIRST_MENU_OPTION = EXIT_MENU,
    LAST_MENU_OPTION = SHOW_NUMBER_OF_BUSES_IN_FLEET
};

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.
const char * const menuOptionStrings[] = {
    "exit the program",
    "add bus to fleet",
    "add bus to fleet with n seats",
    "remove a bus from fleet",
    "assign line to a bus",
    "unassign line from a bus",
    "assign name of driver to bus",
    "show a bus information",
    "show all the the buses in the fleet",
    "show all the the buses in the line",
    "show number of buses in fleet"

};


uint busFleetCount = 0;

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main() {
    MenuOption chosen;
    // Everything happens inside of this do-while loop, until the user
    //     has decided to exit (or an error occurs).
    do {
        cout << endl << "Menu options:" << endl << endl;
        const int menuIndent = 10;
        int busSeats = 0, busId = 0, line = 0;//The user input can be negative
        char driver[80];
        Bus *bus = nullptr;
        cstring ptrDriver = nullptr;
        // The casts are for doing the "++" as an int type since
        // they are not allowed as a MenuOption type.
        for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
             chosen = (MenuOption)((int)chosen + 1)) {
            cout << setw(menuIndent) << " " << chosen << " -- ";
            cout << menuOptionStrings[chosen] << endl;
        }
        cout << endl;

        int chosenInt;
        cout << "Please choose a menu option: ";
        cin >> chosenInt;
        // After the user has input an int, it is cast to a
        //   MenuOption variable.
        chosen = (MenuOption)chosenInt;

        // Note how the individual cases, match nicely to the
        //     operations they will perform.
        switch (chosen) {
        case EXIT_MENU:
            // adios
            cout << "Thanx for using Bus Fleet Management Program!" << endl;
            break;
        case ADD_BUS_TO_FLEET:
            //get the number from the user and create bus struct with default seats
            cout << setw(menuIndent) << "enter the bus id" << endl;
            cin >> busId;
            try{
                 busCtor(busId);//create the bus
            } catch( char * id){
                cout<<"bus: "<<id<<" was not created due to error"<<endl;
            }
            break;
        case ADD_BUS_WITH_N_SEATS_TO_FLEET:
            //get the number from the user and the number of seats and create bus struct
            cout << setw(menuIndent) << "enter the bus id" << endl;
            cin >> busId;
            cout << setw(menuIndent) << "enter the bus seats" << endl;
            cin >> busSeats;
            try{
                 busCtor(busId,busSeats);//create the bus
            }catch(char * id){
                cout<<"bus: "<<id<<" was not created due to error"<<endl;
            }catch(int seats){
                cout<<seats <<" is not a valid number of seats"<<endl;
            }
            break;
        case REMOVE_BUS_FROM_FLEET:
            //remove the bus by the id given from the user
            cout << setw(menuIndent) << "enter the bus id" << endl;
            cin >> busId;
            try{
                 delBus(busId);//delete the bus
            }catch(char * a){
                cout<<"bus: "<<a<<" was not empty and therefore was not deleted"<<endl;
            }catch(int a){
                cout<<"bus: "<<a<<" was not deleted becous he had a line"<<endl;
            }

            break;
        case ASSIGN_LINE_TO_BUS:
            //assign line to bus, get the line number and the bus id from the user
            cout << setw(menuIndent) << "enter the BusId to be inserted to" << endl;
            cin >> busId;
            cout << setw(menuIndent) << "enter the line to be inserted" << endl;
            cin >> line;
            try{
                bus = getBus(busId);//get pointer to the bus
                try{
                    busLine(*(bus), line);//assign lie to the bus
                }catch(char *){
                     cout<<"line was not assgin because it was not a valid bus id"<<endl;
                }catch(int){
                    cout<<"line was not assgin because it was not valid"<<endl;
                }
            }catch (char * id){
                cout<<id<<" no such bus id"<<endl;
            }
            break;
        case UNASSIGN_LINE_FROM_BUS:
            //unassign line from bus, get the bus id from the user
            cout << setw(menuIndent) << "enter the BusId to be unassigned" << endl;
            cin >> busId;
            try{
                bus = getBus(busId);//get pointer to the bus
                try{
                    busLine(*(bus), 0);//assign line to the bus
                }catch(char *){
                    cout<<"line was not unassgin because it was not a valid bus id"<<endl;
                }catch(int){
                    cout<<"line was not unassgin because it was not valid"<<endl;
                }
            }catch (char * id){
                cout<<id<<" no such bus id"<<endl;
            }
            break;
        case ASSIGN_NAME_OF_DRIVER_TO_BUS:
            //assigning name of driver to a bus
            cout << setw(menuIndent) << "enter the BusId to be inserted to" << endl;
            cin >> busId;
            cout << setw(menuIndent) << "enter name of driver" << endl;
            cin.ignore();
            cin.getline(driver, 80);
            ptrDriver = new char[strlen(driver) + 1];
            strcpy_s(ptrDriver,strlen(driver) + 1, driver);//copy the name to pointer
            ptrDriver[strlen(driver)] = '\0';
            try{
                bus = getBus(busId);//get pointer to the bus
            try{
                busDriver(*bus, ptrDriver);//set the name to the bus
            }
            catch(nullptr_t){
                cout<<"ERROR: driver name is empty"<<endl;
            }
        }catch(char * id){
                cout<<id<<" no such bus id"<<endl;
            }
            break;
        case SHOW_BUS: {
            //get the id from the user and print the data
            cout << "insret ID licence:" << endl;
            cin >> busId;
            if (busId>0 && busId<MAX_ID) {//is valid id
                try{
                     bus = getBus(busId);//get pointer to the bus
                     busPrint(*bus);//print
                }catch(char * id){
                    cout<<id<<" no such bus id"<<endl;
                }
            }
        }
            break;
        case SHOW_ALL_BUSES: {
            //show all the buses in the fleet
            uint * busesIds = getBusList();
            for (int i = 0; i<busFleetCount; ++i) {
                busPrint(*getBus(busesIds[i]));//print bus info
                cout << endl;//print empty line between buses
            }
            if (busesIds != nullptr)
                delete[] busesIds;
        }
            break;
        case SHOW_ALL_BUSES_IN_LINE:
            //get the line from the user and print the data
            cout << "insret line number:" << endl;
            cin >> line;
            if (line >0 && line<MAX_LINES) {//is valid line
                //get the list of id's and number of buses
                uint numBuses = lineGetNumBuses(line);
                uint * arrLines = lineGetBuses(line);
                if (numBuses>0) {
                    //print them all
                    for (int i = 0; i<numBuses; ++i) {
                        busPrint(*(getBus(arrLines[i])));
                        cout << endl;//print empty line between buses
                    }
                }
            }
            break;
        case SHOW_NUMBER_OF_BUSES_IN_FLEET:
            //print the number of the buses in the fleet
            cout << setw(menuIndent) << "the number of buses in the fleet is" << " " << busFleetCount << endl;
            break;
        default:
            break;
        }
    } while (chosen != EXIT_MENU);

    //free the memory
    busFleetDtor();

    return 0;
}
