#include "RoundList.h"

List::Node *RoundList::getEnd(){
    Node * tmp = head->next();//get pointer
    while(tmp->next()!=head){//till the end
        tmp=tmp->next();//move
    }
    return tmp;
}

RoundList::RoundList(){}

RoundList::~RoundList(){
    clear();
}

void RoundList::addToEnd(int val){
    if(isEmpty())//the list is empty
        add(val);
    else{
        Node * x =new Node (val,head);//create node point to head
        Node * end = getEnd();//head->next();//get pointer
//        while(tmp->next()!=head){//till the end
//            tmp->next(tmp->next());//move
//        }
        end->next(x);//point from end-1 to the new node
    }
}

int RoundList::search(unsigned int n){
    if(isEmpty())return -1;//empty
    Node * x =head;//pointer
    while(--n){//till the n place
        x=x->next();//move next
    }
    return x->value();//get the value
}

void RoundList::removeFirst(){
    // make sure there is a first element
    if (isEmpty())
        throw "the List is empty, no Elements to remove";
    // save pointer to the removed node
    Node * p = head;
    Node * end = getEnd();
    end->next(head->next());
    // reassign the first node
    if(p->next()!=head){
        head = p->next();
    }else{
        head=nullptr;
    }
    p->next(nullptr);
    // recover memory used by the first element
    delete p;
}

void RoundList::clear(){
    if(isEmpty())return;
    Node * end = getEnd();//get the last node
    end->next(nullptr);//cat the circle
    List::clear();//free the list, using list clear!
}

void RoundList::add(int value){
    if(isEmpty()){
        List::add(value);   //use list addition
        head->next(head);
        return;
    }
    Node * end =getEnd();//get the last node
    List::add(value);   //use list addition
    end->next(head);//update the end to point to the new node
}

void RoundList::print(){

    Node * tmp = head->next();//get pointer
    cout <<head->value()<<" ";
    while(tmp!=head){//till the end
        cout << tmp->value()<<" ";//setting spaces
        tmp=tmp->next();
    }

}
