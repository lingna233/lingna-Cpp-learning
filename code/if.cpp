/*
	if.cpp -- using the if statement
*/
#include <iostream>

using std::cin;         // using declarations
using std::cout;

int main() {
	char ch;
	int spaces = 0;
	int total = 0;
	cin.get(ch);
	while (ch != '.') {          // quit at end of sentence
		if (ch == ' ')         // check if ch is a space
			++spaces;
		++total;        // done every time
		cin.get(ch);
	}
	cout << spaces << " spaces, " << total;
	cout << " characters total in sentence\n";
	return 0;
}