
#include "initfile.h"

using namespace std;
int main(){
    char fileName[80];
    cout<<"enter the name of the file to open"<<endl;
    cin>>fileName;//get the file name
    try{
        initFile(fileName);//init the file
    }catch(const char * s){//error handler
        cout<<s<<endl;
    }
}
