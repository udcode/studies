//yudi noiman
//id: 301759692
//this code get a number and print triangle of numbers from the number to 1
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<< "enter a one digit number:"<<endl;
    //get a number from the user, make sure that the number is in the range
    do{
        cin>>n;
        if(n<0||n>99){
            cout<<"ERROR"<<endl;
        }
    }while(n<0||n>99);

    //print the triangle
    for(int i=0;i<n;++i){
        //print the line
        for(int j=n;j>0;--j){
            //print spaces for empty cell
            if(n-i<j){
                //print two spaces for two digit number (is optional in this mission) 
                if(j>9){
                    cout<<" ";
                }
                cout<<"  ";
            }else{
                cout <<j;
                //print comma between the numbers
                if(j>1){
                    cout<<",";
                }
            }

        }
        cout<<endl;
    }
    return 0;
}

/*
enter a one digit number:
20
20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
   19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
      18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
         17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
            16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
               15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
                  14,13,12,11,10,9,8,7,6,5,4,3,2,1
                     13,12,11,10,9,8,7,6,5,4,3,2,1
                        12,11,10,9,8,7,6,5,4,3,2,1
                           11,10,9,8,7,6,5,4,3,2,1
                              10,9,8,7,6,5,4,3,2,1
                                 9,8,7,6,5,4,3,2,1
                                   8,7,6,5,4,3,2,1
                                     7,6,5,4,3,2,1
                                       6,5,4,3,2,1
                                         5,4,3,2,1
                                           4,3,2,1
                                             3,2,1
                                               2,1
                                                 1
*/

