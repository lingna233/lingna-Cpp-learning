/*
	Œﬁ∑˚∫≈¿‡–Õ(exceed).cpp -- exceeding some integer limits
*/
#include <iostream>
#include <climits>   // defines INT_MAX as largest int value
#define ZERO 0      // make ZERO symbol for 0 value

using namespace std;

int main(void) {
	short sam = SHRT_MAX;    // initialize a variable to max value
	unsigned short sue = sam;    // okay if variable sam already defined

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl
		<< "Add $1 to each accout." << endl << "Now ";
	sam = sam + 1;
	sue = sue + 1;
	cout << "Sam has " << sam << " dollars san Sue has " << sue;
	cout << " dollars deposited." << "\n" << "Poor Sam!" << endl;
	sam = ZERO;
	sue = ZERO;
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl
		<< "Take $1 from each accout." << endl << "Now ";
	sam = sam - 1;
	sue = sue - 1;
	cout << "Sam has " << sam << " dollars san Sue has " << sue;
	cout << " dollars deposited." << "\n" << "Lucky Sue!" << endl;
	return 0;
}