/*
File: list.cpp
Description: This is the  file for linked list class
Course: 150018 C++ Workshop, Exercise 5, Question 2, part 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
//===== parts of this file was given by the teacher!! ===//

#include "list.h"
//------------------------------------------------
// class Node implementation
//------------------------------------------------
List::Node::Node(int val, List::Node* nxt) : _value(val), _next(nxt) {}
List::Node::Node(const List::Node& src) : _value(src._value), _next(src._next) {}
int         List::Node::value() const { return _value; }
List::Node* List::Node::next() const { return _next; }
void        List::Node::next(Node* nxt) { _next = nxt; }

//--------------------------------------------
// class List implementation
//--------------------------------------------
List::List() : head(nullptr) {}

List::List(const List &other) {//copy constractor(deep copy)
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
}

List::List(List &&other) {
	// Keep the temp list is permanent
	head = other.head;
	// Avoid destructing it in the temporary object
	other.head = nullptr;
}

List::~List() {
	clear();
}

bool List::isEmpty() const {
	if (head == nullptr)//the head is null
		return true;
	return false;
}


void List::add(int val) {
	//Add a new value to the front of a Nodeed List
	head = new Node(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}
int List::firstElement() const {
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value();
}

bool List::search(const int &val) const {
	// loop to test each element
	for (Node* p = head; p != nullptr; p = p->next())
		if (val == p->value())
			return true;
	// not found
	return false;
}

void List::removeFirst() {
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


void List::clear() {
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
}

void List::insert(int key) {
	Node * x = new Node(key, nullptr);
	if (isEmpty()) {//the first item
		head = x;//insert
		return;
	}
	else {
		Node * last = head;//point to n-1 item
		Node * current = head->next();//pointer to n item
		if (last->value()>key) {//insert in the first place
			x->next(last);
			head = x;
			return;
		}
		while (current != nullptr) {//to the last item
			if (current->value()>key) {//if the n item is bigger
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
}

void List::remove(int key) {
	if (isEmpty()) throw "value not found";
	Node * last = head;//point to n-1 item
	Node * current = head->next();//pointer to n item
	if (last->value() == key) {//it is the first element
		try {
			removeFirst();
		}catch(const char * s){
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


List & List::operator=(const List & rhs) {//deep copy
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

List & List::operator=(List && rhs) {
	this->clear();//free the memory
	this->head = rhs.head;//move the head
	rhs.head = nullptr;//reset rhs head
	return *this;
}

ostream & operator<<(ostream & out, const List & list) {
	List::Node* x = list.head;//setting a variable to hold the flow of the rhs object
	while (x != nullptr) {//until the end of the list
		out << x->value() << " ";//setting spaces
		x = x->next();//moving the pointer forward
	}
	return out;
}
istream& operator >> (istream& in, List& list) {
	List::Node* x = list.head;//setting a variable to holdthe flow of the rhs object
	int tempBigValue;//setting a value to check correctness of input
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
