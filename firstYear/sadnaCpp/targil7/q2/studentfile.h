#ifndef __STUDENTFILE_H
#define __STUDENTFILE_H

#include<fstream>
#include<iostream>
#include<string>
#include "student.h"
using namespace std;

class  StudentFile{
	string fileName;
	fstream* fileHendler;
    bool error;
    
    //write student in the number place. i used number for empty student to copy
    void writeStudent(Student& student);
    void readStudent(Student& student,int number);

public:
	int getLastStudentId();
    StudentFile();
    StudentFile(string fname);
    StudentFile(StudentFile& rhs)=delete;
    StudentFile(StudentFile&& rhs);
    StudentFile& operator =(StudentFile& rhs)=delete;
    StudentFile& operator =(StudentFile&& rhs);

	string getFileName();
	fstream* getFileHendler();
	void setFileName(string fname);
	void checkFile(string name);
	void setFileHendler(fstream * fhendler);
    void addStudent(Student& student);
    void delStudent(int id);
    void assignStudentCourse(int id, int numCourse);
    bool checkStudentCourse(int id, int numCourse);
    void printStudent(int id);
    void printStudent(Student& student);
	void printStudentWithCourses();
	void printStudentsAtCourse(int course);
friend StudentFile operator +(const StudentFile& lhs,const StudentFile& rhs);
    bool operator !();

    friend ostream & operator<<(ostream & out, const Student & student);
~StudentFile();


};
StudentFile operator +(const StudentFile& lhs, const StudentFile&rhs);
ostream & operator<<(ostream & out,const  Student & student);
#endif // __STUDENTFILE_H
