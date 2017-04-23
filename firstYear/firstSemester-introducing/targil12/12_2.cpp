//this code take file and encrypt the text into enother file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/**
 * @brief encryptFile Encrypt the file
 * @param src The file to encrpt
 * @param dest The file to write to
 */
void encryptFile(char * src, char * dest);
/**
 * @brief encryptLetter Take letter and give the azby of that letter. for numbers give n+1
 * @param l The letter to encryt
 * @return The encryped letter
 */
char encryptLetter(char l);

int main(){
    char inputName[25];
    char outputName[25];
    //get the names from the user.*** it wasn't required in the exercise!!
    cout<<"insret input file name:"<<endl;
    cin.getline(inputName,25);
    cout<<"insert output file name:"<<endl;
    cin.getline(outputName,25);
    //encrypt the files
    encryptFile(inputName,outputName);
    return 0;
}
void encryptFile(char * src, char * dest){
    //open the files
    ifstream input(src);
    ofstream output(dest);
    if(!input&&!output)
	exit(1);//fail to open the file
    char l;
    bool isFirst =true;
    while(input.get(l)){//get by letter til the end
        if(!isFirst)//not the first line. write the end of line *before* the new line.
            output<<endl;
        output<<encryptLetter(l);
        isFirst=false;
    }
    //close the files
    input.close();
    output.close();
}
char encryptLetter(char l){
    if(l>='a'&&l<='z'){//encryp by azby
        return('z'-(l-'a'));
    }else if(l>='A'&&l<='Z'){//encryp by AZBY
        return('Z'-(l-'A'));
    }else if(l>='0'&&l<='9'){//encrypt by n+1 9==0
        if(l=='9')
            return '0';
        else
            return l+1;
    }
    return l;
}
/*
 input file:
 A!a?B123b321Z
 output file:
Z
!
z
?
Y
2
3
4
y
4
3
2
A
*/

