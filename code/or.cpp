/*
	or.cpp -- using the logical OR operator
*/
#include <iostream>

using namespace std;

int main() {
	cout << "This program may reformat your hard disk\n"
		"and destroy all your data.\n"
		"Do you wish to continye? <y/n>";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')         // y or Y
		cout << "You were warned!\a\a\n";
	else if (ch == 'n' || ch == 'N')
		cout << "A wise chice ... bye\n";
	else
		cout << "That wasn't a y or n! Apparently you can't follow "
			"insturctions,\nso I'll trash your disk anyway.\a\a\a\n";
	return 0;
}