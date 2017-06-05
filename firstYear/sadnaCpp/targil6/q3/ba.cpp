/*
    File: ba.cpp
    Description: This is the file for BA class
    Course: 150018 C++ Workshop, Exercise 6, Question 3
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "ba.h"

BA::BA(int id, string firstName, string lastName, int numCourses, int *arrGrades, int numGrades)
    :Student(id,firstName,lastName,numCourses),arrGrades(nullptr),numGrades(0){
    setGrades(arrGrades,numGrades);//set grades
}
//copy constractor
BA::BA(const BA & ba){
	this->arrGrades = ba.arrGrades;
	numGrades = ba.numGrades;
}

BA::BA(BA && ba){
	this->arrGrades = ba.arrGrades;
	this->numGrades = ba.numGrades;
	 ba.arrGrades=nullptr;
}

void BA::setGrades(int *arr, int size){
    if(nullptr==arr||0==size)return;//no grades
    if(arrGrades!=nullptr){//there is grades
        delete []arrGrades;
    }
    arrGrades=new int [size];//alloce memory
    for(int i =0;i<size;++i){//fill the array
        arrGrades[i]=arr[i];
    }
    numGrades=size;//set the size
}

double BA::getAvgGrades() const{
    int sum=0;
    for(int i =0;i<numGrades;++i){//sum the grades
        sum+=arrGrades[i];
    }
    return sum/(double)numGrades;//get the avg
}
bool BA::stipend(){
    if(getNumCourses()>=10&&getAvgGrades()>95)//the student is stipend
        return true;
    return false;
}

void BA::printMore(){
    //print the grades
    cout<<"Grades:";
    for(int i=0;i<numGrades;++i){
        cout<<" "<<arrGrades[i];
    }
    cout<<endl;
}
BA::~BA(){
    delete [] arrGrades;//free the memory
}
