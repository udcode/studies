/*
    File: main.cpp
    Description: This is the  file for training use of string class from STL
    Course: 150018 C++ Workshop, Exercise 5, Question 1
    Student1: Avi margali 305645137
    Student2: Yeuda Nuiman 301759692
    Teacher: Dan Zilberstein
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    string sToAdd = "#!!@1234";//str to add
    int countWord=0;
    cout<<"insert 4 words:"<<endl;
    //get 4 words from the user in one line
    //check if it is more then 4 words
    do{
        countWord=0;
        getline (cin,line);//get the line from the user
        bool inSpace=true;
        for(int i=0;i<line.size();++i){//move over the line and count the words
            if(isspace(line[i])){//it is a space
                inSpace=true;
            }else if(inSpace){//avoid double spaces
                ++countWord;
                inSpace=false;
            }
        }
        if(countWord>4){//the line have more then 4 words
            cout<<"you enterd more the 4 word, try again."<<endl;//print massege
        }
    }while(countWord>4);//until the line have just 4 words

    //replace every space with *
    for(int i=0; i< line.size(); ++i) {//check every letter
           if(line[i] == ' ') {//replace space with *
               line[i] = '*';
           }
       }
    cout<<line<<endl;//print the new line

    //replace the last word with the sToAdd
    int pos=line.find_last_of('*');//get the position of the last word
    line.replace(pos+1,sToAdd.size(),sToAdd);//replace
    cout<<line<<endl;//print the new line

    //delete evry word
    int nextWord=0;
    while(nextWord!=string::npos){//till the last
        nextWord=line.find('*');//get the start of the next word
        if(nextWord==string::npos){//the last word
            line.erase(line.begin(),line.end());//delete evrything
            cout<<line<<endl;//print the new line
            break;
        }
        line.erase(0,nextWord+1);//delete the word
        cout<<line<<endl;//print the new line
    }

   return 0;
}
