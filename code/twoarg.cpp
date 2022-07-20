/*
	twoarg.cpp -- a function with 2 arguments
*/
#include <iostream>

void n_chars(char, int);

using namespace std;

int main() {
	int times;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	while (ch != 'q') {					// q to quit
		cout << "Enter an integer: ";
		cin >> times;
		n_chars(ch, times);			// function with two arguments
		cout << endl << "Enter another character or press the q-key to quit: ";
		cin >> ch;
	}
	cout << "The value of times is " << times << ".\n";
	cout << "Bye!" << endl;
	return 0;
}

void n_chars(char c, int n) {			// displays c n times
	while (n-- >0) {					// continue until n reaches 0
		cout << c;
	}
}