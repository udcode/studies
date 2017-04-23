//yudi noiman
//id: 301759692
//this code get two arrays and
//print the number of the shows of the second arry in the first arry

#include <iostream>
using namespace std;

//the size of the array
const int SIZE_VECTOR1 =500;
const int SIZE_VECTOR2 =100;

int main()
{
    //set the variables
   int vector1 [SIZE_VECTOR1];
   int vector2 [SIZE_VECTOR2];
   int realSizeVector1,realSizeVector2;
   int counter=0;

   //get the size of the first array from the user
   cout<<"enter size of first array:"<<endl;
   do{
       //check for size in range
        cin>> realSizeVector1;
        if(realSizeVector1>SIZE_VECTOR1||realSizeVector1<0){
            cout<<"ERROR"<<endl;
        }
   }while(realSizeVector1>SIZE_VECTOR1||realSizeVector1<0);

   //get the first array from the user
   cout<<"enter first array values:"<<endl;
   for(int i=0;i<realSizeVector1;++i){
       cin>>vector1[i];
   }

   //get the size of the second array from the user
   cout<<"enter size of second array:"<<endl;
   do{
       //check for size in range
        cin>> realSizeVector2;
        if(realSizeVector2>SIZE_VECTOR2||realSizeVector2<0){
            cout<<"ERROR"<<endl;
        }
   }while(realSizeVector1>SIZE_VECTOR2||realSizeVector1<0);

   //get the second array from the user
   cout<<"enter second array values:"<<endl;
   for(int i=0;i<realSizeVector2;++i){
       cin>>vector2[i];
   }

   //check for shows of the second array in the first array
   for(int i=0;i<realSizeVector1;++i){
       //check for the first number from the second array in the first
       if(vector1[i]==vector2[0]){
           bool match=true;
           //check for the all array
           for(int j =0;j<realSizeVector2;++j){
               if(vector1[i+j]!=vector2[j]){
                   match=false;
               }
           }
           //if there is a match add one to the counter
           if(match){
               counter ++;
           }
       }
   }
   //print the result
   cout<<"result: "<<counter<<" times"<<endl;

   return 0;
}
/*
enter size of first array:
18
enter first array values:
6 5 4 3 2 1 6 5 4 3 2 1 6 5 4 3 2 1
enter size of second array:
4
enter second array values:
5 4 3 2
result: 3 times
*/

