/*
	while.cpp -- introducing the while loop
*/
#include <iostream>

using namespace std;

const int ArSize = 20;

int main() {
	char name[ArSize];
	cout << "Your first name, please: ";
	cin >> name;
	cout << "Here is your name, verticalized and ASCIIized:\n";
	int i = 0;                                // strat at beginning of string
	while (name[i] != '\0') {                 // process to end of string
 // while (name[i])
		cout << name[i] << ": " << (int)name[i] << endl;
		i++;                                  // don't forget this step
	}
	return 0;
}