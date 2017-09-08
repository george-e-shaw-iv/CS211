/*
 * Filename: homework02_code.cpp
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 2
 * Description: Shapes using minimal cout statements.
 */

#include <iostream>

using namespace std;

int main() {
	//Triangle
	for(int line = 0; line < 4; line++) {
		for(int spaces = line; spaces > 0; spaces--) {
			cout << " ";
		}
		for(int hashes = (8 - (line * 2)); hashes > 0; hashes--) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
