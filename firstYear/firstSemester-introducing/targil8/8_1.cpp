//yudi noiman
//id: 301759692
//this code manage a demo bus company
//feature: it is possible to add line with number of stops and the duration of the ride
//and it is possible to delete line, and search for line, and print the avg of the travel and stops
//and the shortest line
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief addLine add line to list of lines
 * @param arr pointer to the array of the lines [by ref]
 * @param numBuses the size of the array
 * @param line the line to add
 * @param stops number of stops to add
 * @param durationOfRide the lenght of the ride
 */
void addLine(int **&arr, int numBuses, int line, int stops, int durationOfRide);
/**
 * @brief print the matrix of the lines and the details
 * @param buses pointer to the array of the lines
 * @param numBuses the size of the array
 */
void print(int ** buses,int numBuses);
/**
 * @brief insertLine insert the detials that given into the arr
 * this is acctualyy an helper function for addLine and deleteLine
 * @param arr the arr to insert to [by ref]
 * @param line the line to add
 * @param stops number of stops to add
 * @param durationOfRide the lenght of the ride
 */
void insertLine(int *&arr , int line, int stops, int durationOfRide);
/**
 * @brief search for line in the list of lines, using the binary search algorithem
 * @param buses pointer to the array of lines
 * @param numBuses the size of the array
 * @param line the line to search for
 * @return the index of the line in the array, or -1 if not found
 */
int search(int **buses,int  numBuses,int line);
/**
 * @brief deleteLine delete line from the list of lines
 * @param buses pointer to the array of lines [by ref]
 * @param numBuses the size of the array [by ref] after delete it will decrease
 * @param line the line to delete
 */
void deleteLine(int **&buses,int &numBuses,int line);
/**
 * @brief averageTravel calc the avg of travel
 * @param buses pointer to the array of the lines
 * @param numBuses the size of the array
 * @return the avg
 */
double averageTravel(int **buses,int numBuses);
/**
 * @brief averageStops calc the avg of stops. round to nearest
 * @param buses pointer to the array of the lines
 * @param numBuses the size of the array
 * @return the avg round to nearest
 */
int averageStops(int **buses,int numBuses);
/**
 * @brief shortest calc the shortest line
 * @param buses pointer to the array of the lines
 * @param numBuses the size of the array
 * @return the number of the shortest line
 */
int shortest(int **buses,int numBuses);

int  main(){
    int ** buses;
    int numBuses = 0;
    int line;
    int stops;
    int durationOfRide;
    int choice;
    do {
        cout << "enter 0-7" << endl;
        cin >> choice;
        switch(choice){
        case 0 : // add line
            cout << "enter the line to add" << endl;
            cin >> line;
            cout << "enter the number of stops" << endl;
            cin >> stops;
            cout << "enter the duration of the ride" << endl;
            cin >> durationOfRide;
            //check if the line is not in the list and the valuse to add are positives
            if(search(buses,numBuses,line)==-1&&line>0&&stops>0&&durationOfRide>0){
                numBuses++;
                if (numBuses == 1)
                    buses = new int * [1];
                addLine(buses, numBuses, line, stops, durationOfRide);
                print(buses,numBuses);
            }else{
                cout<<"ERROR"<<endl;
            }
            break;

        case 1 :	// delete line
            cout << "enter the line to delete" << endl;
            cin >> line;
            deleteLine(buses, numBuses, line);
            print(buses,numBuses);
            break;
        case 2: // print all lines
            print(buses,numBuses);
            break;
        case 3 : // search for a particular line
            cout << "enter the line to search for" << endl;
            cin >> line;
            cout << search(buses, numBuses, line)<<endl;
            break;
        case 4 : // calculate average travel time of all buses
            cout << averageTravel(buses, numBuses)<<endl;
            break;
        case 5:  // calcuate average stops of all buses
            cout << averageStops(buses, numBuses)<<endl;
            break;
        case 6: // calculate the bus with the shortest travel time
            cout << shortest(buses,numBuses)<<endl;
            break;
        case 7: break;   // exit the program

        default : cout << "ERROR"<<endl;
        }// switch
    } while (choice != 7);
    //free the memory
    for(int i=0; i < numBuses; i++)
        delete[] buses[i];
    if (numBuses > 0)
        delete [] buses;
    return 0;
}
void insertLine(int *&arr , int line, int stops, int durationOfRide){
    //create array with size 3 and fill it with the values
    arr=new int [3];
    arr[0]= line;
    arr[1]= stops;
    arr[2]= durationOfRide;
}

