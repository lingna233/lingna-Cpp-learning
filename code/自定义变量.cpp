#include <iostream>
using namespace std;
int main(void){
	int carrots;               //����һ������carrots
	carrots = 25;              //��carrots��ֵΪ25
	cout << "I have ";         //C++ output
	cout << carrots;
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1;
	cout << "Crunch, crunch.Now I have " << carrots << " carrots." << endl;
	return 0;
}