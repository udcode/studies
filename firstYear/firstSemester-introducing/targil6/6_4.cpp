//yudi noiman
//id: 301759692
//this code get array of decimal numbers between 0 to 1
//and print the indexes of the array by the numbers order small to bigger

#include <iostream>
using namespace std;

//the size of the array
const int SIZE =6;

int main()
{
    //declare variables
    double numbers[SIZE];
    int indices[SIZE];

    //get the numbers from the user into the array
    cout<<"enter  6 numbers between 0 and 1:"<<endl;
    for(int i=0;i<SIZE;++i){
        cin>>numbers[i];
        //check the numbers to be between 0 to 1, and if not get them from start
        if(numbers[i]<=0.0||numbers[i]>=1.0){
            cout<<"ERROR"<<endl;
            i=-1;
        }
    }
    //find the indexes of the numbers in the array by the right order
    double lastValue =0.0;
    for(int i=0;i<SIZE;++i){
       int index=0;
       double tmpValue;
       //first, find bigger number from the last value
       for(int j=0;j<SIZE;++j){
            if(numbers[j]>lastValue){
                tmpValue=numbers[j];
                index=j;
                break;
            }
       }
       //second, find if ther is a number that smaller then the number we found in tmpValue
       for(int j=0;j<SIZE;++j){
            if(numbers[j]>lastValue&&numbers[j]<tmpValue){
                tmpValue=numbers[j];
                index=j;
            }
       }
       //set the number that found to the last value, and the index into the indices array
        lastValue=numbers[index];
        indices[i]=index;
    }
    //print the indexes
    cout<<"sorted indices:"<<endl;
    for(int i=0;i<SIZE;++i){
        cout<<indices[i]<<" ";
    }
    cout<<endl;
    return 0;
   }
/*
enter  6 numbers between 0 and 1:
0.6 0.5 0.4 0.3 0.1 0.9
sorted indices:
4 3 2 1 0 5
*/

