//this cose get an array and print it in reverse order using recursive function
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
 * @brief reverse Revers an array recurasively
 * @param arr The array to revers
 * @param size The size of the array
 */
void reverse(int * arr , int size);

int main(){
    int * arr;
    int num;
    //get the size of the array
    cout << "enter a number: ";
    cin >> num;
    arr = new int[num];
    //get the array fromt the user
    cout << "enter array values: ";
    for(int i = 0; i < num; i++)
        cin >> arr[i];

    //print the array before the reverse
    cout << "before: \n";
    for(int i= 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    //revers
    reverse(arr, num);
    //print the reversed array
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


void reverse(int * arr , int size){
    if(size<=0){//stop at 0 or smaller
        return;
    }
    //swap the first with the last
    swap(arr,0,size-1);
    //call to reverse with short array.
    reverse(arr+1,size-2);
}
/*
enter a number: 7
enter array values: 9 8 5 4 2 3 5
before:
9 8 5 4 2 3 5
after:
5 3 2 4 5 8 9
*/

