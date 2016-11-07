#include <iostream>
using namespace std;
int main(){
	//setting the variables
	float a, b, c;
	cout << " Enter two numbers \n";
	//asking the user to input tow numbers
	cin >> a >> b;
	//doing the math
	c = (5 * a + 3) / (6 * b + 2);
	//printing the result
	cout << "c= " << c <<endl; 
	system("pause");
	return 0;

}