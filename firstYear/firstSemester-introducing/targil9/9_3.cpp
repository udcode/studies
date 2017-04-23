//yudi noiman
//id: 301759692
//this code get a text and word and print the minimum distance between the show of the word
//in the text even with saperate letters

#include <iostream>
using namespace std;
/**
 * @brief isContained Search for the minimum show of the word in the text,
 *        even with saperate letters
 * @param text the text to search in
 * @param word the word to search for
 * @return the distance between the letters, or -1 for no result
 */
int isContained(char * text , char * word);
/**
 * @brief findJump Find the jump in one show only. this is a helper function to isContained
 * @param text the text to search in
 * @param word the word to search for
 * @return the distance between the letters, or -1 for no result
 */
int findJump(char* &text, char* word);

int  main(){
    char text[80];
    char word [80];
    //get the text and the word for the user
    cout<<"enter text:"<<endl;
    cin.getline(text,80);
    cout<<"enter word:"<<endl;
    cin.getline(word,80);
    //print the jump between the letters
    cout<<"size of jump: "<<isContained(text,word)<<endl;

    return 0;
}
int findJump(char* &text, char* word){
    //start from -1
    int jump=-1,lastJump=-1;
      while(*text&&*word){//move until the end of the text or the word
          if(*text==*word){//match cahr
              if(jump!=lastJump&&lastJump>=0){//mismach
                  return -1;
              }
              //set lastjump
              lastJump=jump;
              //set the jump to zero for next round
              jump=0;
              ++word;
              if(!*word){//end of the word
                  if(lastJump<0){//one letter
                  return jump;
                  }else{
                      return lastJump;
                  }
              }
          }else{
              if(jump>=0){//we are in search for the next letter
                  //increase the jump
                  jump++;
              }
          }
          ++text;
      }
      return lastJump;
}

int isContained(char * text , char * word){
    //start from -1
    int jump =-1;
    while(*text){//move over the text
        //find the next show
       int j= findJump(text,word);
       if (jump==-1){//it is the fist show
            jump=j;
       }else{
            if(jump>j&&j!=-1){//we find lower distance
                jump=j;
            }
       }
       //move to the next char
        ++text;
    }
    //return the jump, or -1
    return jump;
}
/*
enter text:
ajdbudcjseabc
enter word:
abc
size of jump: 0
*/
