/*
Filename: homework01_code.cpp / homework01_executable
Name: George Shaw
WSUID: g829g576
HW #: 1
Description: A simple arithmetic program using two operands.
*/

#include<iostream>

using namespace std;

// Program Entry Point
int main() {
	int one, two, operation;
	float answer;
	bool isValid;

	cout << "Enter the first integer: ";
	cin >> one;
	cout << "Enter the second integer: ";
	cin >> two;

	
	// Looping until a valid operation is selected
	while(true) {
		isValid = true;

		cout << "\nThe avaliable operations are:\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n";
		cout << "Enter the number for your choice of operation: ";
		cin >> operation;

		// Looping through the cases that operation could be
		switch(operation) {
			case 1:
				answer = one + two;
				cout << endl << one << " + " << two << " = " << answer << endl;
				break;
			case 2:
				answer = one - two;
				cout << endl << one << " - " << two << " = " << answer << endl;
				break;
			case 3:
				answer = one * two;
				cout << endl << one << " * " << two << " = " << answer << endl;
				break;
			case 4:
				if(two == 0) {
					cout << endl << one << " / " << two << " cannot be found because can't divide by zero.\n";
					isValid = false;
				}
				else {
					answer = one / two;
					cout << endl << one << " / " << two << " =  " << answer << endl;
				}
				break;
			default:
				cout << "\nInvalid operation, please select a valid key." << endl;
				isValid = false;
				break;
		}

		if(!isValid) {
			continue; // If isValid is equal to false, re-run this while block
		}
		else {
			break; // If isValid is equal to true, break out of this while block
		}
	}

	return 0;
}
