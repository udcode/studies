//yudi noiman
//id: 301759692
//this code get manage a lexicon of words. main functions are adding, deleting, search, and print.

#include <iostream>
#include <cstring>
using namespace std;
/**
 * @brief newStr Add new word to the list. insert by order
 * @param lexicon Pointer to the lexicon [by ref]
 * @param numWords Size of the list [by ref]
 * @param word The word to add
 */
void  newStr(char** &lexicon,int &numWords,const char* word);
/**
 * @brief delStr Delete word from the list
 * @param lexicon Pointer to the lexicon [by ref]
 * @param numWords Size of the list [by ref]
 * @param word The word to delete
 */
void  delStr(char ** &lexicon,int &numWords,const char* word);
/**
 * @brief searchStr Search for word in the list. using binary search
 * @param lexicon Pointer to the lexicon
 * @param numWords Size of the list
 * @param word The word to look for
 * @return Pointer to the word. if not found NULL
 */
char * searchStr ( char** lexicon, int numWords, const char* word);
/**
 * @brief printChar Print all words with given irst letter
 * @param lexicon Pointer to the lexicon
 * @param numWords Size of the list
 * @param l The first letter to print from
 */
void  printChar(char** lexicon, int numWords,char l);
/**
 * @brief printAll Print the list.
 * @param lexicon Pointer to the lexicon
 * @param numWords Size of the list
 */
void printAll (char** lexicon, int numWords);

int  main(){
    char ** lexicon =NULL;//nullptr
    char  word[80] ;
    int numWords =0;
    int choice,l=0;
    do{//do until 5
        cout<<"enter 0-5:"<<endl;
        cin>>choice;
        switch (choice) {
        case 0:
            //add word
            cout<<"enter the word:"<<endl;
            cin.ignore();//clear the cache
            cin.getline(word,80);//get the word
            l = strlen(word);
            word[l]='\0';
            newStr(lexicon,numWords,word);
            printAll(lexicon,numWords);
            break;
        case 1:
            //delete word
            cout<<"enter the word to delete:"<<endl;
            cin.ignore();//clear the cache
            cin.getline(word,80);//get the word
            l = strlen(word);
            word[l]='\0';
            delStr(lexicon,numWords,word);
            printAll(lexicon,numWords);
            break;
        case 2:
            //search
            cout<<"enter the word to search for:"<<endl;
            cin.ignore();//clear the cache
            cin.getline(word,80);//get the word
            l = strlen(word);
            word[l]='\0';
            if(searchStr(lexicon,numWords,word)==NULL){//not found
                cout<<"not found"<<endl;//found
            }else{
                cout<<"found"<<endl;
            }
            break;
        case 3:
            //print by letter
            char letter;
            cout<<"enter the char:"<<endl;
            cin>>letter;//get the letter
            printChar(lexicon,numWords,letter);
            break;
        case 4:
            //print all
            printAll(lexicon,numWords);
            break;
        case 5:
            //exit
            break;
        default:
            cout << "ERROR"<<endl;
            break;
        }
    }while(choice!=5);

    //free the memory
    for (int i=0;i<numWords;++i){
        delete [] lexicon[i];
    }
    if(numWords>0){
        delete [] lexicon;
    }

    return 0;
}
void  newStr(char** &lexicon,int &numWords,const char* word){
    if(numWords>0){//it is not the first word
        if(searchStr(lexicon,numWords,word)==NULL){//word not in the list
            //new array to fill size+1
            char ** newLexicon = new char *[numWords+1];
            int oldIndex=0;
            bool inserted =false;
            //fill the new arry
            for(int i =0;i<numWords+1;++i){
                //copy smaller words into the new lexicon, or if word inserted
                if((i<numWords&&strcmp(lexicon[oldIndex],word)<0)||inserted){
                    newLexicon[i]=new char [strlen(lexicon[oldIndex])+1];
                    //copy old words
                    strcpy(newLexicon[i],lexicon[oldIndex]);
                    ++oldIndex;
                }else{//copy the word in the order place
                    newLexicon[i]=new char [strlen(word)+1];
                    strcpy(newLexicon[i],word);
                    inserted=true;
                }
            }
            //free the memory
            for(int i=0;i<numWords;++i){
                delete [] lexicon[i];
            }
            delete [] lexicon;
            //get the pointer to point to the new array
            lexicon = newLexicon;
            ++numWords;
        }
    }else{//is first word
        //allocate one place and copy the word into
        lexicon =new char * [1];
        lexicon[0]=new char[strlen(word)+1];
        strcpy(lexicon[0],word);
        //increase the num of the words
        ++numWords;
    }
}
void  delStr(char ** &lexicon,int &numWords,const char* word){
    //the list is not empty and the word is in the list
    if(numWords>0&&(searchStr(lexicon,numWords,word)!=NULL)){
        //creae new lexicon size-1
        char ** newLexicon =new char * [numWords-1];
        int oldIndex=0;
        //copy the old list, jump on the word to delete
        for(int i=0;i<numWords-1;++i){
            if(strcmp(lexicon[i],word)==0){//skip on the entry to delete
                ++oldIndex;
            }else{
                //copy words
                newLexicon[i]=new char[strlen(lexicon[oldIndex])+1];
                strcpy(newLexicon[i],lexicon[oldIndex]);
                ++oldIndex;
            }
        }
        //free the memory
        for(int i=0;i<numWords;++i){
            delete [] lexicon[i];
        }
        delete [] lexicon;
        //get the pointer to point to the new array
        lexicon=newLexicon;
        //deacrease the num of the words
        --numWords;
    }
}

char * searchStr ( char **lexicon, int numWords,const char * word){
    //set left right and mid of the array
    int left=0,right = numWords-1,mid;
    if(strcmp(lexicon[left],word)<=0&&strcmp(lexicon[right],word)>=0){//word in range
        while(left<=right){//go until the end of the array
            //set mid to the middle of the erea of the search
            mid= left+(right-left)/2;
            if(strcmp(lexicon[mid],word)==0){//found
                return lexicon[mid];
            }
            if(strcmp(lexicon[mid],word)>0){//lexicon[mid]>word
                //move the right
                right=mid-1;
            }else{//lexicon[mid]<word
                //move the left
                left=mid+1;
            }
        }
    }
    return NULL;
}
void  printChar(char** lexicon, int numWords,char l){
    bool pass=false;
    //move over the array, or until it is print all the words
    for(int i =0;i<numWords&&!pass;++i){
       if(lexicon[i][0]==l){//the word starts with the letter
           cout<<lexicon[i]<<" ";
       }else{//skip on the word
           if(lexicon[i][0]>l){//the words thet start with l already passed
               pass=true;
           }
       }
    }
    cout<<endl;
}

void printAll (char** lexicon, int numWords){
    //print all the list of the words
    for(int i =0;i<numWords;++i){
        cout<<lexicon[i]<<" ";
    }
    cout<<endl;
}
/*
enter 0-5:
0
enter the word:
hi
hi 
enter 0-5:
0
enter the word:
morning
hi morning 
enter 0-5:
0
enter the word:
walla
hi morning walla 
enter 0-5:
1
enter the word to delete:
walla
hi morning 
enter 0-5:
2
enter the word to search for:
hi
found
enter 0-5:
4
hi morning 
enter 0-5:
3
enter the char:
m
morning 
enter 0-5:
5
*/
