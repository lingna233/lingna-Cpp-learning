/*
	用户自定义函数.cpp -- defining your own function
*/
#include <iostream>
using namespace std;
void simon(int);   // function prototype for simon()

int main(void){
	simon(3);      // call the simon() function
	cout << "Pick an integer: ";
	int count;
	cin >> count;
	simon(count);  // call it again
	cout << "Done!" << endl;
	return 0;
}

void simon(int n){                // define the simon() function
	cout << "Simon says touch your toes " << n << " times." << endl;  // void function don't need return statements
}