/*
	equal.cpp -- equality vs assignment
*/
#include <iostream>

using namespace std;

int main() {
	int quizscorce[10] = { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };
	cout << "Doing it right:\n";
	int i;
	for (i = 0; quizscorce[i] == 20; i++)
		cout << "quiz " << i << " is a 20\n";
// Warning: you may prefer reading about this program to actually runing it.
	cout << "Doing it dangerously wrong:\n";
	for (i = 0; quizscorce[i] = 20; i++)
		cout << "quiz " << i << " is a 20\n";

	return 0;
}