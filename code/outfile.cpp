/*
	outfile.cpp -- writing to a file
*/
#include <iostream>
#include <fstream>         // for file I/O

using namespace std;

int main() {
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;                // create object for output
	outFile.open("carinfo.txt");     // associate with a file

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

// dispaly information on screen with cout

	cout << fixed;				       // prohibit the use of scientific notation
	cout.precision(2);                 // reserve two decimal places
	cout.setf(ios_base::showpoint);    // displays zeros after the decimal point for floating point numbers 
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

// now do exact same thing using outFile instead of cout

	outFile << fixed;				      // prohibit the use of scientific notation
	outFile.precision(2);                 // reserve two decimal places
	outFile.setf(ios_base::showpoint);    // displays zeros after the decimal point for floating point numbers 
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	
	outFile.close();
	return 0;
}