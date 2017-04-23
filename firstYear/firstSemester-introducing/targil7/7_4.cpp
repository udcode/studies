//yudi noiman
//id: 301759692
//this code get 10 words from the user and sort them with bubble sort algorithem
#include <iostream>
#include <cstring>
using namespace std;

//the size of the arrays
const int WORDS =10;
const int LETTERS =5;
/**
 * @brief bubbleSort do the buuble sort on words
 * @param arr the array of words
 * @param size the number of words
 * @param wordSize the word length
 */
void bubbleSort(char arr[][LETTERS], int size, int wordSize);
/**
 * @brief strcmp compare two arrays of char
 * @param a first array
 * @param b second array
 * @param size the size of the word
 * @return  0 - the array are the same 1 - the first is bigger -1 the first is smaller
 */
//!!!! i'm not sure that i can't just using the cstring function *strcmp*,
//!  so i implement it

int strcmp(char *a, char*b, int size);


int main()
{
    //declare variables
    char matrix[WORDS][LETTERS];

    //get the words from the user
    cout<<"enter 10 words:"<<endl;
    for(int i =0;i<WORDS;++i){
        for(int j=0;j<LETTERS;++j){
            cin>>matrix[i][j];
        }
    }
    //sort the words
    bubbleSort(matrix,WORDS,LETTERS);
    //print the sorted list
    cout<<"after sorting:"<<endl;
    for(int i=0;i<WORDS;++i){
        for(int j =0 ;j<LETTERS;++j){
            cout<<matrix[i][j];
        }
        cout<<" ";
    }
    cout<<endl;

    return 0;

}
void bubbleSort(char arr[][LETTERS], int size, int wordSize){
    bool isSorted=false;
    //move over the array until is sorted
    while (!isSorted){
        isSorted=true;
        //move over the array and sort every two cells
        for(int i=0;i<size-1;++i){
            //check how is bigger
            int cmp= strcmp(arr[i],arr[i+1],wordSize);
            //if the first is bigger swap him
            if(cmp>0){
                char tmp[wordSize];
                // i used the strncpy, i'm not sure that i'm not supposed to implement it
                strncpy (tmp,arr[i],wordSize);
                strncpy(arr[i],arr[i+1],wordSize);
                strncpy(arr[i+1],tmp,wordSize);
                isSorted=false;
            }
        }
    }
}
int strcmp(char *a,char*b,int size){
    //check every letter how is bigger
    for(int i=0;i<size;++i){
        if(a[i]<b[i]){
            //return -1 for the first is smaller
            return -1;
        }else if(a[i]>b[i]){
            return 1;
            //return 1 for the first is bigger
        }
    }
    //they are the same
    return 0;
}
/*
 * enter 10 words:
house apple teach array teach books point float apply begin
after sorting:
apple apply array begin books float house point teach teach
*/

