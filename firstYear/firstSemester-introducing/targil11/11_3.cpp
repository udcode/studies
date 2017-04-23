//this cose get an array and sort it using selection sort recursivly
#include <iostream>
using namespace std;

/**
 * @brief swap Swap tow numbers in array
 * @param arr The array to swap
 * @param a Index to swap
 * @param b Index to swap
 */
void swap(int* arr, int a , int b);
/**
 * @brief smallest Find the index of the smallest number in array
 * @param arr The array
 * @param size The size of the array
 * @return  the index of the smallest number
 */
int smallest(int * arr, int size);
/**
 * @brief sort Sort the array using selection sort
 * @param arr The array to sort
 * @param size The size of the array
 */
void sort(int * arr , int size);

int main()
{
    int * arr;
    int num;
    do {//get the size of the array. chek for positive number
        cout << "enter a number:"<<endl;
        cin >> num;
        if (num<=0)
            cout << "ERROR" << endl;
    } while (num<=0);

    arr = new int[num];
    cout << "enter array values: ";
    //get the array
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    //print the array before sorting
    cout << "before: \n";
    for(int i= 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    //sort
    sort(arr, num);
    //print the array after sorting
    cout << "after: \n";
    for(int i= 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
void swap(int* arr, int a, int b){
    //swap
        int temp = arr[a];
        arr[a]= arr[b];
        arr[b] = temp;
}

int smallest(int *arr, int size){
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

void sort(int *arr, int size){
    if (size==0){//the end of the array
        return;
    }
    //find the smallest number
    int small = smallest(arr,size);
    //swap the smallest to the first index of the array
    swap(arr,small,0);
    //sort recursivly. increas the array start pointer
    sort(arr+1,size-1);

}
/*
enter a number:
10
enter array values: 2 5 8 7 4 5 6 1 4 5
before:
2 5 8 7 4 5 6 1 4 5
after:
1 2 4 4 5 5 5 6 7 8
*/

