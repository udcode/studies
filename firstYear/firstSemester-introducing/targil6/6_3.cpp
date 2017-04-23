//this code get array and print the array after deleting the double numbers

#include <iostream>
using namespace std;

//the size of the array
const int SIZE =100;

/**
    Fix the arr to be with no double numbers.
    @param arr[] the original array.
    @param fixArr[] the fixed array with no double numbers.
    @param size the size of the arr.
    @param &newSize the real size of the new array by ref.
*/
void fixArray(int arr[],int fixArr [],int size,int &newSize);
int main()
{
    //set the variables
    int array[SIZE];
    int fixedArray[SIZE];
    int newSize;
    //get the numbers from the user
    cout<<"enter up to 100  values, to stop enter 0:"<<endl;
    for(int i=0;i<SIZE;++i){
        cin>>array[i];
        if(array[i]==0){
            break;
        }
    }
    //call to fixArray to get the fixed array with no double numbers
    fixArray(array,fixedArray,SIZE,newSize);
    //print the fixed array
    cout<<"the new vector is:"<<endl;
    for(int i=0 ;i <newSize;++i){
        cout<<fixedArray[i]<<" ";
    }
    cout<<endl;
    //fix the size of the new array
    cout<<"number of elements: "<<newSize<<endl;
   return 0;
}
void fixArray(int arr[], int fixArr[], int size, int &newSize){
    int n=0;
    //copy the arr one by one unlese the number already codied.
    for(int i=0;arr[i]!=0&&i<size;++i){
        bool isCopied=false;
        for(int j =0;j<i;++j){
            //check if the number already copied.
            if(arr[i]==fixArr[j]){
                isCopied=true;
            }
        }
        if(!isCopied){
            //copy the number to the new array, and increase the new size by one.
            fixArr[n]=arr[i];
            n++;
        }
    }
    //set the new size by the number of items that copied.
    newSize=n;
}
/*
enter up to 100  values, to stop enter 0:
5 6 4 5 2 3 5 6 2 0
the new vector is:
5 6 4 2 3
number of elements:5
*/

