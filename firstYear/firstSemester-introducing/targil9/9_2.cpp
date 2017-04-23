//yudi noiman
//id: 301759692
//this code get a string from the user and revers evry word in it.
#include <iostream>
using namespace std;
/**
 * @brief reverse Revers evry word from the sentence
 * @param str The string to revers
 */
void reverse(char * str);

int  main(){
    char sentence[80];

    cout<<"enter a string: "<<endl;
    //get the string from the user
    cin.getline(sentence,80);
    cout<<"after reverse:"<<endl;
    //do the revers
    reverse(sentence);
    //print the reversed string
    cout<<sentence<<endl;
    return 0;
}
void reverse(char * str){
    while(*str){//move until the NULL
        if(*str!=' '){//it a new word
            //get pointer to the first char
            //and for the last char of the word
            char * firstPtr = str;
            char *lastPtr= NULL;//nullptr
            while(*str!=' '&&*str){//go to the end of the word
                ++str;
            }
            lastPtr=--str;
            //do the switch
            while(firstPtr<=lastPtr){//move form both sides until the end
                //swap them
                char tmp= *firstPtr;
                *firstPtr=*lastPtr;
                *lastPtr=tmp;
                //move
                ++firstPtr;
                --lastPtr;
            }
        }
        ++str;
    }
}

