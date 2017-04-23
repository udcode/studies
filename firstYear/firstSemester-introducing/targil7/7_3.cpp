//yudi noiman
//id: 301759692
//this code get a matrix from the user, and print the matrix with top and bottom trianlge sorted,
//using insortion sort algorithem
#include <iostream>
using namespace std;

//the size of the arrays
const int SIZE =10;
const int HALF_SIZE =45;

/**
 * @brief splitMatrix split the matrix into two arrays by the triangle
 * @param matrix the matrix to split
 * @param topArr the top array
 * @param bottomArr the bottom array
 * @param size the size of the matrix
 */
void splitMatrix(int matrix[][SIZE], int topArr[], int bottomArr[], int size);
/**
 * @brief insertionSort do the insortion sort algorithem on given array
 * @param arr the array to sort
 * @param size the size of the array
 */
void insertionSort(int arr[], int size);

int main()
{
    //declare variables
    bool isCorrect;
    int matrix[SIZE][SIZE];
   int topArray[HALF_SIZE];
    int bottomArray[HALF_SIZE];

    //get the numbers from the user into the array
    cout<<"enter 100 numbers:"<<endl;
    do{
        //set the flag o be true
        isCorrect=true;
        //fill the matrix
        for(int i=0; i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                cin>>matrix[i][j];
                //check for positives numbers
                if(matrix[i][j]<=0){
                    isCorrect=false;
                    cout<<"ERROR"<<endl;
                }
            }
        }
    }while(!isCorrect);
    //split the matrix into two arrays
    splitMatrix(matrix,topArray,bottomArray,SIZE);
    //sort the top triangle
    insertionSort(topArray,HALF_SIZE);
    //sort the bottom triangle
    insertionSort(bottomArray,HALF_SIZE);

    //fill back the matrix with the sorted numbers
    int index=0;
    //fill the top triangle
    for(int i=0;i<SIZE;++i){
        for(int j=i+1;j<SIZE;++j){
            matrix[i][j]=topArray[index];
            index++;
        }
    }
    index=0;
    //fill the bottom triangle
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<i;++j){
            matrix[i][j]=bottomArray[index];
            index++;
        }
    }
    //print the sored matrix
    cout<<"sorted matrix:"<<endl;
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
void splitMatrix(int matrix[][SIZE], int topArr[], int bottomArr[], int size){
    //copy the top triangle into the top array
    int index=0;
    for(int i =0;i<size;++i){
        for(int j=i+1;j<size;++j){
            topArr[index]=matrix[i][j];
            index++;
        }
    }
    //copy the botom triangle into the bottom array
    index=0;
    for(int i =0;i<size;++i){
        for(int j=0;j<i;++j){
            bottomArr[index]=matrix[i][j];
            index++;
        }
    }
}
void insertionSort(int arr[], int size){
    //move over the array start with the second element
    for(int i=1;i<size;++i){
        int x = arr[i];
        int j = i - 1;
        //swap the elements until the end or until is sorted
        while (j >= 0 && arr[j] > x){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = x;
    }
}

/*
enter 100 numbers:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
sorted matrix:
1 11 21 22 31 32 33 41 42 43
2 12 44 51 52 53 54 55 61 62
3 4 23 63 64 65 66 71 72 73
5 6 7 34 74 75 76 77 81 82
8 9 10 13 45 83 84 85 86 87
14 15 16 17 18 56 88 91 92 93
19 20 24 25 26 27 67 94 95 96
28 29 30 35 36 37 38 78 97 98
39 40 46 47 48 49 50 57 89 99
58 59 60 68 69 70 79 80 90 100
*/

