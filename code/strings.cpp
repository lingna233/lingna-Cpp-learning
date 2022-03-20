/*
	strings.cpp -- storing strings in an array
*/
#include <iostream>
#include <cstring>   // for the strlen() function
using namespace std;

int main() {
	const int Size = 15;
	char name1[Size];                   // empty array
	char name2[Size] = "C++owboy";      // initialized array
	// NOTE: some implementations may require the static keyword to initalize the array name2

	cout << "Howdy! I'm " << name2 << "! What's your name?\n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';   // Set to null character
	cout << "Here are the frist 3 characters of my name: ";
	cout << name2 << endl;
	return 0;
}