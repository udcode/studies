//this code read names and grades from files and write them in another file
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //open he files
    ifstream names("names.txt");
    ifstream grades("grades.txt");
    ofstream roster ("roster.txt");
    if(!names&&!grades&&!roster)
	return 1;
    bool isFirst=true;//count to know the first one
    char  name[50] ;
    char  grade[50];
    //read the first lines
    names.getline(name,50);
    grades.getline(grade,50);
    //copy the names and grades to roster file
    while(!names.eof()&&!grades.eof()){//as long as they have text in them
        if(!isFirst){//not the first line
            roster<<endl;//write new line *before* the new line
        }
        //copy the line
        roster<<name<<" "<<grade;
        //get new line
        names.getline(name,50);
        grades.getline(grade,50);

        isFirst=false;
    }
    //print the remaining names
    isFirst=true;
    while(!names.eof()){
        if(isFirst)//first line
            cout<<"finished reading grades before names"<<endl;

        cout<<  name<<endl;
        names.getline(name,50);
        isFirst=false;
    }
    //print the remaining grades
    isFirst=true;
    while(!grades.eof()){
        if(isFirst)//first line
            cout<<"finished reading names before grades"<<endl;
        cout<<  grade<<endl;


        grades.getline(grade,50);
        isFirst=false;

    }
    //close the connection
    names.close();
    grades.close();
    roster.close();
    return 0;
}
/*
finished reading grades before names
Shaul
Hannar
*/