void addLine(int **&arr, int numBuses, int line, int stops, int durationOfRide){
    bool isLast =true;
    if(numBuses>1){//it is not the first line
        //move over the array to find the place to insert the new entry
        for(int i=0;i<numBuses-1&&isLast;++i){
            if(line<arr[i][0]){
                //move from here all the items forword
                //and add the line in i

                //declare new matrix to fill
                int ** fixedPtr = new  int * [numBuses];
                for(int j=0;j<numBuses;++j){//move over the array
                    if(i>j){//before the index
                        insertLine(fixedPtr[j],arr[j][0],arr[j][1],arr[j][2]);
                    }else if(i<j){//after the index, move them by 1
                        insertLine(fixedPtr[j],arr[j-1][0],arr[j-1][1],arr[j-1][2]);
                    }else if(i==j){//the index to fill with the new
                        insertLine(fixedPtr[i],line,stops,durationOfRide);
                    }
                }
                //free the memory of the old array
                for(int k=0;k<numBuses-1;++k){
                    delete[]arr[k];
                }
                delete [] arr;
                //point to the new array
                arr=fixedPtr;
                isLast=false;
            }
        }
    }
    if(isLast){
        //add the line to the last
        insertLine(arr[numBuses-1],line,stops,durationOfRide);
    }
}
void print(int ** buses,int numBuses){
    //move over the array and print it as matrix
    for(int i=0;i<numBuses;++i){
        for(int j=0;j<3;++j){
            cout<< buses[i][j]<<" ";
        }
        cout <<endl;
    }
}
int search(int **buses,int  numBuses,int line){
    int left=0;
    int right= numBuses-1;
    int middle;
    if(numBuses>0){//the array is not empty
        if(line>=buses[0][0]&&line<=buses[numBuses-1][0]){//the line is in the range
            while(left<=right){//while the bounds are correct
                //set the middle
                middle=left+(right-left)/2;
                if(line==buses[middle][0]){//line found
                    return middle;
                }else{
                    if(line > buses[middle][0]){//move left
                        left=middle+1;
                    }else{//move the right
                        right=middle-1;
                    }
                }
            }
        }
    }
    //not found
    return -1;
}
void deleteLine(int **&buses,int &numBuses,int line){
    if(search(buses,numBuses,line)>-1){//the line is exist
        //declare new matrix to fill, smaller by 1
        int ** fixedPtr = new  int * [numBuses-1];
        //move over the array and copy every entry to the new matrix, skip on the deleted entry
        for(int i=0,j=0;i<numBuses;++i){
            if(buses[i][0]!=line){//the entry is not deleted
                insertLine(fixedPtr[j],buses[i][0],buses[i][1],buses[i][2]);
                ++j;
            }else{//the entry should be deleted so skip it
                continue;
            }
        }
        //free the memory of the old matrix
        for(int k=0;k<numBuses;++k){
            delete[]buses[k];
        }
        delete [] buses;
        //point to the new matrix
        buses=fixedPtr;
        //decrease the size of the array
        --numBuses;
    }
}
double averageTravel(int **buses,int numBuses){
    if (numBuses>0){//the list are not empty
        int sum=0;
        //move over the array and do the sum
        for(int i=0;i<numBuses;++i){
            sum+=buses[i][2];
        }
        //calc the avg
        return sum/static_cast<double>(numBuses);
    }
    return 0;
}
int averageStops(int **buses,int numBuses){
    if (numBuses>0){//the list are not empty
        int sum=0;
        //move over the array and do the sum
        for(int i=0;i<numBuses;++i){
            sum+=buses[i][1];
        }
        //calc the avg
        //round the avg to the nearest
        //!! i used in round from cmath.
        return round(sum/static_cast<double>(numBuses));
    }
    return 0;
}
int shortest(int **buses,int numBuses){
    if(numBuses>0){//the list are not empty
        //take the first entry as anchor
        int line=buses[0][0];
        int minDurationOfRide=buses[0][2];
        //move over the array and seek for the shortest
        for(int i=0;i<numBuses;++i){
            if(buses[i][2]<minDurationOfRide){//is shorter then the latest line
                minDurationOfRide=buses[i][2];
                line=buses[i][0];
            }
        }
        return line;
    }
    return 0;
}
/*
enter 0-7
0
enter the line to add
1
enter the number of stops
2
enter the duration of the ride
3
1 2 3
enter 0-7
0
enter the line to add
3
enter the number of stops
5
enter the duration of the ride
6
1 2 3
3 5 6
enter 0-7
0
enter the line to add
5
enter the number of stops
6
enter the duration of the ride
99
1 2 3
3 5 6
5 6 99
enter 0-7
5
4
*/

