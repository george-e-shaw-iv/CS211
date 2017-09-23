/*
 * Filename: program4.cpp 
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 4
 * Description: Vending Machine
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;

int menu(void);
int acceptMoney(int price);
int computeChange(int totalPaid, int totalPrice);
void dispenseChange(int change);

int main() {
	int selectionPrice, depositedMoney, change;
	char anotherPurchase = 'Y';

	while((char)toupper(anotherPurchase) == 'Y') {
		selectionPrice = menu();
		depositedMoney = acceptMoney(selectionPrice);
		change = computeChange(depositedMoney, selectionPrice);

		cout << endl << "Your total inserted:\t" << setw(3) << right << depositedMoney << " CENTS" << endl;
		dispenseChange(change);

		cout << "\nWould you care to make another purchase (Y/N): ";
		cin >> anotherPurchase;
		cout << endl;
	}

	cout << "Thank you and enjoy your purchase!\n";

	return 0;
}

int menu(void) {
	struct snack {
		char identifier;
		string name;
		float price;
	};

	snack snackArray[6] = {
		{ 'P', "Potato Chips", 1.25 },
		{ 'S', "Snickers Bar", 1.35 },
		{ 'T', "Pop Tart", .95 },
		{ 'C', "Cookies", 1.50 },
		{ 'B', "Brownie", 1.75 },
		{ 'N', "Nuts", 1.40 }
	};

	char selectionInput;
	snack validSnackSelection;
	unsigned int i;

	cout << "Avaliable snacks to select from:\n";
	for(i = 0; i < (sizeof(snackArray)/sizeof(*snackArray)); i++) {
		cout << "\t" << snackArray[i].identifier << " - ";
		cout << setw(16) << left  << snackArray[i].name;
		cout << "$" << setprecision(2) << fixed << snackArray[i].price << endl;
	}

	while(true) {
		bool validSelection = false; //Assume the selection is invalid at first

		cout << "Please enter the letter labeling your snack selection: ";
		cin >> selectionInput;

		for(i = 0; i < (sizeof(snackArray)/sizeof(*snackArray)); i++) {
			if(toupper(selectionInput) == snackArray[i].identifier) {
				validSelection = true;
				validSnackSelection = snackArray[i];
				break;
			}
		}

		if(validSelection) break;
		else cout << "Invalid selection!\n\n";
	}

	return ceil((snackArray[i].price) * 100);
}

int acceptMoney(int price) {
	struct money {
		char identifier;
		string name;
		int value;
	};

	money acceptedTypes[3] = {
		{ 'N', "Nickel", 5 },
		{ 'Q', "Quarter", 25 },
		{ 'D', "Dollar", 100 }
	};

	char selectionInput;
	int depositedMoney = 0;
	unsigned int i;

	cout << "\nMoney accepted by the machine:\n";
	for(i = 0; i < (sizeof(acceptedTypes)/sizeof(*acceptedTypes)); i++) {
		cout << "\t" << acceptedTypes[i].identifier << " - ";
		cout << acceptedTypes[i].name << endl;
	}

	while(depositedMoney < price) {
		bool validSelection = false; //Assume that the selection is invalid at first

		cout << "\nYour selected snack item cost:\t" << setw(3) << right << price << " CENTS\n";
		cout << "Your total inserted:\t\t" << setw(3) << right << depositedMoney << " CENTS\n";
		cout << "Insert amount (enter letter of choice): ";
		cin >> selectionInput;

		for(i = 0; i < (sizeof(acceptedTypes)/sizeof(*acceptedTypes)); i++) {
			if(toupper(selectionInput) == acceptedTypes[i].identifier) {
				depositedMoney += acceptedTypes[i].value;
				validSelection = true;
				break;
			}
		}

		if(!validSelection) cout << endl << (char)toupper(selectionInput) << " is not recognized as a coin.\n";
	}

	return depositedMoney;
}

int computeChange(int totalPaid, int totalPrice) {
	return (totalPaid - totalPrice);
}


/*
	Function that dispenses the least amount of coins as change

	This function assumes that the internal array 'acceptedTypes' is structured
	so that the coins are arranged from greatest to least in terms of value.
*/
void dispenseChange(int change) {
	if(change == 0) {
		cout << "No change needs to be dispensed.\n";
		return;
	}

	struct money {
		char identifier;
		string name;
		int value;
	};

	 money acceptedTypes[3] = {
		{ 'Q', "QUARTER", 25 },
		{ 'D', "DIME", 10 },
		{ 'N', "NICKEL", 5 }
	};

	int typeSize = sizeof(acceptedTypes)/sizeof(*acceptedTypes);

	/*
		Create an array whose keys coorespond to acceptedTypes keys
		that stores the amount of each acceptedType as change in it
	*/
	int coorespondingChangeAmount[typeSize];
	
	int remainingChange = change;
	unsigned int i;

	//Initialize all of their values as 0
	for(i = 0; i < (unsigned int)typeSize; i++) {
		coorespondingChangeAmount[i] = 0;
	}

	while(remainingChange != 0) {
		for(i = 0; i < (unsigned int)typeSize; i++) {
			if(remainingChange >= acceptedTypes[i].value) {
				remainingChange -= acceptedTypes[i].value;
				coorespondingChangeAmount[i]++;
				break;
			}
		}
	}

	cout << "Dispensing change:";
	for(i = 0; i < (unsigned int)typeSize; i++) {
		if(i == 0) cout << "\t";
		else cout << "\t\t\t";

		cout << setw(3) << right << coorespondingChangeAmount[i] << " ";

		if(coorespondingChangeAmount[i] > 1 || coorespondingChangeAmount[i] == 0) cout << acceptedTypes[i].name << "S";
		else cout << acceptedTypes[i].name;
			
		cout << endl;
	}
	cout << "Total change:\t\t" << setw(3) << right << change << " CENTS\n";

	return;
}
