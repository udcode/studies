//this code an array and find the smallest number in it using recursive function
#include <iostream>
using namespace std;
/**
 * @brief smallest Get the index of the smallest number in the array
 * @param arr Pointer to the array
 * @param size The size of the array
 * @return
 */
int smallest(int * arr, int size);

int main(){
    int * array;
    int num;
    do {// get the size of the array. check for positive number
        cout << "enter a number:"<<endl;
        cin >> num;
        if (num<=0)
            cout << "ERROR" << endl;
    } while (num<=0);

    array = new int[num];
    cout << "enter array values: ";
    //get the array from the user
    for(int i = 0; i < num; i++)
        cin >> array[i];
    //print the smallest number
    cout << "the smallest is: " << array[smallest (array,num)]<< endl;
    return 0;
}
int smallest(int * arr, int size){
    if(size==1){//end case
       return 0;
    }else {
        //get the minimum case
        int min = smallest(arr,size-1);
        //check how is bigger
        if(arr[size-1]<arr[min]){
            return size-1;
        }else{
            return min;
        }
    }
}
/*
enter a number:
8
enter array values: 5 6 9 7 4 2 1 7
the smallest is: 1
*/

