#include <iostream>
using namespace std;
int main(void){
	int carrots;               //定义一个变量carrots
	carrots = 25;              //将carrots赋值为25
	cout << "I have ";         //C++ output
	cout << carrots;
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1;
	cout << "Crunch, crunch.Now I have " << carrots << " carrots." << endl;
	return 0;
}