/*
	hexoct1.cpp -- shows hex and cotal literals
*/

#include <iostream>
using namespace std;

int main(void) {
	int chest = 42;        // decimal integer literal
	int waist = 0x42;      // hexadecimal integer literal
	int inseam = 042;      // octal integer literal

	cout << "Monsieur cuts a striking figure!\n";
	cout << "chest = " << chest << " (42 in decimal)\n";
	cout << "waist = " << waist << " (0x42 in hex)\n";
	cout << "inseam = " << inseam << " (042 in octal)\n";
	return 0;
}