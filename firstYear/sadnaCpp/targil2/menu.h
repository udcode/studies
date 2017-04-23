/*
File: menu.h
Description: This is the header file to manage the menu
Course: 150018 C++ Workshop, Exercise 2, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/

#ifndef __MENU_H_
#define __MENU_H_
#include "mytypes.h"
#include <iostream>
#include <iomanip>

using namespace std;
// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements


enum MenuOption {
    EXIT_MENU,
    INSERT_NUM_TO_ELEMENT,
    PRINT_ARRAY,
    SUMS_ARRAY,
    SUM_OF_MULTI_ARRAY,
    ADD_TWO_ELEMENTS,
    MULTIPLY_TWO_ELEMENTS,
    SUB_TWO_ELEMENTS,
    SORT_ARRAY,

    // a neat trick for for-loop initial and final values
    FIRST_MENU_OPTION = EXIT_MENU,
    LAST_MENU_OPTION = SORT_ARRAY
};
enum ArrySelectMenu {
    INT_ARRAY=1,
    FLOAT_ARRAY,
    RATIONAL_ARRAY,
    COMPLEX_ARRAY,
    // a neat trick for for-loop initial and final values
    FIRST_SELECT_OPTION = INT_ARRAY,
    LAST_SELECT_OPTION = COMPLEX_ARRAY
};


// prefix (++) for increasing the menueOption
MenuOption& operator++(MenuOption& opt);
//overload the input operaor of the menuOpt
istream& operator>> (istream& is, MenuOption& opt);
ostream& operator<< (ostream& os,const MenuOption& opt);

//print the menu for selection of the array.
void printArraySelectMenu();

//!!!!!operators for ArrySelectMenu. the professional way :-)!!!!!
//overload the input operaor of the ArrySelectMenu
istream& operator>> (istream& is,ArrySelectMenu& select);
ostream& operator<< (ostream& os,const ArrySelectMenu& select);
// prefix (++) for increasing the ArrySelectMenu
ArrySelectMenu& operator++(ArrySelectMenu& select);
#endif // __MENU_H_
