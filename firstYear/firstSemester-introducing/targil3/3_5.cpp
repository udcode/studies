//yudi noiman
//id: 301759692
//this code get date in d/m/yy formate from the 20th and print the day in a week
#include <iostream>
using namespace std;

int main()
{
    int year,month,day;
    int dayInWeek ;
    char helpChar;
    int b,c,d,e,f ;
    cout<<"enter a date:"<<endl;
    cin >>day>>helpChar>>month>>helpChar>>year;

    //calculate the day by the month and the year
     b = year/4;
     c = year+b;
    switch (month) {
    case 1:
    case 10:
        d=1;
        break;
    case 2:
    case 3:
    case 11:
        d=4;
        break;
    case 4:
    case 7:
        d=0;
        break;
    case 5:
        d=2;
        break;
    case 6:
        d=5;
        break;
    case 8:
        d=3;
        break;
    case 9:
    case 12:
        d=6;
        break;
    default:
        cout<<"ERROR"<<endl;
        break;
    }
    e=d+c;
    f = day+e;
    dayInWeek =f%7;
    //print the day by the result
    switch (dayInWeek) {
    case 0:
        cout<<"Saturday"<<endl;
        break;
    case 1:
        cout<<"Sunday"<<endl;
        break;
    case 2:
        cout<<"Monday"<<endl;
        break;
    case 3:
        cout<<"Tuesday"<<endl;
        break;
    case 4:
        cout<<"Wednesday"<<endl;
        break;
    case 5:
        cout<<"Thursday"<<endl;
        break;
    case 6:
        cout<<"Friday"<<endl;
        break;
    default:
        cout<<"ERROR"<<endl;

        break;
    }
    return 0;
}
/*
enter a date:
17/8/44
Thursday
*/

