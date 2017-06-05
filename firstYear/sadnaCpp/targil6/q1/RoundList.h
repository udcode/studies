#ifndef ROUNDLIST_H
#define ROUNDLIST_H

#include "List.h"
class RoundList : public List{
    Node * getEnd();
public:
    RoundList();
    ~RoundList();
    void addToEnd(int val);
    int search(unsigned int n);
    void removeFirst();
    void clear ();
    void add(int value);
    void print();

};

#endif // ROUNDLIST_H
