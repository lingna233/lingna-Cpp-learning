/*
	modulus.cpp -- uses % operator to convert lbs to stone
*/
#include <iostream>
using namespace std;

int main(void) {
	const int Lbs_per_stn = 14;
	int lbs;
	
	cout << "Enter your weight in pounds: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;     // whole stone
	int pounds = lbs % Lbs_per_stn;    // remainder in pounds
	cout << lbs << " pounds are " << stone << " stone, " << pounds << " pound(s). \n";
	return 0;
}