/*
 * Filename: program10.cpp
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 10
 * Description: Numerical zip code to postnet converter and vice versa.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

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
		string postnet, barcode[2][27], file_name;
		ofstream file;

		void setPostnet() {
			if(this->roman == 0) return;

			this->postnet = "1";
			string temp;

			for(char c : to_string(this->roman)) {
				int i = c - '0';
				temp = "";

				if(i == 0) {
					temp = "11000";
				}
				else {
					if(i >= 7) {
						temp += "1";
						i -= 7;
					}
					else {
						temp += "0";
					}

					if(i >= 4) {
						temp += "1";
						i -= 4;
					}
					else {
						temp += "0";
					}

					if(i >= 2) {
						temp += "1";
						i -= 2;
					}
					else {
						temp += "0";
					}

					if(i >= 1) temp += "1";
					else temp += "0";

					if(count(temp.begin(), temp.end(), '1') == 1) temp += "1";
					else temp += "0";
				}

				this->postnet += temp;
			}

			this->postnet += "1";
		}

		void setRoman() {
			if(this->postnet == "") return;

			string m_postnet = this->postnet.substr(1, this->postnet.size() - 1);
			int count = 0, roman_digit = 0;
			this->roman = 0;

			for(char c : m_postnet) {
				if(count == 5) {
					if(roman_digit == 11) roman_digit = 0;

					this->roman = stoi(to_string(this->roman) += to_string(roman_digit));

					roman_digit = 0;
					count = 0;
				}

				if(c == '0') {
					count++;
					continue;
				}

				switch(count) {
					case 0:
						roman_digit += 7;
						break;
					case 1:
						roman_digit += 4;
						break;
					case 2:
						roman_digit += 2;
						break;
					case 3:
						roman_digit += 1;
						break;
					case 4:
						break;
				}

				count++;
			}
		}

		void setBarcode() {
			if(this->postnet == "") return;

			string m_postnet = this->postnet.substr(1, this->postnet.size() - 1);
			int pos = 0;

			this->barcode[0][pos] = "|";
			this->barcode[1][pos] = "|";
			pos++;

			for(char c : m_postnet) {
				switch(c) {
					case '0':
						this->barcode[0][pos] = " ";
						this->barcode[1][pos] = "|";
						break;
					case '1':
						this->barcode[0][pos] = "|";
						this->barcode[1][pos] = "|";
						break;
				}
				pos++;
			}

			this->barcode[0][pos] = "|";
			this->barcode[0][pos] = "|";
		}

		void CreateFile() {
			if(this->roman == 0) return;

			this->file_name = to_string(this->roman) + ".txt";
			file.open(file_name, ofstream::out | ofstream::trunc);
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

		~Zipcode() {
			file.close();
		}

		int GetRoman() {
			return this->roman;
		}

		string GetPOSTNET() {
			return this->postnet;
		}

		void PrintBarcode(destination dest) {
			if(this->barcode[0][0] == "") return;

			switch(dest) {
				case CONSOLE:
					for(int i = 0; i < 2; i++) {
						for(int ii = 0; ii < 27; ii++) {
							cout << this->barcode[i][ii] << " ";
						}
						cout << "\n";
					}
					break;
				case TEXT_FILE:
					if(!file.is_open()) CreateFile();
					
					for(int i = 0; i < 2; i++) {
						for(int ii = 0; ii < 27; ii++) {
							file << this->barcode[i][ii] << " ";
						}
						file << "\n";
					}

					cout << "Your zip code was saved in the file " << this->file_name << endl;

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
		cout << endl << "Enter a zip code in roman format (#####): ";
		cin >> input;

		Zipcode zip(input, ROMAN);

		cout << endl << "Your zip code is " << zip.GetRoman() << ", and the bar code looks like this:" << endl << endl;

		zip.PrintBarcode(CONSOLE);
		cout << endl;
		zip.PrintBarcode(TEXT_FILE);
	}
	else if(prompt == 2) {
		cout << endl << "Enter a zip code in bar code format (1's and 0's): ";
		cin >> input;

		Zipcode zip(input, POSTNET);
		
		cout << endl << "Your zip code is " << zip.GetRoman() << ", and the bar code looks like this:" << endl << endl;

		zip.PrintBarcode(CONSOLE);
		cout << endl;
		zip.PrintBarcode(TEXT_FILE);
	}
}
