//yudi noiman
//id: 301759692
//this code get two arrays of numbers and print the diffrent between them
//set1-set2=diff

#include <iostream>
using namespace std;

//the size of the array
const int SIZE =6;

/**
 * @brief fill the array with numbers from the user
 * @param arr[] the arry to fill
 * @param size the size of the arry
 */
void fillArray(int arr[],int size);
/**
 * @brief find if number is exsist in array of numbers
 * @param arr[] the array to check
 * @param size the size of the array
 * @param number the number to look in the array
 * @return true if number found in the array, false if not found
 */

bool isExist(int arr[],int size,int number);
int main()
{
    //declare variables
   int set1[SIZE];
   int set2 [SIZE];
   int difference[SIZE];


   //fill the array
   cout<<"enter first 6 numbers:"<<endl;
   fillArray(set1,SIZE);
   cout<<"enter next 6 numbers:"<<endl;
   fillArray(set2,SIZE);

   //fill the difference array
   int diffIndex=-1;
   for(int i =0 ;i<SIZE;++i){
       //check every number in set1 if he is exsist in set2
       //if not copy his value to the diff array
       if(!isExist(set2,SIZE,set1[i])){
           diffIndex++;
           difference[diffIndex]=set1[i];
       }
   }
   //print the diff array
   cout<<"set difference is:"<<endl;
    if(diffIndex==-1){//there is no diff
        cout<<"empty";
    }else{//print the diff array
        for(int i =0;i<=diffIndex;++i){
            cout<<difference[i]<<" ";
        }
    }
    cout<<endl;

   return 0;

   }
void fillArray(int arr[],int size){
    for(int i =0 ; i<size;++i){
        do{//fill the array, check for positive numbers
            cin>>arr[i];
            if(arr[i]<=0){
                cout<<"ERROR"<<endl;
            }
        }while(arr[i]<=0);
    }
}
bool isExist(int arr[],int size,int number){
    bool exist =false;
    //move over the array and if the number exist set true to be return
    for(int i =0;i<size;++i){
        if(arr[i]==number){
            exist=true;
        }
    }
    return exist;
}

/*
enter first 6 numbers:
1 2 3 5 8 9
enter next 6 numbers:
5 8 9 10 11 12
set difference is:
1 2 3
*/

