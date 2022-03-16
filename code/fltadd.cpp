/*
	fltadd.cpp -- precision problems with float
*/
#include <iostream>
using namespace std;

int main(void) {
	float a = 2.34e+22;
	float b = a + 1.0;
	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
	return 0;
}