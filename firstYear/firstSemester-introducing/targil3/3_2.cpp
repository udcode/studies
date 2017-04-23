//yudi noiman
//id: 301759692
//this code take 3 numbers and print if the last number is in the range of the 2 numbers before
#include <iostream>
using namespace std;

int main()
{
    int first,last,number;
    cout<<"enter 3 numbers:"<<endl;
    //get 3 numbers from the user
    cin >>first>>last>>number;
    //check if the number is in the range
    if(number>=first&&number<=last){
        cout<<"between"<<endl;
    }else if(number<first){
              cout<<"smaller"<<endl;
    }else{
        cout<<"bigger"<<endl;
    }
    return 0;
}
/*
enter 3 numbers:
3  9 7
between
*/
