
#include <iostream>

#include "studentfile.h"
#include "student.h"
using namespace std;
//menu options
enum Action {
    STOP,
    CREATE_FILE,
    INSERT_STUDENT,
    DELETE_STUDENT,
    ADD_STUDENT_TO_COURSE,
    CHECK_STUDENT_IS_IN_COURSE,
    PRINT_STUDENT,
    PRINT_STUDENT_WITH_COURSES,
    PRINT_STUDENT_BY_COURSE,
    MERGE_FILES
};

Action menu() {//function that return a menu enum
    cout<<"choose option:"<<endl;
	cout <<"0: quit the program" << endl;
    cout<<"1: create file"<<endl;
    cout<<"2: insert student"<<endl;
    cout<<"3: delete student"<<endl;
    cout<<"4: add student to course"<<endl;
    cout<<"5: check if student assign to course"<<endl;
    cout<<"6: print student details"<<endl;
    cout<<"7: print students assinged to courses"<<endl;
    cout<<"8: print students by course"<<endl;
    cout<<"9: merge two files"<<endl;
    int x;
    cin >> x;
    return (Action)x;//casting the x to the enum equivalent to the number inputed by user
}

int main() {
    StudentFile fileHandler;
    string fileName;
    Student student(0,"","");
    int id=0,course=0;
    Action ac = menu();
    while (ac) {
        switch (ac) {
        case CREATE_FILE:
            cout<<"enter file name:"<<endl;
            cin>>fileName;
            fileHandler.checkFile(fileName);
            if(!fileHandler)
                cerr<<"failed to create the file"<<endl;
            break;
        case INSERT_STUDENT:
            cout<<"insert student details (id firstname lastname)"<<endl;
            cin>>student;
            ///cout>>student;
            //FIXME : after solving bug in output
            fileHandler.addStudent(student);
            fileHandler.printStudent(student);
            if(!fileHandler)
                cerr<<"failed to add student"<<endl;
            break;
        case DELETE_STUDENT:
            cout<<"insert student id:"<<endl;
            cin>>id;
            fileHandler.delStudent(id);
            if(!fileHandler)
                cerr<<"failed to delete student"<<endl;
            break;
        case ADD_STUDENT_TO_COURSE:
            cout<<"insert student id and course number (1-5):"<<endl;
            cin>>id>>course;
            fileHandler.assignStudentCourse(id,course);
            if(!fileHandler)
                cerr<<"failed to assign course to student"<<endl;
            break;
        case CHECK_STUDENT_IS_IN_COURSE:

            break;
        case PRINT_STUDENT:
            cout<<"insert student id:"<<endl;
            cin>>id;
            fileHandler.printStudent(id);
            if(!fileHandler)
                cerr<<"failed to print student"<<endl;
            break;
        case PRINT_STUDENT_WITH_COURSES:
			fileHandler.printStudentWithCourses();
			if (!fileHandler)
				cerr << "failed to print students" << endl;
            break;
        case PRINT_STUDENT_BY_COURSE:
			cout << "insert course id:" << endl;
			cin >> id;
			fileHandler.printStudentsAtCourse(id);
			if (!fileHandler)
				cerr << "failed to print students" << endl;
            break;
        case MERGE_FILES:
			cout << "enter name of first file";
			cin >> fileName;
			StudentFile firstFile(fileName);
			cout << "enter name of second file";
			cin >> fileName;
			StudentFile second(fileName);
			StudentFile thirdfile = firstFile + second;
            break;

        }
        ac = menu();
    }

    return 0;
}
