/*
File: menu.cpp
Description: This is the file to manage the menu
Course: 150018 C++ Workshop, Exercise 2, Question 1
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include "menu.h"

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.

const char * const menuOptionStrings[] = {
    "exit the program",
    "insert number to element in array",
    "print an array",
    "sum an array",
    "sum the multiple of an array",
    "add two element into another",
    "mutiply two element into another",
    "sub two element into another",
    "sort an array"
};
const char * const arraySelectStrings[] = {
    "int array",
    "float array",
    "rational array",
    "complex array"
};
MenuOption& operator++(MenuOption& opt){
    opt = static_cast<MenuOption>(opt + 1); // static_cast required because enum + int -> int
    return opt;
}
istream& operator>> (istream& is, MenuOption& opt){
    int i;
    is>>i;
    opt=static_cast<MenuOption>(i);
    return is;//get the stream back
}
ostream& operator<< (ostream& os, const MenuOption& opt){
    //print nicely
    os << setw(10) << " " << (int)opt << " -- ";
    os << menuOptionStrings[(int)opt];
    return os;//get the stream back
}

void printArraySelectMenu(){
    //print the sub menu like the MenuOption
    cout<<"Arays list:"<<endl;
    for (ArrySelectMenu chosen = FIRST_SELECT_OPTION; chosen <= LAST_SELECT_OPTION;++chosen) {
        cout << chosen<<endl;
    }
    cout<<"please choose an array: ";
}

istream &operator>>(istream &is, ArrySelectMenu &select){
    int i;
    is>>i;
    select=static_cast<ArrySelectMenu>(i);
    return is;//get the stream back
}
ostream &operator<<(ostream &os, const ArrySelectMenu &select){
    //print nicely
    os << setw(10) << " " << (int)select << " -- ";
    os << arraySelectStrings[(int)select-1];
    return os;//get the stream back
}
ArrySelectMenu& operator++(ArrySelectMenu& select){
    select = static_cast<ArrySelectMenu>(select + 1); // static_cast required because enum + int -> int
    return select;
}
