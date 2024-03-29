/*
	static.cpp -- using a static local variable
*/
#include <iostream>

using namespace std;

// constants
const int ArSize = 10;

// function prototype
void strcount(const char *str);

int main() {
	char input[ArSize];
	char next;

	cout << "Enter a line:\n";
	cin.get(input, ArSize);
	while (cin) {
		cin.get(next);
		while (next != '\n') {		// string didn't fit!
			cin.get(next);		// dospose of remainder
		}
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArSize);
	}
	cout << "Bye\n";
	return 0;
}

void strcount(const char *str) {
	static int total = 0;	// static local variable
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while (*str++) {		// go to end of string
		count++;
	}
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
