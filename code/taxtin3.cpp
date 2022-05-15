/*
	taxtin3.cpp -- reading chars to end of file
*/
#include <iostream>

using namespace std;

int main() {
	char ch;
	int count = 0;
	cin.get(ch);             // attempt to read a char
	while (cin.fail() == false) {           // test for EOF
		cout << ch;             // echo character
		++count;
		cin.get(ch);         // attempt to read another char
	}
	cout << endl << count << " characters read\n";
	return 0;
}