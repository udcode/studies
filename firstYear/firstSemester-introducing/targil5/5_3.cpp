//yudi noiman
//id: 301759692
//this code get ID number and print the ID with the check digit

#include <iostream>
using namespace std;

/**
    Returns the sum of digits.
    @param number The number to calculate.
    @return the sum of the digits.
*/
int sumOfDigits(int number);
/**
    Returns the check digit of the ID.
    @param id The id number.
    @return the check digit of the ID.
*/
int checkDigitOfId(int id);

int main()
{
    int id;
    cout<<"enter your ID:"<<endl;
    //get number form the user check for the correct range.
    do{
        cin>>id;
        if(id<0||id>100000000){
            cout<<"ERROR"<<endl;
        }

    }while(id<0||id>100000000);

    cout<<"your full ID is:"<<endl;
    //print the full id
    cout<<(id*10+checkDigitOfId(id))<<endl;
    return 0;
}



int sumOfDigits(int number){
    int sumOfDigits=0;
    //calulate the sum of the numbers.
    while (number>0){
        sumOfDigits += number%10;
        number = number/10;
    }
    return sumOfDigits;
}

int checkDigitOfId(int id){
    int checkDigit,sumOfProducts=0;

    //loop for every digit and calculate the sum of the product
    for(int i=8;i>0;--i){
        int weightOfDigit;
        int digit= id%10;
        if(i%2==0){
            weightOfDigit=2;
        }else{
            weightOfDigit=1;
        }
        sumOfProducts = sumOfProducts + sumOfDigits(digit*weightOfDigit);
        id = id/10;
    }
    //correct the check digit for 10 to be 0
    if(sumOfProducts%10==0){
        checkDigit =0;
    }else{
        checkDigit =10- (sumOfProducts%10);
    }
    return checkDigit;
}
/*
  enter your ID:
30564513
your full ID is:
305645137
*/

