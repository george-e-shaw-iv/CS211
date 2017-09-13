/*
 * Filename: homework02_code.cpp
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 2
 * Description: Shapes using minimal cout statements.
 */

#include <iostream>
#include <stdlib.h>

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

	cout << "\n\n";

	//Diamond
	int diamondHashCalc;
	for(int line = 0; line < 7; line++) {
		for(int spaces = abs(line - 3); spaces > 0; spaces--) {
			cout << " ";
		}

		if(line > 3) diamondHashCalc = 2 + (abs(line - 6) * 2);
		else diamondHashCalc = 2 + (line * 2);

		for(int hashes = diamondHashCalc; hashes > 0; hashes--) {
			cout << "#";
		}
		cout << "\n";
	}

	cout << "\n\n";

	//X
	for(int line = 0; line < 7; line++) {
		for(int singleChar = 0; singleChar < 7; singleChar++) {
			if(line == singleChar || (6 - line) == singleChar) cout << "#";
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
