/*
    File: list.h
    Description: This is the header file for linked list class
    Course: 150018 C++ Workshop, Exercise 5, Question 2, part 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
//===== parts of this file was given by the teacher!! ===//

#ifndef __LIST_H
#define __LIST_H
#include<iostream>
using namespace std;

//------------------------------------------------
// Class List - Arbitrary size Lists
// Permits insertion and removal only from the front of the List
//------------------------------------------------
class List {
protected:
    //--------------------------------------------
    // inner class Node a single element for the Nodeed List
    //--------------------------------------------
    class Node {
        int   _value;
        Node* _next;
    public:
        // constructor
        Node(int, Node*);
        Node(const Node&);
        // data areas
        int   value() const; // getter only
        Node* next() const;  // getter
        void  next(Node*);   // setter
    }; //end of class Node

public:
    // constructors
    List();
    List(const List&);
    List(List&&);
    ~List();
    // operations
    void add(int value);
    int  firstElement() const;
    bool search(const int&) const;
    bool isEmpty() const;
    void removeFirst();
    void clear();
    void insert (int key);
    void remove(int key);
    //operators overloading
    List & operator =(const List& rhs);
    List & operator =(List&& rhs);
    friend ostream& operator<<(ostream& out, const List& list);
    friend istream& operator >> (istream& in, List& list);

protected:
    // data field
    Node* head;
};
//global I/O operators
ostream& operator<<(ostream& out, const List& list);
istream& operator >> (istream& in, List&list);

#endif //__LIST_H

