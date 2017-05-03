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
   
  int  operator[](const char *);

   // Public functions
   int length() const; // Length of the string
   void print() const; // Print the string
   String& insert(int index, const char* str);

   friend ostream & operator<< (ostream&,const String&);
};
ostream & operator<< (ostream&, const String&);
String operator + (String, const String&); // Declaration of addition operator (global)
String operator * (String, unsigned int);  // Declaration of mulitiplication oeprator (global)

#endif // __STRING_H

