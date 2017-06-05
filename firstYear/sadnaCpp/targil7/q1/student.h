#ifndef __STUDENT_H
#define __STUDENT_H

struct Student{
    int id;
    char firstName[20];
    char lastName[20];
    char courses[5];
    Student(int id,char *firstName ,char * lastName);
    static Student emptyStudent;

};


#endif //__STUDENT_H
