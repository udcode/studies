//yudi noiman
//id: 301759692
//this code print the area of rectangle by given width and length
// and print the erea of circle by given radius

#include <iostream>
using namespace std;

//set the pi value
const double PI = 3.14159;

/**
    Returns the area of a rectangle by the width and length.
    @param width The width of the rectangle.
    @param length The length of the rectangle.
    @return The area of the rectangle.
*/
int area( int width , int length){
    return(width*length);
}
/**
    Returns the area of a circle by the radius.
    @param radius The radius of the circle.
    @return The area of the circle.
*/
double area( int radius ){
    return(radius*radius*PI);
}
int main()
{
    int width,lenght,radius;

    cout <<"enter length and width of the rectangle:"<<endl;
    //get the width and the lenght from the user and check if the number is positive
    do{
        cin>>width>>lenght;
        if(width<=0||lenght<=0){
            cout<<"ERROR"<<endl;
        }
    }while(width<=0||lenght<=0);
    //print the erea
    cout<<area(width,lenght)<<endl;

    //get the radius  from the user and check if the number is positive
    cout <<"enter radius of the circle:"<<endl;
    do{
        cin>>radius;
        if(radius<=0){
            cout<<"ERROR"<<endl;
        }
    }while(radius<=0);
    //print the erea
    cout<<area(radius)<<endl;

    return 0;
}
/*
enter length and width of the rectangle:
2 4
8
enter radius of the circle:
1
3.14159
*/

