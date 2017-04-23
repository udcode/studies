//yudi noiman
//id: 301759692
//this code get three numbers ant print the type of triangle
#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout<<"enter 3 numbers:"<<endl;
    cin>>a>>b>>c;
    //chek if it is a leagal triangle
    if((a+b)>c&&(a+c)>b&&(b+c)>a){
        //it is a leagal triangle check is type
        if(a==b&&b==c){
            cout<<"equilateral triangle"<<endl;
        }else if(a==b||a==c||c==b){
            cout<<"isosceles triangle"<<endl;
        }else{
            cout<<"scalene triangle"<<endl;
        }
    }else{
        cout<<"cannot form a triangle"<<endl;
    }
    return 0;
}
/*
enter 3 numbers: 
 3 4 5
scalene triangle
*/
