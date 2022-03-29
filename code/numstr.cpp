/*
	numstr.cpp -- following number input with line input
*/
#include <iostream>
using namespace std;

int main() {
	int year;
	char address[80];
	cout << "What year was your house built?\n";
	//(cin >> year).get();
	cin >> year;
	cin.get();     // read enter
	cout << "What's its street address?" << endl;
	cin.getline(address, 80);
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
	return 0;
}