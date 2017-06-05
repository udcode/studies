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
template <typename T>
class List {
protected:
	//--------------------------------------------
	// inner class Node a single element for the Nodeed List
	//--------------------------------------------
	class Node {
		T   _value;
		Node* _next;
		//------------------------------------------------
		// class Node implementation
		//------------------------------------------------
	public:
		// constructor
		Node(T val,Node* nxt) : _value(val), _next(nxt) {}
		Node(const Node&) : _value(src._value), _next(src._next) {}
		// data areas
		T value() const { return _value; } // getter only
		Node* next()const { return _next; }  // getter
		void next(Node* nxt) {_next = nxt; }   // setter
	}; //end of class Node
	bool toInsert = true;
public:
	// constructors
	List() : head(nullptr) {};
	//--------------------------------------------
	// class List implementation
	//--------------------------------------------
	List(const List& other) {//copy constractor(deep copy)
		Node *src, *trg;//setting two Nodes pointer
		if (other.head == nullptr)//if the list is empty
			head = nullptr;//just assign the head to be nullptr(empty list)
		else {
			head = new Node(other.head->value(), nullptr);//else create a new Node
			if (head == nullptr)//if the build was not successful tell the user
				throw "failed in memory allocation";

			src = other.head;//setting the source pointer to the rhs list
			trg = head;//setting the target pointer to the corrent(lhs) list
			while (src->next() != nullptr) {//while there are Nodes to copy
				trg->next(new Node(src->next()->value(), nullptr));//deep copy the values
				if (trg->next() == nullptr)//if the build was not successful tell the user
					throw "failed in memory allocation";
				src = src->next();//moving the src pointer forward
				trg = trg->next();//moving the target pointer forward
			}
		}
	};
	List(List&&other) {
		// Keep the temp list is permanent
		head = other.head;
		// Avoid destructing it in the temporary object
		other.head = nullptr;
	}
	~List() {
		clear();
	}
	// operations
	void add(T value) {//Add a new value to the front of a Nodeed List
		head = new Node(value, head);
		if (head == nullptr)
			throw "failed in memory allocation";
	}
	T  firstElement() const {
		// return first value in List
		if (isEmpty())
			throw "the List is empty, no first Element";
		return head->value();
	}
	bool search(const T& val) const {

		// loop to test each element
		for (Node* p = head; p != nullptr; p = p->next())
			if (val == p->value())
				return true;
		// not found
		return false;
	}
	bool isEmpty() const {
		if (head == nullptr)//the head is null(list is empty)
			return true;
		return false;
	};
	void removeFirst() {
		// make sure there is a first element
		if (isEmpty())
			throw "the List is empty, no Elements to remove";
		// save pointer to the removed node
		Node* p = head;
		// reassign the first node
		head = p->next();
		p->next(nullptr);
		// recover memory used by the first element
		delete p;
	}
	void clear() {
		// empty all elements from the List
		Node* next;
		for (Node* p = head; p != nullptr; p = next) {
			// delete the element pointed to by p
			next = p->next();
			p->next(nullptr);
			delete p;
		}
		// mark that the List contains no elements
		head = nullptr;
	};
	void insert(T key) {
		Node * x = new Node(key, nullptr);
		if (isEmpty()) {//the first item
			head = x;//insert
			return;
		}
		else {
			Node * last = head;//point to n-1 item
			Node * current = head->next();//pointer to n item
			while (current != nullptr) {//to the last item
				if (current->value() > key) {//if the n item is bigger
										   //insert between the n-1 and the n item
					x->next(current);
					last->next(x);
					return;
				}
				//move forword
				last = last->next();
				current = current->next();
			}
			last->next(x);//add in the end
			return;
		}
	};
	void remove(T key) {
		if (isEmpty()) throw "value not found";
		Node * last = head;//point to n-1 item
		Node * current = head->next();//pointer to n item
		if (last->value() == key) {//it is the first element
			try {
				removeFirst();
			}
			catch (const char * s) {
				cout << s << endl;
			}
			return;
		}
		while (current != nullptr) {//to the last item
			if (current->value() == key) {//found
				last->next(current->next());//jump over the current
				delete current;//free the memory of current
				return;
			}
			//move forword
			last = last->next();
			current = current->next();
		}
		throw "value not found";
	}
	//operators overloading
	List & operator =(const List& rhs) {//deep copy
		if (this == &rhs)return *this;//if it is the same obj return
		this->clear();//in case there was a list allready
		Node * x1 = rhs.head;//setting a variable to hold the flow of the rhs object
		this->head = new Node(x1->value(), nullptr);//creating a whole new obj(deep copy)
		Node * x2 = this->head;//setting a variable to hole the flow of this object
		while (x1 != nullptr) {//while there are things to copy
			x1 = x1->next();//going to the next item to copy
			x2->next(new Node(x1->value(), nullptr));//creating a new node to hold the data
			x2 = x2->next();//going to the next node of this object
		}
		return *this;
	}
	List & operator =(List&& rhs) {
		this->clear();//free the memory
		this->head = rhs.head;//move the head
		rhs.head = nullptr;//reset rhs head
		return *this;
	}
	friend ostream& operator<<(ostream& out, const List& list) {
		List::Node* x = list.head;//setting a variable to hold the flow of the rhs object
		while (x != nullptr) {//until the end of the list
			out << x->value() << " ";//setting spaces
			x = x->next();//moving the pointer forward
		}
		return out;
	}
	friend istream& operator >> (istream& in, List& list) {
		List::Node* x = list.head;//setting a variable to holdthe flow of the rhs object
		T tempBigValue;//setting a value to check correctness of input
		bool flag = true;//setting a flag to tell the operator how long to kip inserting
		in >> tempBigValue;//taking the first falue from user
		while (flag) {//until the input is incorrect
			if (list.head == nullptr) {//first Node
				list.head = new List::Node(tempBigValue, nullptr);//creating the first Node for the list
				x = list.head;//moving the pointer forward
			}
			else {//if it is not the first Node
				in >> tempBigValue;//taking the rest of the values from the user
				if (x->value() <= tempBigValue) {//if the inserted value equal or bigger then the last inserted value(sorted list)
					x->next(new List::Node(tempBigValue, nullptr));//create the Node and insert the value
					x = x->next();//moving the pointer forward
				}
				else {
					flag = false;//if the user inputted a smaller value
				}
			}
		}
		return in;
	}
	void print() {
		Node* x = head;
		while (x != nullptr) {
			cout << x->value()<<endl;
			x = x->next();
		}
	}
protected:
	// data field
	Node* head;
};
//global I/O operators
template<typename T>
ostream& operator<<(ostream& out, const List<T>& list);
template<typename T>
istream& operator >> (istream& in, List<T>&list);
#endif //__LIST_H

