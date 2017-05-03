/*
    File: vector.cpp
    Description: This is the  file for the vectro class
    Course: 150018 C++ Workshop, Exercise 4, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "vector.h"
#include "indexException.h"
#include <cstring>
void Vector::setVector(const Vector & v){
    if(data==v.data)return;//if the data is the same do nothing
    delete []data;//free the old data
    if(v.data!=nullptr){//if the data given is not empty
        data=new int [v.capacity];//get memory
        memcpy(data,v.data,v.capacity*sizeof(int));//copy the memory
    }else{
       data=nullptr;//set to null
    }
    //update the capacity and size to the new
    capacity=v.capacity;
    size=v.size;
}

Vector::Vector(int cap):data(nullptr),capacity(cap),size(0){// initialize the fields
    data=new int [cap];//get the memory
}

Vector::Vector(const Vector & v):data(nullptr){// initialize the fields
    setVector(v);//copy the vector
}

Vector::Vector(Vector && v):data(v.data),size(v.size),capacity(v.capacity){// initialize the fields
    //rest the old vector
    v.data=nullptr;
    v.size=0;
}

Vector::~Vector(){
    //free the memory
    delete []data;
    data=nullptr;
}

Vector &Vector::operator =(const Vector & rhs){
    if(this==&rhs)return *this;//if they are the same return this
    delete []data;//delete the old data
    data=nullptr;//avoid dungling pointer
    setVector(rhs);//copy the new vector
    return *this;
}
Vector &Vector::operator =(Vector && rhs){
    delete []data;//delete old data
    //set the new data
    data=rhs.data;
    capacity=rhs.capacity;
    size=rhs.size;
    //reset the old data
    rhs.data=nullptr;
    rhs.size =0;
    return *this;
}

bool Vector::operator ==(const Vector & rhs) const{
    if(rhs.capacity!=capacity)return false;//if the capacity are not the same return
        for(int i=0;i<capacity;++i){//check every item if they are the same
            if(data[i]!=rhs.data[i])return false;
        }
        return true;
}

int &Vector::operator[](int index){
    if(index<0||index>size)throw IndexException(index,size);//check boundary
    return data[index];//get the item by ref
}

const int &Vector::operator[](int index) const{
    if(index<0||index>size)throw IndexException(index,size);//check boundary
    return data[index];//get the index value
}

Vector &Vector::operator +=(const Vector & rhs){
    if(rhs.data==nullptr)return *this;//if the new data is empty do nothing
    if(data==nullptr){//if the class data is empty
        setVector(rhs);//copy the new data
        return *this;
    }
    int * tmp =new int [capacity+rhs.capacity];//get more memory for both vectors
    memcpy(tmp,data,size*sizeof(int));//copy the first vector
    memcpy(tmp+size,rhs.data,rhs.size*sizeof(int));//copy the second vector
    delete []data;//free old data
    //set the fileds
    size= size+rhs.size;
    capacity=capacity+rhs.capacity;
    data=tmp;
    return *this;
}

Vector &Vector::operator *=(const Vector& rhs){
    if(size!=rhs.size)throw IndexException(size,rhs.size);//check if they are in the same size
    //mult every item with the same index item from the othe vector
    for(int i=0;i<size;++i)
        data[i]=data[i]*rhs.data[i];
    return *this;
}

int Vector::getCapaticy() const{
    return capacity;//get the capacity
}

int Vector::getSize() const{
    return size;//get the size
}

void Vector::clear(){
    //free the memory and rest the fileds
    delete []data;
    data=nullptr;
    size=0;
}

void Vector::delLast(){
    if(data==nullptr)throw 0;//no data
    data[size]=0;//set to zero
    --size;//deacrease the size
}

void Vector::insert(int val){
    if(size==capacity)throw capacity;//check for place
    data[size++]=val;//insert and increase the size
}

Vector operator +(Vector lhs, const Vector & rhs){
    lhs+=rhs;//use += opertor
    return lhs;
}

Vector operator *( Vector lhs, const Vector & rhs){
    try{//try to use *= operator
        lhs*=rhs;
    }catch(IndexException& ex){
        throw ex;//throw up
    }
    return lhs;
}

ostream &operator<<(ostream & os, Vector & rhs){
    //print the fileds
    os<<"capacity: "<<rhs.capacity<<" size: "<<rhs.size<<" content:";
    for(int i =0;i<rhs.size;++i)//print the data
        os<<" "<<rhs.data[i];
    return os;
}
