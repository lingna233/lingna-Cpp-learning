/*
	ifelseif.cpp -- using if else if else
*/
#include <iostream>

const int Fave = 27;

using namespace std;

int main() {
	int n;
	
	cout << "Enter a number in the range 1-100 to find ";
	cout << "my favorite number: ";
	do {
		cin >> n;
		if (n < Fave)
			cout << "Too low -- guess again: ";
		else if (n > Fave)
			cout << "Too high -- guess again: ";
		else
			cout << Fave << " is right!" << endl;
	} while (n != Fave);

	return 0;
}