//yudi noiman
//id: 301759692
//this code print 10 random numbers and print if they sorted or not
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int lastNumber=0;
    int minNumber =1;
    int maxNumber=1000;
    bool isSorted =true;

    srand(time(NULL));
    for(int i=0; i<10;i++){
        //get randome number in range of 1 to 1000
        int randNum = minNumber + (rand() % (maxNumber - minNumber + 1));
        //check if the last number is bigger then the new
        if(lastNumber>randNum){
            isSorted=false;
        }
        //print the number
        cout<<randNum<<" ";
       lastNumber= randNum;
    }
    cout<<endl;

    //print if is sorted list or not
    if(isSorted){
        cout<<"sorted list"<<endl;
    }else{
        cout<<"not sorted list"<<endl;
    }
    return 0;
}

/*
384 887 778 916 794 336 387 493 650 422
not sorted list
*/

