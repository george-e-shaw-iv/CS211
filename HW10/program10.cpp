/*
 * Filename: program10.cpp
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 10
 * Description: Numerical zip code to postnet converter and vice versa.
 */

#include <iostream>
#include <string>

using namespace std;

enum zipcode_type {
	ROMAN,
	POSTNET
};

enum destination {
	CONSOLE,
	TEXT_FILE
};

class Zipcode {
	private:
		int roman;
		string postnet;
		string barcode[2][27];

		void setPostnet() {

		}

		void setRoman() {

		}

		void setBarcode() {

		}

	public:
		Zipcode(string value, zipcode_type type) {
			switch(type) {
				case ROMAN:
					this->roman = stoi(value);
					setPostnet();
					break;
				case POSTNET:
					this->postnet = value;
					setRoman();
					break;
			}

			setBarcode();
		}

		int GetRoman() {
			return this->roman;
		}

		string GetPOSTNET() {
			return this->postnet;
		}

		void PrintBarcode(destination dest) {
			switch(dest) {
				case CONSOLE:
					break;
				case TEXT_FILE:
					break;
			}
		}
};

/*
 * Argument is used to display appropriate prompt to user
 * Gets zip code from user
 * Creates and assigns to a Zipcode class
 * Prints roman and graphical bar code to screen
 * Creates a file whose name is in the format ROMAN.txt where
 *		ROMAN is the roman zip code, and the contents are the
 *		graphical representation of the bar code
 */
void processZip(int prompt);

int main() {
	int mainMenu;

	cout << "This program is able to convert zip codes to a POSTNET format "
		<< "and vice versa\n"
		<< "\t1. Convert zip code to POSTNET\n"
		<< "\t2. Convert POSTNET to zip code\n"
		<< "\t3. Quit\n";

	do {
		cout << "Please make your selection: ";
		cin >> mainMenu;

		switch(mainMenu) {
			case 1:
			case 2:
				processZip(mainMenu);
				break;
			default:
				if (mainMenu != 3)
					cout << "Invalid choice...\n";
				else
					cout << "\n";
		}
	} while (mainMenu != 3);

	return 0;
}

void processZip(int prompt) {
	string input;

	if(prompt == 1) {
		cout << "Enter a zip code in roman format (#####): ";
		cin >> input;

		Zipcode zip(input, ROMAN); 
	}
	else if(prompt == 2) {
		cout << "Enter a zip code in bar code format (1's and 0's): ";
		cin >> input;

		Zipcode zip(input, POSTNET);
	}
}
