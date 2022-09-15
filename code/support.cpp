/*
	support.cpp -- use externel variable
*/
// compile with externel.cpp
#include <iostream>

extern double warming;	// use warming from another file

// function prototypes
void update(double dt);
void local();

using std::cout;

void update(double dt) {	// modifies global variable
	extern double warming;	// optional redeclaration
	warming += dt;	// use global warming
	cout << "Updating global warming to " << warming << " degrees.\n";
}

void local() {		// use local variable
	double warming = 0.8;	// new vaeiable hides externel one

	cout << "Local warming = " << warming << " degrees.\n";
	// Access global variable with the scope resolution operator
	cout << "But global warming = " << ::warming << " degrees.\n";
}
