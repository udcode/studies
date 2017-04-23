//yudi noiman
//id: 301759692
//this code get three arrays from the user and print the marge between them
#include <iostream>
using namespace std;

//the size of the array
const int SIZE =10;
/**
 * @brief fillArray fill an array with numbers from the user, stop with 0 or size. fill top down
 * @param arr the array to fill
 * @param size the size of the array
 * @param realSize the actual size of the array
 */
void fillArray(int arr[],int size,int &realSize);
/**
 * @brief margeArrays marge two arrays into third one, top down.
 * @param margeArr the array to marge into.
 * @param arr1 the first array.
 * @param arr2 the second array.
 * @param size1 the size of first array.
 * @param size2 the size of the second array.
 */
void margeArrays(int margeArr[], int arr1[], int arr2[], int size1, int size2);
int main()
{
    //declare variables
    int arr1[SIZE];
    int arr2[SIZE];
    int arr3[SIZE];
    int margedArray1[SIZE*2];
    int finalMargedArray[SIZE*3];
    int realSize[3];

    //fill the arrays, and get back the actual size of the array
    cout<<"enter values for the first vector:"<<endl;
    fillArray(arr1,SIZE,realSize[0]);
    cout<<"enter values for the second vector:"<<endl;
    fillArray(arr2,SIZE,realSize[1]);
    cout<<"enter values for the third vector:"<<endl;
    fillArray(arr3,SIZE,realSize[2]);

    //marge the first and the second into margedArray1
    margeArrays(margedArray1,arr1,arr2,realSize[0],realSize[1]);
    //marge the third and the margedArray1 into finalMargedArray
    margeArrays(finalMargedArray,margedArray1,arr3,realSize[0]+realSize[1],realSize[2]);
    //print the marged array
    cout<<"merged vector is:"<<endl;
    for(int i=0;i<realSize[0]+realSize[1]+realSize[2];++i){
        cout << finalMargedArray[i]<<" ";
    }
    cout<<endl;
    return 0;

}
void margeArrays(int margeArr[], int arr1[], int arr2[], int size1, int size2){
    //hold the index of the margeArr
    int index=0,index1=0,index2=0;
    //move over the arrays until one of them reach the end
    while(index1<size1&&index2<size2){
        //check which is bigger
        //if the first bigger then the second
        if(arr1[index1]>=arr2[index2]){
            //set the first into the marged
            margeArr[index]=arr1[index1];
            //increase the first index
            index1++;
        }else {
            //set the second into the marged
            margeArr[index]=arr2[index2];
            //increase the second index
            index2++;
        }
        //increase the marged index
        index++;
    }
    //copy the left numbers
    if(index1<size1){
        //copy the left from the first array
        for(int i =index1;i<size1;++i){
            margeArr[index]=arr1[i];
            //increase the marged index
            index++;
        }
    }else{
        for(int i =index2;i<size2;++i){
            //copy the left from the second array
            margeArr[index]=arr2[i];
            //increase the marged index
            index++;
        }
    }

}

void fillArray(int arr[],int size,int &realSize){
    bool isCorrect;
    int counter ;
    //get numbers
    do{
        isCorrect=true;
        //get the first number, if it is 0 set the counter to zero
        cin>>arr[0];
        if(arr[0]==0){
            counter=0;
        }else{
            counter=1;
        }
        //get the numbers until size or zero
        for(int i=1;i<size&&arr[i-1]!=0;++i){
            cin>>arr[i];
            if(arr[i]>=arr[i-1]){
                //if the current number is bigger from the last one set error
                isCorrect=false;
                cout<<"ERROR"<<endl;
            }
            if(arr[i]!=0){
                counter++;
            }
        }
    }while(!isCorrect);//if there is an error get the number from start
    realSize=counter;//set the real size to be as the counter
}
/*
 * enter values for the first vector:
4 2 0
enter values for the second vector:
5 4 3 3 0
ERROR
5 23 0
ERROR
4 3 0
enter values for the third vector:
7 6 5 4 3 2 1 0
merged vector is:
7 6 5 4 4 4 3 3 2 2 1
*/

