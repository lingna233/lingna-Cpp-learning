/*
	file2.cpp -- contains functions called in file1.cpp
*/
#include <iostream>
#include <cmath>
#include "coordin.h"	// structure templates, function prototypes

using namespace std;

// convert rectangular to polar coodinates
polar rect_to_polar(rect xypos) {
	polar answer;

	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;	// returns a polar structuer
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos) {
	const double Red_to_deg = 57.29577951;

	cout << "distance = " << dapos.distance;
	cout << ", angle = " << dapos.angle * Red_to_deg;
	cout << " degrees.\n";
}
