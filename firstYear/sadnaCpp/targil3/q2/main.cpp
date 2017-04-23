/*
File: main.cpp
Description: This is the test program (main) for maintain numbers (int,float,rational,complex)
Course: 150018 C++ Workshop, Exercise 3, Question 2
Student1: Avi margali 305645137
Student2: Yeuda Nuiman 301759692
Teacher: Dan Zilberstein
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "mytypes.h"
#include "common.h"
#include "menu.h"
#include "complex.h"
#include "rational.h"

using namespace std;
const uint SIZE_ARR =4;

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main() {
    MenuOption chosen;
    ArrySelectMenu arrChoose;
    //4 arrays for the data
    int *arrInteger [SIZE_ARR];
    float *arrFloat[SIZE_ARR];
    //arrays of pointers to the dynamic objects
    Rational * arrRational[SIZE_ARR];
    Complex * arrComplex[SIZE_ARR];

    srand(time(0));//set for rand

    //fill the arrays with random numbers
    int nu;
    uint den;
    float im,real;
    for(int i =0;i<SIZE_ARR;++i){
        arrInteger[i]=new int((-10)+(rand()%(21)));
        //fill with float random number
        arrFloat[i]=new float((-10.0f)+static_cast<float>(rand())/( static_cast<float>(RAND_MAX/(20.0f))));
        nu =(rand() % (21))-10;//random numerator
        den = (rand() % 30) + 1;//random denumeator
        arrRational[i] = &rationalCtor(nu, den);
        //fill with float random number
        im=(-10.0f)+static_cast<float>(rand())/( static_cast<float>(RAND_MAX/(20.0f)));
        real=(-10.0f)+static_cast<float>(rand())/( static_cast<float>(RAND_MAX/(20.0f)));
        arrComplex[i]=&complexCtor(real,im);
    }
    // Everything happens inside of this do-while loop, until the user
    //     has decided to exit (or an error occurs).
    do {
        //print the menu options
        cout << endl << "Menu options:" << endl << endl;
        for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;++chosen) {
            cout<<chosen<<endl;
        }
        cout << endl;
        cout << "Please choose a menu option: ";
        cin >> chosen;

        // Note how the individual cases, match nicely to the
        //     operations they will perform.
        int src1, src2, dest;
        int sumI=0;
        float sumF=0;
        switch (chosen) {
        case EXIT_MENU:
            // adios
            cout << "Thanx for using the Program!" << endl;
            break;
        case INSERT_NUM_TO_ELEMENT:
            //insert an element into array chosen by the user
            int index;
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            cout<<"insert the index of the element (0-3)"<<endl;
            cin>>index;
            if(index>=0&&index<=3){
                cout<<"insert the value of the element";
                switch (arrChoose) {
                case INT_ARRAY:
                    //insert value to int array
                    cout<<" (int)"<<endl;
                    insertValue(arrInteger[index]);
                    break;
                case FLOAT_ARRAY:
                    //insert value to float array
                    cout<<" (float)"<<endl;
                    insertValue(arrFloat[index]);
                    break;
                case RATIONAL_ARRAY:
                    //insert value to rational array
                    cout << " (numer) (denum) -7 5" << endl;
                    insertValue(arrRational[index]);
                    break;
                case COMPLEX_ARRAY:
                    //insert value to complex array
                    cout<<" (real) (imaginary) i.e 2 3"<<endl;
                    insertValue(arrComplex[index]);
                    break;
                default:
                    break;
                }
            }else{//no array chosen
                cout <<"ERROR: enter a valid array number"<<endl;
            }
            break;
        case PRINT_ARRAY:
            //print an array chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            switch (arrChoose) {
            case INT_ARRAY:
                //print the int array
                printArry(arrInteger,SIZE_ARR);
                break;
            case FLOAT_ARRAY:
                //print the float array
                printArry(arrFloat,SIZE_ARR);
                break;
            case RATIONAL_ARRAY:
                //print the rational array
                printArry(arrRational,SIZE_ARR);
                break;
            case COMPLEX_ARRAY:
                //print the complex array
                printArry(arrComplex,SIZE_ARR);
                break;
            default:
                cout <<"ERROR: enter a valid array number"<<endl;
                break;
            }
            break;
        case SUMS_ARRAY:
            //sums an array chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            switch (arrChoose) {
            case INT_ARRAY:
                //sums the int array
                for (int i = 0; i < SIZE_ARR; ++i)
                    sumI=add(sumI,*arrInteger[i]);
                cout << sumI;
                break;
            case FLOAT_ARRAY:
                //sums the float array
                for (int i = 0; i < SIZE_ARR; ++i)
                    sumF=add(sumF,*arrFloat[i]);
                cout << sumF;
                break;
            case RATIONAL_ARRAY: {
                //sums the rational array
                Rational * sumR = &rationalCtor(0);
                for (int i = 0; i < SIZE_ARR; ++i)
                    *sumR=add(*sumR,*arrRational[i]);
                cout << *sumR;
                delete sumR;
            }
                break;
            case COMPLEX_ARRAY:{
                //sums the complex array
                Complex * sumC=&complexCtor(0);
                for(int i=0;i<SIZE_ARR;++i)
                    *sumC=add(*sumC, *arrComplex[i]);
                cout<<*sumC;
                delete sumC;
            }
                break;
            default:
                cout <<"ERROR: enter a valid array number"<<endl;
                break;
            }
            break;
        case SUM_OF_MULTI_ARRAY:
            //sums the multypli of an array chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            switch (arrChoose) {
            case INT_ARRAY:
                //sum the multiply of the int array
                sumI = 1;
                for (int i = 0; i<SIZE_ARR; ++i)
                    sumI=mult(sumI,*arrInteger[i]);
                cout << sumI;
                break;
            case FLOAT_ARRAY:
                //sum the multiply of the float array
                sumF = 1;
                for (int i = 0; i<SIZE_ARR; ++i)
                    sumF=mult(sumF,*arrFloat[i]);
                cout << sumF;
                break;
            case RATIONAL_ARRAY: {
                //sum the multiply the rational array
                Rational * sumR = &rationalCtor(1);
                for (int i = 0; i < SIZE_ARR; ++i)
                    *sumR =mult (*sumR , *arrRational[i]);
                cout << *sumR;
                delete sumR;
            }
                break;
            case COMPLEX_ARRAY:{
                //sum the multiply the rational array
                Complex * sumC = &complexCtor(1);
                for (int i = 0; i < SIZE_ARR; ++i)
                   *sumC = mult(*sumC , *arrComplex[i]);
                cout << *sumC;
                delete sumC;
            }
                break;
            default:
                cout <<"ERROR: enter a valid array number"<<endl;
                break;
            }
            break;
        case  ADD_TWO_ELEMENTS:
            //add two element in the array into another chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            cout<<"insert tree numbers of indexes in the array (src) (src) (dest) i.e 1 2 3"<<endl;
            cin>>src1>>src2>>dest;
            if(src1 >= 0 && src1 <= 3 && src2 >= 0 && src2 <= 3 && dest >= 0 && dest <= 3){//check for bounds
                switch (arrChoose) {
                case INT_ARRAY:
                    //add two element to another in int array
                    operation(&arrInteger[dest], &arrInteger[src1], &arrInteger[src2], [](void * dest, const void * src1, const void * src2) {*static_cast<int*>(dest) = *((int*)src1) + *((int*)src2); });
                    break;
                case FLOAT_ARRAY:
                    //add two element to another in float array
                    operation(&arrFloat[dest], &arrFloat[src1], &arrFloat[src2], [](void * dest, const void * src1, const void * src2) {*static_cast<float*>(dest) = *((float*)src1) + *((float*)src2); });
                    break;
                case RATIONAL_ARRAY:
                    //add two element to another in rational array
                    operation(arrRational[dest],arrRational[src1],arrRational[src2],addRational);
                    break;
                case COMPLEX_ARRAY:
                    //add two element to another in complex array
                    operation(arrComplex[dest],arrComplex[src1],arrComplex[src2],addComplex);
                    break;
                default:
                    cout <<"ERROR: enter a valid array number"<<endl;
                    break;
                }
            }else{
                cout<<"ERROR: index out of range"<<endl;
            }
            break;
        case MULTIPLY_TWO_ELEMENTS:
            //multiply two element in the array into another chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            cout << "insert tree numbers of indexes in the array (src) (src) (dest) i.e 1 2 3" << endl;
            cin >> src1 >> src2 >> dest;
            if (src1 >= 0 && src1 <= 3 && src2 >= 0 && src2 <= 3 && dest >= 0 && dest <= 3){//check for bounds
                switch (arrChoose) {
                case INT_ARRAY:
                    //multiply two element to another in int array
                    operation(&arrInteger[dest], &arrInteger[src1], &arrInteger[src2], [](void * dest, const void * src1, const void * src2) {*static_cast<int*>(dest) = (*((int*)src1)) * (*((int*)src2)); });
                    break;
                case FLOAT_ARRAY:
                    //multiply two element to another in float array
                    operation(&arrFloat[dest], &arrFloat[src1], &arrFloat[src2], [](void * dest, const void * src1, const void * src2) {*static_cast<float*>(dest) = (*((float*)src1)) * (*((float*)src2)); });
                    break;
                case RATIONAL_ARRAY:
                    //multiply two element to another in rational array
                    operation(arrRational[dest], arrRational[src1], arrRational[src2], multRational);
                    break;
                case COMPLEX_ARRAY:
                    //multiply two element to another in complex array
                    operation(arrComplex[dest], arrComplex[src1], arrComplex[src2], multComplex);
                    break;
                default:
                    cout <<"ERROR: enter a valid array number"<<endl;
                    break;
                }
            }else{
                cout<<"ERROR: index out of range"<<endl;
            }
            break;
        case SUB_TWO_ELEMENTS:
            //sub two element in the array into another chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            cout << "insert tree numbers of indexes in the array (src) (src) (dest) i.e 1 2 3" << endl;
            cin >> src1 >> src2 >> dest;
            if (src1 >= 0 && src1 <= 3 && src2 >= 0 && src2 <= 3 && dest >= 0 && dest <= 3){//check for bounds
                switch (arrChoose) {
                case INT_ARRAY:
                    //sub two element to another in int array
                    *arrInteger[dest]=sub(*arrInteger[src1],*arrInteger[src2]);
                    break;
                case FLOAT_ARRAY:
                    //sub two element to another in float array
                   *arrFloat[dest]=sub(*arrFloat[src1],*arrFloat[src2]);
                    break;
                case RATIONAL_ARRAY:
                    //sub two element to another in rational array
                   *arrRational[dest]=sub(*arrRational[src1],*arrRational[src2]);
                    break;
                case COMPLEX_ARRAY:
                    //sub two element to another in complex array
                    *arrComplex[dest]=sub(*arrComplex[src1],*arrComplex[src2]);
                    break;
                default:
                    cout <<"ERROR: enter a valid array number"<<endl;
                    break;
                }
            }else{
                cout<<"ERROR: index out of range"<<endl;
            }
            break;
        case SORT_ARRAY:
            //sort an array chosen by the user
            printArraySelectMenu();//print sub menu
            cin >>arrChoose;
            switch (arrChoose) {
            case INT_ARRAY:
                //sort the int array
                qsort(arrInteger, SIZE_ARR, sizeof(int*), (comparator)compare<int*>);
                break;
            case FLOAT_ARRAY:
                //sort the float array
                qsort(arrFloat, SIZE_ARR, sizeof(float*), (comparator)compare<float*>);
                break;
            case RATIONAL_ARRAY:
                //sort the rational array
                qsort(arrRational,SIZE_ARR,sizeof(Rational*),(comparator)compare<Rational*>);
                break;
            case COMPLEX_ARRAY:
                //sort the complex array
                qsort(arrComplex,SIZE_ARR,sizeof(Complex *),(comparator)compare<Complex*>);
                break;
            default:
                cout <<"ERROR: enter a valid array number"<<endl;
                break;
            }
            break;
        default:
            break;
        }
    } while (chosen != EXIT_MENU);

    //free the memory
    for(int i=0;i<SIZE_ARR;++i){
        delete arrInteger[i];
        delete arrFloat[i];
        delete arrComplex[i];
        delete arrRational[i];
    }

    return 0;
}
