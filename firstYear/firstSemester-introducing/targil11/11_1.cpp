//this code print a and b n times using recursive function
#include <iostream>
using namespace std;
/**
 * @brief printABs print a and b n times using recursive
 * @param n Number of letters to print
 */
void printABs(int n);
int main(){
    int num;
    cout << "enter a number:"<<endl;
    //get the number from the user
    cin >> num;
    //print
    printABs(num);
    cout<<endl;
    return 0;
}
void printABs(int n){
    if(n==0){//end of the calls
        return;
    }
    //first letter
    cout<<"a";
    //call to function with n-1 to print all the letters
    printABs(n-1);
    //sec letter
    cout<<"b";
}

