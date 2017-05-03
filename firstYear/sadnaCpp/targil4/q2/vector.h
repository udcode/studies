#ifndef __VECTOR_H
/*
    File: vector.h
    Description: This is the header file for vector class
    Course: 150018 C++ Workshop, Exercise 4, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#define __VECTOR_H
#include <iostream>
using namespace std;
//Vector class
class Vector{
private:
    int * data;//the data
    int capacity;//the max items
    int size;//the accual size of items
    void setVector(const Vector &);// initialize the data and allocate the memory needed
public:
    Vector(int cap=10);  //default ctor get the capacity
    Vector (const Vector&);//copy ctor
    Vector (Vector&&);//move ctor
    ~Vector();//dtor
    //=====operators======
    Vector &operator =(const Vector&);//copy assignment
    Vector& operator =(Vector&&);//move assignment
    bool operator ==(const Vector&)const;//equal
    int& operator[](int);//index --setter
    const int& operator[](int) const;//index --getter
    Vector& operator += (const Vector&);    // Addition to object by concatenation
    friend Vector operator + (Vector, const Vector&); // Symmetric addition as friend
    Vector& operator *= (const Vector& rhs);     // Multiplication by replicating
    friend Vector operator * (Vector, const Vector& rhs);  // Symmetric multiplication as friend
    //public function
    int getCapaticy()const;//get capatity
    int getSize()const;//get size
    void clear();//clear the vector
    void delLast();//delete the last item in the vector
    void insert(int val);//insert in the next available place in the vector

    friend ostream& operator<< (ostream&, Vector&);//output friend

};
ostream& operator<< (ostream&, Vector&);//Output (global)
Vector operator + (Vector, const Vector&);// Declaration of addition operator (global)
Vector operator * ( Vector, const Vector&);// Declaration of mulitiplication oeprator (global)



#endif //__VECTOR_H
