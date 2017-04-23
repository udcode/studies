//yudi noiman
//id: 301759692
//this code get two numbers and oparetor and calc them by the oparetor
#include <iostream>
using namespace std;

int main()
{
    int num1,num2;
    char op;
    cout<<"enter 2 numbers:"<<endl;
    //get 2 numbers from the user
    cin >>num1>>num2;
    //get the oparetor
    cout<<"enter an operator:"<<endl;
    cin >>op;
    //print the calc by the oparetor
    switch (op) {
    case '+':
        cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1+num2<<endl;
        break;
    case '-':
        cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1-num2<<endl;
        break;
    case '*':
        cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1*num2<<endl;
        break;
    case '/':
        if(num2!=0){
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<(float)num1/num2<<endl;
        }else{
            //print error when dividing by 0
            cout<<"ERROR"<<endl;
        }
        break;
    default:
        cout<<"ERROR"<<endl;
        break;
    }
    return 0;
}

