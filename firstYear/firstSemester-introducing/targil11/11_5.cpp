//this cose print the options to 8 qween problem. with recursive method
#include <iostream>
using namespace std;

int board [8]={0,0,0,0, 0,0,0,0};//evry qween can be on one line only
int count =0;
void printBoard() {
    int i,j;
    cout<<"Solution :"<<count<<endl;
    for(j=0; j<8; ++j)
        cout<<"+---";

    cout<<endl;
    //print matrix with * where qween should be
    for(i=0; i<8; ++i) {

        for(j=0; j<board[i]; ++j)
            cout<<"|   ";
        cout<<"| * ";
        j++;
        for(; j<8; ++j)
            cout<<"|   ";
        cout<<"|"<<endl;
        for(j=0; j<8; ++j)
            cout<<"+---";

        cout<<endl;

    }
    cout<<endl;
}
int valid(int i, int j) {
    //the diagonal
    int diagPlus = i+j, diagMinus = i-j;

    //check every cell
    for(int i1=0; i1<i; ++i1) {
        int j1 = board[i1];
        //check the diagonal and the column
        if(j == j1 || i1+j1 == diagPlus || i1-j1 == diagMinus)
            return 0;
    }
    return 1;
}

//find place for qween by line i.
void queens(int i) {
    if(i == 8) {//solution found
        ++count;
        printBoard();//print it
        return;
    }
    int j;
    for(j=0; j<8; ++j) {//check evry column for place
        if(valid(i,j)) {//free place
            board[i] = j;//set qween here
            queens(i+1);//move next
        }
    }

}
//check cell if qween can be there

int main(){
    queens(0);//start
    return 0;
}

