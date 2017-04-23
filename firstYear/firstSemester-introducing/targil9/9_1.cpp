//yudi noiman
//id: 301759692
//this code crypt a string from the user by 'azby' algorithm
//a==z b==y etc.

#include <iostream>
#include <cstring>
using namespace std;
/**
 * @brief crypto Encrypt the str by the 'azby' algorithm
 * @param str Pointer to the string
 */
void crypto ( char *str);

int  main(){
    //set new array of char (size 80)
    char  str[80];

    cout<<"enter a string:"<<endl;
    //get the string from the user

    cin.getline(str,80);
    //for moodle
    int l = strlen(str);
    str[l]='\0';
    cout<<"after crypto:"<<endl;
    //print the crypt string
    crypto(str);
    cout<<str<<endl;

    return 0;
}
void crypto ( char* str){
    while(*str){//move to the 0
        //get the char
        char c =*str;
        if(c>=97&&c<=122){//the char is a lower-case letter
            //set the char to be the crypto char
           *str=122-(c-97);
        }
        //move to the next char
        str++;
    }
}
/*
enter a string:
b>?klkjfFza
after crypto:
y>?popquFaz
*/

