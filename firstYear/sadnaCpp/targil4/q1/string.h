/*
    File: string.h
    Description: This is the header file for string class
    Course: 150018 C++ Workshop, Exercise 4, Question 1
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#ifndef __STRING_H
#define __STRING_H
#include <string.h>
#include <iostream>
#include "Exceptions.h"

using namespace std;

class String {
private:
   char *str;                      // Internal data container - for dynamic c-string
   void setString(const char* s);   // Modifier - for internal usage
public:
   // constructors
   String(const char* s = nullptr); // Default and from c-string
   String(const String& s);         // Copy ctor
   String(String&& s);              // Move ctor
   ~String();                       // Dtor

   char* getString() const;         // Viewer
   // Operators
   String& operator = (const String&);     // Copy Assignment
   String& operator = (String&&);          // Move Assignment
   bool operator == (const String&) const; // Equality
   bool operator != (const String&) const; // Not equality
   bool operator < (const String&) const; //  Bigger
   bool operator > (const String&) const; //  Smaller
   bool operator <= (const String&) const; // Bigger or equal
   bool operator >= (const String&) const; // Smaller or equal

   String & operator += (const String&);    // Addition to object by concatenation
   friend String operator + (String, const String&); // Symmetric addition as friend
   String & operator *= (unsigned int);     // Multiplication by replicating
   friend String operator * (String, unsigned int);  // Symmetric multiplication as friend
   
  int  operator[](const char *);//index operator - get the index of substring

   // Public functions
   int length() const; // Length of the string
   void print() const; // Print the string
   String& insert(int index, const char* str);//insert cstring in the string in index

   friend ostream & operator<< (ostream&,const String&);//output operator for cout
};
//global operators//
ostream & operator<< (ostream&, const String&);//output operator for cout
String operator + (String, const String&); // Declaration of addition operator (global)
String operator * (String, unsigned int);  // Declaration of mulitiplication oeprator (global)

#endif // __STRING_H

