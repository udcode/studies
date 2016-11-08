#include <iostream>
using namespace std;
int main() {
	int duration, time, HH, MM, SS,HH2,MM2,SS2, result,result1, result2, result3;

	cout << "enter flight takeoff \n";
	cin >> HH>> MM>> SS;
	
	time = (MM*60) + (HH*3600) + SS;
	cout << "enter flight duration \n";
	cin >> HH2>> MM2>> SS2;
	duration = (MM2*60) + (HH2*3600) + SS2;
	result = time + duration;
	result1 = result /3600;
	result2 = (result - (result1 *3600))/60 ;
	result3 = result % 60;
	result1 %= 24;
	cout <<result1 <<":" << result2 << ":" << result3 << "\n";

	system("pause");
	return 0;
}