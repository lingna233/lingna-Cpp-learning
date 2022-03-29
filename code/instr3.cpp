/*
	instr3.cpp -- reading more than one word with get() & get()
*/
#include <iostream>
using namespace std;

int main() {
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:" << endl;
	//cin.get(name ,AeSzie);
	//cin.get();
	cin.get(name, ArSize).get();    // reads string, newline
	cout << "Enter your favorite dessert:" << endl;
	//cin.get(dessert ,AeSzie);
	//cin.get();
	cin.get(dessert, ArSize).get();
	cout << "I have some delicious " << dessert << " for you," << name << endl;
	return 0;
}