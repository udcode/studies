/*
File: common.h
Description: This is the header file to manage function that in common use for few moduls
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#ifndef __COMMON_H_
#define __COMMON_H_
#include "rational.h"
//type for function
using Func =void (*)(void*, const void*, const void*);
/*
    call for Func by the given void pointers
    @param p the pointer for the result
    @parm first pointer to the first element
    @parm second pointer to the second element
    @parm func the function to call
*/
void operation(void *, const void *, const void * ,Func);
//helper in convert the compare func to qsort
using comparator = int(*)(const void*, const void*);
// ===== Tamplates=====//
//tamplate to add tow items and return the result
//@note: we can't return a reference to a loacl variable
//so i change it to const T return.
template<typename T>
const T/*&*/ add(const T& a,const T& b){
    return a+b;
}
//tamplate to sub tow items and return the result
template<typename T>
const T/*&*/ sub(const T& a,const T& b){
    return a-b;
}
//tamplate to multiply tow items and return the result
template<typename T>
const T/*&*/ mult(const T& a,const T& b){
    return a*b;
}
//tamplate to compare tow elements, return 0 if tey equel, -1 if the first is smaller
//1 if the first is bigger
template<typename T>
int compare(const T* a,const T* b){
    if(**a==**b)//they are equel
        return 0;
    else if(**a<**b)//the first is smaller
        return -1;
    return 1;
}
//template to print an array in a size
template<typename T>
void printArry(const T* arr,int size){
    for (int i = 0; i < size; ++i)
        cout << *arr[i]<<endl;
}
//template to insert item to an array
template<typename T>
void insertValue(T* item){
    T value;
    cin>>value;//get the value from the user
    *item=value;
}
#endif // __COMMON_H_
