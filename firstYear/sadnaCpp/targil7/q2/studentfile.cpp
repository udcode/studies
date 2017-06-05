#include "studentfile.h"
#include "initfile.h"

StudentFile::StudentFile() :fileName(""), fileHendler(nullptr),error(false) {}

StudentFile::StudentFile(string fname) :fileName(fname), fileHendler(nullptr),error(false) {
    fileHendler = new fstream(fname,fstream::in | fstream::out |fstream::binary);
    if (!fileHendler)error=true;/*throw "file was not found";*/
	fileHendler->close();

}
StudentFile::~StudentFile() {
	if (fileHendler->is_open()) {
		fileHendler->close();
	}
	delete fileHendler;
	fileHendler = nullptr;
}
StudentFile::StudentFile(StudentFile &&rhs) {
	fileName = rhs.getFileName();
	fileHendler = rhs.getFileHendler();
	rhs.setFileHendler(nullptr);
	rhs.setFileName("");
}
string StudentFile::getFileName() {
	return fileName;
}
fstream* StudentFile::getFileHendler() {
	return fileHendler;
}
void StudentFile::setFileName(string fname) {
	fileName = fname;
}
void StudentFile::checkFile(string name) {//??? whats that func ??
    error=false;
    if(fileHendler!=nullptr)return;//no nedd to create file
    fileHendler = new fstream(name,fstream::in | fstream::out | fstream::trunc|fstream::binary);
	fileName = name;
    if (!fileHendler)error=true;/*throw "file was not found";*/
    //fstream checker(name);
    //if (!(checker))throw "file was not found";
    fileHendler->close();
}
void StudentFile::setFileHendler(fstream* fhendler) {
	fileHendler = fhendler;
}

StudentFile &StudentFile::operator =(StudentFile && rhs) {
	fileHendler = rhs.getFileHendler();
	fileName = rhs.getFileName();
	rhs.setFileHendler(nullptr);
	rhs.setFileName("");
	return *this;
}

void StudentFile::addStudent(Student & student) {
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName,fstream::binary|fstream::in|fstream::out);//open
	}
	int lastId = getLastStudentId();//TODO: check for empty file
    if (student.id <= 0){
        error=true;/*throw "not a valid id";*///not valid id
        return;
    }
	Student tmp(0, "", "");
	if (lastId >= student.id) {//the id is inside the file
		readStudent(tmp, student.id);
        if (tmp.id == student.id){
            error=true;/*throw "the place is taken by other student";*/
            return;
        }
		writeStudent(student);//write student
	}
	else {// the id is outside the file. we need to expend the file
		int numNewEntries = student.id - lastId;//how much place to extend
		//add new empty entries to the end of the file
		if (!fileHendler->is_open()) {
			fileHendler->open(fileName, fstream::binary | fstream::in | fstream::out);
		}
		fileHendler->seekp(ios::beg);
		fileHendler->write((char*)&student.id, sizeof(int));//adding the number of students to the begining of the file
		for (int i = 0; i < numNewEntries; ++i) {//add empty students to the end
			fileHendler->seekp(ios::end);//goto the end
			fileHendler->write((char*)&Student::emptyStudent, sizeof(Student));//write the student
		}
		writeStudent(student);//write the student
	}
	fileHendler->close();//close
}

void StudentFile::delStudent(int id) {
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
	int lastId = getLastStudentId();//TODO: check for empty file
	if (id > 0) {//is valid id
		Student tmp(0, "", "");
        if (lastId < id){
            error=true;/*throw "no such student";*///id is not in the range of the file
            return;
        }
            readStudent(tmp, id);
        if (tmp.id != id){//the ids are not the same. it is mean that we can delete it
//			throw "not the right student";
            error=true;
            return;
        }else {
			fileHendler->seekp((-1 * (int)sizeof(Student)), ios::cur);//go back
			fileHendler->write((char*)&Student::emptyStudent, sizeof(Student));//write the student
		}
	}
	fileHendler->close();//close
}

