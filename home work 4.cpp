#include <iostream>
using namespace std;
int main() {
	int num,x,y,z;
	//asking the user to input three digit number
	cout << "Enter a three digit number here \n";
	cin >> num ;
	//separating the first digit
	x = num / 100;
	//separating the second digit
	y = num/10;
	y %= 10;
	//separating the thered digit
	z = num % 10;
	//doing the math
	cout << "the sum is: " <<x + y + z<< "\n";

	system("pause");
	return 0;
}