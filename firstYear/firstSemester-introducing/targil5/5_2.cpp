//yudi noiman
//id: 301759692
//this code print list of perfect numbers by given number from the user
//and to 500

#include <iostream>
using namespace std;

/**
    Returns if number is perfect.
    @param n The number to check.
    @return if the number is perfect.
*/
bool perfect(int number);
/**
    Print perfect numbers by given number
    @param n number to print to. default is 500
*/
void printPerfectNumbersByNumber(int number =500);

int main()
{
    int number;
    cout<<"enter a number:"<<endl;
    //get number from the user to print to. check for positive number
    do{
        cin>>number;
        if(number<=0){
            cout<<"ERROR"<<endl;
        }
    }while(number<=0);

    //print perfect numbers by the user number
    printPerfectNumbersByNumber(number);
    //print perfect numbers by the default number
    printPerfectNumbersByNumber();

    return 0;
}
bool perfect(int number){
    bool isPerfect;
    int sumOfDividers=0,resultOfDivide;

    //get the sum of the dividers
    for(int i=1;i<=number/2;++i){
        resultOfDivide=number/i;
        if(resultOfDivide*i==number){
            sumOfDividers+=i;
        }
    }
    //check if the sum of the deviders is equal to the number
    if(sumOfDividers==number){
        isPerfect=true;
    }else{
        isPerfect=false;
    }
    return isPerfect;
}
void printPerfectNumbersByNumber(int number){
    //loop over the numbers by n to find perfect numbers
    for(int i =1;i<number;i++){
        if(perfect(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
/*
enter a number:
7
6
6 28 496
*/

