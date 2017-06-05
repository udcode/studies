/*
    File: Main.cpp
    Description: This is the (header) file for get 2 Poligon class and check if they equel
    Course: 150018 C++ Workshop, Exercise 6, Question 2
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include "Triangle.h"
#include "Rectangle.h"


void isPolyganEqual(Polygan& first,Polygan& second)//helpper function to check if the polygans created by user are equal
{
    if (second == first)//using the overloaded bool operator
    {
        cout << "equal" << endl;
    }
    else
    {
        cout << "not equal" << endl;
    }
}
int main()
{
    uint fSides,sSides;//setting two variables to hold the number of sides of the polygans
    uint size1, size2, size3;//setting three variables to hold the sizes of each side
    cout << "enter number of sides for polygan 1" << endl;//asking the user to enter the number of sides in the polygan
    cin >> fSides;
    if (fSides == 3)//if it is a triangle
    {
        cout << "enter sizes of Polygan" << endl;//asking the user to enter the sizes of the sides
        cin >> size1 >> size2 >> size3;
        Triangle first(size1, size2, size3);//creating the triangle
        cout << "enter number of sides for polygan 2" << endl;//asking the user to enter the number of sides of the second polygan
        cin >> sSides;
        if (sSides == fSides)//if the number of sides match
        {
            cout << "enter sizes of Polygan" << endl;//asking the user to enter the sizes of the sides
            cin >> size1 >> size2 >> size3;
            Triangle second(size1, size2, size3);//creating the triangle
            isPolyganEqual(first, second);//using the helper function to print the result
        }
        else
        {
            cout << "not equal" << endl;//if the number of sides does not equal
        }
    }
    else if(fSides==4)//if it is a rectangle
    {
        cout << "enter sizes of Polygan" << endl;//asking the user to enter the sizes of the sides
        cin >> size1 >> size2;
        Rectangle first(size1, size2);//creating the rectange
        cout << "enter number of sides for polygan 2" << endl;//asking the user to enter the number of sides of the second polygan
        cin >> sSides;
        if (sSides == fSides)//if the number of sides match
        {
            cout << "enter sizes of Polygan" << endl;//asking the user to enter the sizes of the sides
            cin >> size1 >> size2;
            Rectangle second(size1, size2);//creating the rectangle
            isPolyganEqual(first, second);//using the helper function to print the result
        }
        else
        {
            cout << "not equal" << endl;//if the number of sides does not equal
        }
    }
    else
    {
        Polygan pol1(fSides);//if it is nor a triangle or a rectangle use the polygan constructor to handle the creation
        cout << "enter number of sides for polygan 2" << endl;//asking the user to enter the number of sides of the second polygan
        cin >> sSides;
        if (sSides == fSides)//if the number of sides match
        {
            Polygan pol2(sSides);//using the polygan constructor to handle the creation
            isPolyganEqual(pol1, pol2);//using the helper function to print the result
        }
        else
        {
            cout << "not equal" << endl;//if the number of sides does not equal
        }
    }
    return 0;
}