void StudentFile::assignStudentCourse(int id, int numCourse) {
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
    if (id <= 0){
        error=true;/*throw "not a valid id";*///not valid id
        return;
    }
    if (numCourse < 1 || numCourse>5){
        error=true;/*throw "not a valid course number";*///mot valid course num
        return;
    }
	Student tmp(0, "", "");
	readStudent(tmp, id);//read the id place
    if (tmp.id == 0){
        error=true;/*throw "no such student id";*///is empty id
        return;
    }
    if (tmp.courses[numCourse - 1] == 'Y'){
        error=true;/*throw "student already assigned to this course";*///no need to update
        return;
    }
        tmp.courses[numCourse - 1] = 'Y';
	fileHendler->seekp(-1 *(int) sizeof(Student), ios::cur);//go back
	fileHendler->write((char*)&tmp, sizeof(Student));//write the updated student
	fileHendler->close();//close
}

bool StudentFile::checkStudentCourse(int id, int numCourse) {
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return false;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
    if (id <= 0){
        error=true;/*throw "not a valid id";*///not valid id
        return false;
    }
    if (numCourse < 1 || numCourse>5){
        error=true;/*throw "not a valid course number";*///mot valid course num
        return false;
    }
	Student tmp(0, "", "");
	readStudent(tmp, id);//read the id place

	if (tmp.courses[numCourse - 1] == 'Y') {
		fileHendler->close();//close
		return true;//is assign to this course
	}
	fileHendler->close();//close
	return false;
}

void StudentFile::printStudent(int id) {
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
    if (id <= 0){
        error=true;/*throw "not a valid id";*///not valid id
    }
	Student tmp(0, "", "");
	readStudent(tmp, id);//read the id place
	printStudent(tmp);//print
	fileHendler->close();//close
}

void StudentFile::printStudent(Student &student) {
	//print details
	cout << "id: " << student.id << endl;
	cout << "first name: " << student.firstName << endl;
	cout << "last name: " << student.lastName << endl;
	cout << "courses: ";
	for (int i = 0; i < 5; ++i)
		cout << " " << student.courses[i];
	cout << endl;
}

void StudentFile::printStudentWithCourses(){
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
	Student temp(0, "", "");
	int numberOfStudents = this->getLastStudentId();//getting the number of students in the file
	for (int i = 0; i < numberOfStudents; ++i) {//going through the entire file to search for students to print
		readStudent(temp, i);//reading the student from the file
		for (int j = 0; j < 5; ++j) {//going through the courses to see if the student is attending one of them
			if (temp.courses[i] == 'y') {//if the student attend to a course
				printStudent(temp);//print the student information
				break;//break out of the courses array(no need to keep looking)
			}
		}
	}
	fileHendler->close();//closing the file
}

