/*
    File: main.cpp
    Description: This is the file for Vector Class
    Course: 150018 C++ Workshop, Exercise 4, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include "vector.h"
#include "indexException.h"
using namespace std;
//menu options
enum Action {
    STOP,
    INSERT_NUMBERS_TO_VECTOR,
    COMPARE,
    MULTIPLY,
    COPY_FIRST_TO_THIRD,
    SUM_TO_THE_THIRD,
    CLEAR_VECTOR,
    DELETE_LAST,
    PRINT_ALL
};
//sub menu options, for the vector to go for
enum VectorsChoice {
    V1=1,
    V2
};
//print the sub menu and get the opion from the user
VectorsChoice subMenu() {
    cout << "choose a vector:"<<endl;
    cout <<setw(12)<< "1 for v1" << endl;
    cout << setw(12)<<"2 for v2" << endl;
    //get the choice from the user
    int x;
    cin >> x;
    return (VectorsChoice)x;
}
//print the menu of the program
Action menu() {
    cout << "enter 1 to insert numbers to vector" << endl;
    cout << "enter 2 to compare the two vectors" << endl;
    cout << "enter 3 to multiply the two vectors" << endl;
    cout << "enter 4 to copy the first vector to the third vector" << endl;
    cout << "enter 5 to sum the first and second vectors into the third vector" << endl;
    cout << "enter 6 to clear vector" << endl;
    cout << "enter 7 to delete last item in vector" << endl;
    cout << "enter 8 to print all the vectors" << endl;
    cout << "enter 0 to stop" << endl;
    //get the choice from the user
    int x;
    cin >> x;
    return (Action)x;
}

int main() {
    Vector v1(9), v2(9), v3;    //initialize 3 vectors
    VectorsChoice vectorChoice;
    int val,size;
    Action ac = menu();//print the menu
    while (ac) {//run until the user send zero
        switch (ac) {
        //insert the numbers given from the user to the vector
        case INSERT_NUMBERS_TO_VECTOR:{
            vectorChoice =subMenu();//print the sub menu
            //get the size of the input from the user
            cout<<"insert the amount of numbers you want to insert:"<<endl;
            cin>>size;
            cout<<"insert the numbers:"<<endl;
            switch (vectorChoice) {
            case V1:
                v1.clear();//free the old entries
                //try to insert to the size
                for(int i =0;i<size;++i){
                    cin>>val;//get the value from the user
                    try{//try to insert the value
                        v1.insert(val);
                    }catch(int capacity){
                        //error while try to write more then the capacity
                        cout<<"ERROR: you can't insert more then "<<capacity<< " items!"<<endl;
                        break;
                    }
                }
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');//ignore the rest of the line
                break;
            case V2:
                v2.clear();//free the old entries
                //try to insert to the size
                for(int i =0;i<size;++i){
                    cin>>val;//get the value from the user
                    try{//try to insert the value
                        v2.insert(val);
                    }catch(int capacity){
                        //error while try to write more then the capacity
                        cout<<"ERROR: you can't insert more then "<<capacity<< " items!"<<endl;
                        break;
                    }
                }
                cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');//ignore the rest of the line
            }
            break;
        }
        case COMPARE:
            if(v1==v2)//check if they are equel and print massege about that
                cout<<"the first and the second vectors are equel"<<endl;
            else
                cout<<"the first and the second vectors are not equel"<<endl;
            break;
        case MULTIPLY:{
            //try to multiply the vectors
            Vector tmp;
            try{
                tmp=v2*v1;
            }catch(IndexException&){//the vectors are not in the same size
                cout<<"ERROR: your vectors are not in the same size"<<endl;
                break;
            }
            cout<<tmp<<endl;//print the mult
        }break;
        case COPY_FIRST_TO_THIRD:
            //copy the first vector to the last
            v3=v1;
            break;
        case SUM_TO_THE_THIRD:
            //insert into the last vector the sum of the first and second vectors
            v3=v1+v2;
            break;
        case CLEAR_VECTOR:
            //clear a vector
            vectorChoice =subMenu();//print the sub menu
            switch (vectorChoice) {
            case V1:
                v1.clear();//clear
                break;
            case V2:
                v2.clear();//clear
                break;
            }
            break;
        case DELETE_LAST:
            //delete the last item in a vector
            vectorChoice =subMenu();//print the sub menu
            switch (vectorChoice) {
            case V1:
                v1.delLast();//delete
                break;
            case V2:
                v2.delLast();//delete
                break;
            }
            break;
        case PRINT_ALL:
            //print the vectors
            cout<<v1<<endl;
            cout<<v2<<endl;
            cout<<v3<<endl;
            break;
        }
        ac = menu();
    }
    return 0;
}
