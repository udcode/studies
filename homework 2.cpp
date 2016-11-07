#include <iostream>
using namespace std;
int main() {
	int x, y,z;
	cout << "Enter tow numbers here \n";
	cin >> x >> y;
	cout << "x = " << x << " " <<"y =" << y<<"\n";
	z = x;
	x = y;
	y = z;
	cout << "x = " << x << " " << "y =" << y << "\n";

	system("pause");
	return 0;
}