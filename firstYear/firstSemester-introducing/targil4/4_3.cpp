//yudi noiman
//id: 301759692
//tihs code get number and print the fibonacci-sequence by the number
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout<<"enter a number:"<<endl;
    //get a positive number
    do{
        cin >>n;
        if (n<0){
            cout <<"ERROR"<<endl;
        }
    }while(n<0);

    //print the sequence
    if(n!=0){
        cout<<0<<" "<<1;
        if(n>1){
            int first=0,second=1;
            for(int i=0;i<n-1;i++){
                int a= first+second;
                cout<<" "<<a;
                first =second;
                second=a;
            }
        }
    }else{
        cout<<0;
    }
    cout<<endl;
    return 0;
}
/*
enter a number:
9
0 1 1 2 3 5 8 13 21 34
*/


