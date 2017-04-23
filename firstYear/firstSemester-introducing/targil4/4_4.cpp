//yudi noiman
//id: 301759692
//this code print sum of series, by getting the x as base and n for the last index 
#include <iostream>
using namespace std;

int main()
{
	int x, n;
	
	cout << "enter 2 numbers: " << endl;
	cin >> x ;
	//get the n, make sure that n bigger then 0
	do {
		cin >> n;
		if (n <= 0) {
			cout << "ERROR"<< endl;
		}
	} while (n <= 0);
	
	//calculate the sum of the series
	double sum = 0.0;
	for (int i = 1; i < n+1; i++) {	
	    //calculate the power of -1
		int powerOfMinusOne;
		if ((i) % 2==0) {
			powerOfMinusOne = -1;
		}
		else {
			powerOfMinusOne = 1;
		}
		
		//calculate the power of the x
		int secondePower = x;
		for (int k = 1; k < 2*i - 1; k++) {
			secondePower = secondePower *x;
		}

		sum = sum + (powerOfMinusOne/(double)(2 *i-1))*secondePower;
	}
	
	cout << sum<<endl;

	return 0;
}




