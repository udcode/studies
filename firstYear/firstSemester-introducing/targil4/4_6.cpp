//yudi noiman
//id: 301759692
//this code get number and print if his digits are smaller form eachother with one.
//from left to right
#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isSmaller =false;

    cout<< "enter a number:"<<endl;
    //get number from the user. check if it is positive number
    do{
        cin>>n;
        if(n<0){
            cout<<"ERROR"<<endl;
        }
    }while(n<0);

    //check if ther is two numbers that the right number is bigger then the left.
    //or if the right number is smaller more then one
    while(n>9&&!isSmaller){
        int rightNumber = n % 10;
        n /= 10;
        int leftNumber = n%10;
      if(rightNumber>leftNumber||rightNumber+1<leftNumber){
            isSmaller=true;
      }
    }
    //print if is smaller NO
    if(isSmaller){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    cout<<endl;

    return 0;
}

/*
enter a number:
9876
YES
*/

