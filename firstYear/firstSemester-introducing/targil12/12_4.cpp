//yudi noiman
//id: 301759692
//this code take file with students details and print their details
#include <iostream>
#include <fstream>
#include <cstdlib>//for old gcc
using namespace std;
/**
 * @brief getStudentDetails Read the file and copy the details to the student arry
 * @param file Name of the file
 * @return The number of students
 */
int getStudentDetails(const char *file);
/**
 * @brief print Print the student array
 * @param numStudents The number of the students
 */
void print(int numStudents);

struct Student
{
    int id;
    char name[25];
    int mark;
};
//global array
Student studentArr[50];

int main(){
    //do the copy and get the number of students
    int numStudents =getStudentDetails("data.txt");
    //print the data
    print(numStudents);
    return 0;
}
int getStudentDetails(const char * file){
    int count=0;
    //open the file
    ifstream fileStudents(file);
    if(!fileStudents)//fail to open
        exit(1);
    while(!fileStudents.eof()){//read to the end
        if(fileStudents.eof())//the file ended
            break;
        //insert the data to the array of student
        fileStudents>>studentArr[count].id>>studentArr[count].name>>studentArr[count].mark;
        ++count;
    }
    //close the file
    fileStudents.close();
    return count;
}
void print(int numStudents){
    //print the array of students
    for(int  i=0;i<numStudents;++i){
        cout<<"name: "<<studentArr[i].name<<" id: "<<studentArr[i].id<<" mark: "<<studentArr[i].mark<<endl;
    }
}
/*
name: Elkana id: 1234 mark: 100
name: Chana id: 5678 mark: 90
name: Penina id: 9090 mark: 80
name: Eli id: 6868 mark: 70
name: Shmuel id: 4321 mark: 60
*/

