#include <iostream>
using namespace std;
int main() {
	int num1, num2;
	cout << "enter tow numbers here\n";
	cin >> num1 >> num2;
	cout << num1 << "+" << num2 << "=" << num1 + num2<<"\n";
	cout << num1 << "-" << num2 << "=" << num1 - num2 << "\n";
	cout << num1 << "*" << num2 << "=" << num1 * num2 << "\n";
	if (num2!= 0) 
	{
		cout << num1 << "/" << num2 << "=" <<(float) num1 / num2 << "\n";
	}
	else
	{
		cout << "error: dividing by 0 is not allowed\n";
	}
	system("pause");
	return 0;
}