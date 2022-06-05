#include <iostream>
#include "drob.h"

using namespace std;

void main() {
	Drob d1{ 1,2 };
	Drob d2{ 2,4 };
	Drob d3;
	d1 == d2 ? cout << "Yes" : cout << "No";
}