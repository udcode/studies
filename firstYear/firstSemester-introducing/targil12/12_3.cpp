//yudi noiman
//id: 301759692
//this code check which file have the highest avg
#include <iostream>
#include <fstream>
#include <cstdlib>//for old gcc
using namespace std;

/**
 * @brief avgFile Avg of the numbers in the file
 * @param file File object
 * @return The avg
 */
double avgFile(ifstream &file);

int main(){
    int index=0;
    //declare array of files and avg
    ifstream grades [4];
    double avg [4];
    //open the files
    grades[0].open("grade1.txt");
    grades[1].open("grade2.txt");
    grades[2].open("grade3.txt");
    grades[3].open("grade4.txt");

    if(!grades[0]&&!grades[1]&&!grades[2]&&grades[3])//file not open
        return 1;

    //fill the avg of the files
    for(int i=0;i<4;++i){
        avg[i]=avgFile(grades[i]);
    }
    //find the highest avg
    for(int i=0;i<4;++i){
        if(avg[i]>avg[index]){
            index=i;
        }
    }
    //print the index
    cout<<"highest average found in file "<<index+1<<endl;

    //close the files
    grades[0].close();
    grades[1].close();
    grades[2].close();
    grades[3].close();

    return 0;
}
double avgFile(ifstream &file){
    int sum=0,count=0;
    int number;
    while(file>>number){//get numbers to the end
        sum+=number;
        ++count;
    }
    if(count>0)//avoid div by zero
        return (double(sum)/count);

    return 0.0;
}
/*
 highest average found in file 3
 */

