//yudi noiman
//id: 301759692
//this code get an orderd array and number from the user
//and print the index of the number in the array using the binary search

#include <iostream>
using namespace std;

//the size of the array
const int SIZE =10;

/**
 * @brief binSearch it is a basic binary search on orderd array
 * @param arr[] the array to search in.
 * @param size the size of the array.
 * @param number the number to look in the array
 * @return the index of the founded number, or -1 if not found
 */
int binSearch(int arr[],int size,int number);

int main()
{
    //declare variables
    int arr[SIZE];
    int number,index;
    int lastNum;
    bool isCorrect;

    cout<<"enter 10 numbers:"<<endl;
    //get the array from the user
    //the array must be orderd down to top, if not print error and get from start
    do{
        isCorrect=true;
        cin>>arr[0];
        lastNum =arr[0];
        for(int i=1;i<SIZE;++i){
            cin>>arr[i];
            if(arr[i]<=arr[i-1]){
                isCorrect=false;
                cout<<"ERROR"<<endl;
            }
            lastNum=arr[i];
        }
    }while(!isCorrect);

    //get the number from user
    /**! i assumed that no need to check that numbe**/
    cout<<"enter 1 number:"<<endl;
    cin>>number;

    //do the search
    index= binSearch(arr,SIZE,number);
    //print the index of the number if found
    if (index>=0){
        cout<<"the number " <<number<<" was found at index "<<index<<endl;

    }else{
        cout<<"not found"<<endl;

    }


    return 0;

}

int binSearch(int arr[],int size,int number){
    //set the indexes of left right and middle
    int left=0, middle=size/2,right=size-1;
    //if our number is in the range
    if(number>=arr[left]&&number<=arr[right]){
        //go over the array until the right and left will move outside
        for(int i=0;left<=right;++i){
            if(arr[middle]==number){//we found our number
                return middle;
            }else{
                if(number>arr[middle]){//cut the left side
                    left=middle+1;
                }else{//cut the right side
                    right=middle-1;
                }
                //move to the new middle
                middle= left+(right-left)/2;
            }
        }
    }
    //if not found return -1
    return -1;
}

