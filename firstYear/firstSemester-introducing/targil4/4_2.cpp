//this code get two positive numbers and list of numbers in a loop
//and print the sum of them.
//the loop stop either the sum of the list is bigger then the first number
//or the number of the numbers is equel to the first number

#include <iostream>
using namespace std;

int main()
{
    int num1=0;
    int num2=0;
    int sumList=0;
    int input;

    cout<<"enter 2 positive numbers:"<<endl;

    //get the first number. if the number is negative,
    //print error and get another number
    do{
        cin>>num1;
        if(num1<0){
            cout<<"ERROR"<<endl;
        }
    }while(num1<0);
    //get the seconde number. if the number is negative,
    //print error and get another number
    do{
        cin>>num2;
        if(num2<0){
            cout<<"ERROR"<<endl;
        }
    }while(num2<0);

    cout<<"enter a list of numbers:"<<endl;
    //get the list of numbers.
    //stop if the sum of the list is bigger then the first number
    //or if the number of the list numbers is equal to the seconde number
    int i=0;
    while (sumList <= num1 && i < num2)
        {
            cin >> input;
            sumList += input;
            i ++;
        }
    //print the sum of the list
    cout <<sumList<<endl;
    return 0;
}
/*
enter 2 positive numbers:
40 6
enter a list of numbers:
1 2 3 4 5 6
21
*/



