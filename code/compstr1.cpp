/*
	compstr1.cpp -- comparing strings using arrays
*/
#include <iostream>
#include <cstring>                   // prototype for strcmp()

using namespace std;

int main() {
	char word[5] = "?ate";
	for (char ch = 'a'; strcmp(word, "mate"); ch++) {
		cout << word << endl;
		word[0] = ch;
	}
	cout << "After loop ends, word is " << word << endl;
	return 0;
}