/*
	forloop.cpp -- introducing the for loop
*/
#include <iostream>
using namespace std;

int main() {
	int i;                      // create a counter
//  initialize; test; update
	for (i = 0; i < 3; i++) {
		cout << "C++ knows loops.\n";
	}
	cout << "C++ knows when to stop.\n";
	return 0;
}