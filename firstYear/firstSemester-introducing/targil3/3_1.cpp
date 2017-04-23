//yudi noiman
//id: 301759692
//this code get number and print if the digits are odd or even
#include <iostream>
using namespace std;

int main()
{
    int num;
    int tens,digits;
    cout<<"enter a number:"<<endl;
    //get the number from the user
    cin>>num;
    //divide the number to tens and digits
    tens = num/10;
    digits =num%10;
    //check if the number between 0 to 100
    if(num<100&&num>0){
        //if the tens and the digits are even
        if((((tens%2)==0)&&((digits%2)==0))||((num<10)&&(num%2==0))){
            cout<<"even digits only"<<endl;
            cout<<(tens*digits)<<endl;
            //if the tens and the digits are odd
        }else if((((tens%2)==1)&&((digits%2)==1))||((num<10)&&(num%2==1))){
            cout<<"odd digits only"<<endl;
            cout<<(tens+digits)<<endl;
            //if the tens and the digits are mixed
        }else{
            cout<<"mixed number"<<endl;
        }
    }else{
        //if the number not in the range print error
        cout<<"ERROR"<<endl;
    }
    return 0;
}

/*
enter a number:
19
odd digits only
10
*/

