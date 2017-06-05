#include "initfile.h"

using namespace std;

void initFile(char *name){
    ofstream file (name);//open the file
    if(!file)throw "error wile open the file";//cant open
	int a = 0;
	file.write((char*)&a, sizeof(int));
    for(int i=0;i<10;++i){//fill the file
        file.write((char *)&Student::emptyStudent,sizeof(Student));//write to the file
    }
}