void StudentFile::printStudentsAtCourse(int course){
    error=false;
	//try to open
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName);//open
	}
	int numberOfStudents = this->getLastStudentId();//getting the number of students in the file
	for (int i = 1; i < numberOfStudents; ++i) {//going through the entire file to search for students to print
		if (checkStudentCourse(i, course))printStudent(i);
	}
	fileHendler->close();
}
StudentFile operator+(const StudentFile& lhs,const StudentFile & rhs)//overloading the add operator
{
	string tmepFileName = const_cast<StudentFile&>(lhs).getFileName() + const_cast<StudentFile&>(rhs).getFileName();//creating a unique name for the file
	initFile(const_cast<char*>(tmepFileName.c_str()));//creating a file with 10 empty students
	StudentFile tempfile(tmepFileName);//creating a studentFile maneger
	tempfile.getFileHendler()->open(tmepFileName, fstream::in | fstream::out);
	tempfile.getFileHendler()->seekp(ios::beg);//move the file pointer to the beggining of the file
	int sumOfElements = const_cast<StudentFile&>(lhs).getLastStudentId() + const_cast<StudentFile&>(rhs).getLastStudentId();//summing the number of elements
	tempfile.getFileHendler()->write((char*)&sumOfElements, sizeof(int));//writing the number of elements in the file
	//initializing 3 temp students
	Student temp(0, "", "");
	Student temp2(0, "", "");
	Student temp3(0, "", "");
	const_cast<StudentFile&>(lhs).getFileHendler()->open(const_cast<StudentFile&>(lhs).getFileName(), fstream::in | fstream::out);
	const_cast<StudentFile&>(rhs).getFileHendler()->open(const_cast<StudentFile&>(rhs).getFileName(), fstream::in | fstream::out);
	const_cast<StudentFile&>(lhs).getFileHendler()->seekg(sizeof(int));
	const_cast<StudentFile&>(rhs).getFileHendler()->seekg(sizeof(int));
	for (int i = 1; i <= sumOfElements; ++i) {//writing to the file in the corect position		
		const_cast<StudentFile&>(lhs).getFileHendler()->read((char *)&temp, sizeof(Student));//reading from the first file
        const_cast<StudentFile&>(rhs).getFileHendler()->read((char *)&temp2, sizeof(Student));//reading from the second file
		if (temp.id == i || temp2.id == i) {//if one of the student obj has a valid id(at the corrent index)
			if (temp.id == 0) { //if the first element is empty
				tempfile.getFileHendler()->write((char*)&temp2, sizeof(Student));//insert the one with the vaild id
				continue;
			}
			if (temp2.id == 0) {//if the second element is empty
				tempfile.getFileHendler()->write((char*)&temp, sizeof(Student));//insert the one with the vaild id
				continue;
			}
			if (temp2 > temp) {//if the student from the first file has a valid id and should be inserted first
					tempfile.getFileHendler()->write((char*)&temp, sizeof(Student));
					for (int j = 1; j < temp2.id - temp.id; ++j) {//filling the gap with empty students
						tempfile.getFileHendler()->write((char*)&temp3, sizeof(Student));
					}
					tempfile.getFileHendler()->write((char*)&temp2, sizeof(Student));//inserting the second file student at right position
				}
            }else if (temp > temp2) {
				tempfile.getFileHendler()->write((char*)&temp2, sizeof(Student));
				for (int j = 1; j < temp.id - temp2.id; ++j) {//filling the gap with empty students
					tempfile.getFileHendler()->write((char*)&temp3, sizeof(Student));
				}
				tempfile.getFileHendler()->write((char*)&temp, sizeof(Student));//inserting the first file student at right position
            }else if(temp.id==0&&temp2.id==0){
				tempfile.getFileHendler()->write((char*)&temp, sizeof(Student));//if both of the student at the file are empty,just insert one empty student
			}
		}
	if (const_cast<StudentFile&>(lhs).getFileHendler()->is_open())const_cast<StudentFile&>(lhs).getFileHendler()->close();
	if (const_cast<StudentFile&>(rhs).getFileHendler()->is_open())const_cast<StudentFile&>(rhs).getFileHendler()->close();
	if (tempfile.getFileHendler()->is_open()) tempfile.getFileHendler()->close();//if the file is still open close it
    return tempfile;//return using the mover constructor
}

bool StudentFile::operator !(){
    return error;
}
int StudentFile::getLastStudentId() {
    error=false;
    if (!fileHendler){
        error=true;/*throw "file was not found";*/
        return 0;
    }
	if (!fileHendler->is_open()) {
		fileHendler->open(fileName,fstream::in|fstream::out);//open
	}
	int lastId = 0;
	fileHendler->seekg(ios::beg);
	fileHendler->read((char*)&lastId, sizeof(int));//TODO: check for empty file
	fileHendler->close();
	return lastId;
}

void StudentFile::writeStudent(Student &student) {
	fileHendler->seekp(sizeof(int) + (student.id - 1) * sizeof(Student), ios::beg);//goto the number pos
	fileHendler->write((char*)&student, sizeof(Student));//write the student
}

void StudentFile::readStudent(Student &student, int number) {
	fileHendler->seekg(sizeof(int) + (number - 1) * sizeof(Student), ios::beg);
	fileHendler->read((char*)&student, sizeof(Student));
}

ostream & operator<<(ostream & out,const  Student & student){//over loading the output operator
    //BUG: write to no where
    StudentFile temp;//creating a temp file hendler using default constructor
    temp.addStudent(const_cast<Student&>(student));//adding the temp student to print it
    temp.printStudent(student.id);//using the temp obj to print the details of the student
	return out;
}
