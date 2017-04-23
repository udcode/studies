//yudi noiman
//id: 301759692
//this code get tree numbers and print them in the correct order
#include <iostream>
using namespace std;
int main(){
    int num1, num2, num3, smallest, middle, biggest;
    cout << "enter 3 numbers: " << endl;
    cin >> num1 >> num2 >> num3;
    //find which number is bigger, smaller or middle
    if(num1>num2){
        if(num2>num3){
            biggest=num1;
            middle=num2;
            smallest=num3;
        }else{
            if(num1>num3){
                biggest=num1;
                middle=num3;
                smallest=num2;
            }else{
                biggest=num3;
                middle=num1;
                smallest=num2;
            }
        }
    }else{
        if(num1>num3){
            biggest=num2;
            middle=num1;
            smallest=num3;
        }else{
            if(num3>num2){
                biggest=num3;
                middle=num2;
                smallest=num1;
            }else{
                biggest=num2;
                middle=num3;
                smallest=num1;
            }
        }
    }
    //print the number in the right order
    cout << smallest << " " << middle << " " << biggest << endl;
    return 0;
}
/*
enter 3 numbers:
2 9 4
2  4 9
*/

