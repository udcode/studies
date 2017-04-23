//yudi noiman
//id: 301759692
//this code get the month and print the numbers of days
#include <iostream>
using namespace std;
int main(){
    // enum of the month
    enum MONTH{JAN =1, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
    int num,numDays;
    cout << "enter a number:" << endl;
    cin>>num;
    //set the numbers of days to numDays
   if (num>0&&num<13){
        switch (num) {
        case JAN:
        case MARCH:
        case MAY:
        case JULY:
        case AUG:
        case OCT:
        case DEC:
            numDays =31;
            break;
        case FEB:
            numDays = 28;
            break;
        case APRIL:
        case JUNE:
        case SEPT:
        case NOV:
            numDays = 30;
            break;
        default:
            break;
        }
        cout<< numDays <<" days in the month"<<endl;
   }
    return 0;
}
/*
5
31
*/


