//yudi noiman
//id: 301759692
//this code get number and print the nearest bigger Prime number

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/**
    Returns if n is a Pime number.
    @param n The number to check.
    @return true if is a Prime number either is false.
*/
bool isPrime(int n);
/**
    Returns prime number if n is prime and the nearest bigger prime if n is not prime.
    @param n The number to check.
    @return prime number if n is prime and the nearest bigger prime if n is not prime.
*/
int findPrime(int n);

int main()
{
    //set the rand
    srand(time(NULL));

    int number;
    cout<<"enter number of values:"<<endl;
    //get number from the user
    cin>>number;
    //if the number is negative get rand number in 10 to 100
    if(number<0){
        number =  rand()%90 + 10;
    }
    //print the table size
    cout<<"table size: "<<findPrime(number)<<endl;
    return 0;
}

bool isPrime(int n){
    bool isPrime =true;
    //check if the number is divided by any number except 1 and n
    for(int i =2;i<n/2;++i){
        if(n%i==0){
            isPrime=false;
        }
    }
    //1 is not prime!
    if(n==1){
        isPrime=false;
    }
    return isPrime;
}

int findPrime(int n){
    int primeNumber;
    //if the number i prime return the number
    if(isPrime(n)){
        primeNumber= n;
    }else{//else return the nearest bigger prime number
        bool primeFound =false;
        for(int i=1;!primeFound;++i){
            if(isPrime(n+i)){
                primeNumber= n+i;
                primeFound=true;
            }
        }
    }
    return primeNumber;
}
/*
enter number of values:
50
table size: 53
*/

