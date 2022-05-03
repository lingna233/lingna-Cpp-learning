/*
	block.cpp -- use a block statement
*/
#include <iostream>

using namespace std;

int main() {
	cout << "The Amazing Accounto will sum and average ";
	cout << "five numbers for you.\n";
	cout << "Please rnter five values:\n";
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++) {                       // block starts here
 		cout << "Value " << i << ": ";
		cin >> number;
		sum += number;
	}                                                    // block ends here
	cout << "Five exquisite choices indeed! ";
	cout << "They sun to " << sum << endl;
	cout << "and average to " << sum / 5 << ".\n";
	cout << "The Amazing Accounto bids you adieu!\n";
	return 0;
}