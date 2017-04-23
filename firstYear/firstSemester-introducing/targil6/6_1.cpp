//yudi noiman
//id: 301759692
//this code get arry with 15 numbers and print if the arry has evry number from 1 to 15

#include <iostream>
using namespace std;

//the size of the array
const int SIZE =15;

/**
    Returns if the array has every number from 1 to size.
    @param arr[] the array to check.
    @param size the size of the array to check, and the max range of numbers.
    @return true for good array and false for bad array.
*/
bool isGoodArray(int arr[],int size);

int main()
{
    int arr [SIZE];
    cout <<"enter 15 numbers:"<<endl;
    //get the arry from the user. check for positive numbers
    for(int i =0;i<=SIZE-1;++i){
        do{
            cin >>arr[i];
            if(arr[i]<=0){
                cout<<"ERROR"<<endl;
            }
        } while(arr[i]<=0);
    }
    //check if the array is good
    if(isGoodArray(arr,SIZE)){
        cout<<"GOOD"<<endl;
    }else{
        cout<<"NOT GOOD"<<endl;
    }
    return 0;
}
bool isGoodArray(int arr[],int size){
    bool found =true;
    //check for every number from 1 to size
    for(int i =1;i<=size&&found;++i){
        found =false;
        //check in every cell in the array
        for(int j = 0 ;j<size;++j){
            if(arr[j]==i){
                found=true;
		break;
            }
        }
    }
    return found;
}

/*
enter 15 numbers:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 16
NOT GOOD
*/

