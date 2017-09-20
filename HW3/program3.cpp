/*
 * Filename: homework03_code.cpp
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 3
 * Description: A loan calculator that uses a given loan, rate, and monthly payment to make calculations for 3 years.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double loanAmount, interestRate, monthlyPayment, monthlyInterest, monthlyPrincipal;
	double yearTotalInterest, yearTotalPrincipal;

	cout << "Enter amount of loan: ";
	cin >> loanAmount;

	cout << "Enter interest rate: ";
	cin >> interestRate;

	if(interestRate > 1) interestRate = (interestRate / 100.00);

	cout << "Enter monthly payment: ";
	cin >> monthlyPayment;

	cout << endl;

	for(int year = 1; year <= 3; year++) {
		yearTotalInterest = yearTotalPrincipal = 0;

		cout << "Year " << year << "\t\t\tInterest\tPrinicipal\n";
		cout << "\t\t---\t--------\t----------\n";

		for(int month = 1; month <= 12; month++) {
			monthlyInterest = ((loanAmount * interestRate) / 12.0);
			monthlyPrincipal = (monthlyPayment - monthlyInterest);
			loanAmount -= monthlyPrincipal;

			cout << "\t\t" << right << setw(2) << month << ":";
			cout << "\t" << right << setw(8) << setprecision(2) << fixed << monthlyInterest;
			cout << "\t" << right << setw(10) << setprecision(2) << fixed << monthlyPrincipal;
			cout << endl;

			yearTotalInterest += monthlyInterest;
			yearTotalPrincipal += monthlyPrincipal;
		}

		cout << "\t\t---\t--------\t----------\n";
		cout << "Year " << year << " totals:";
		cout << "\t\t" << right << setw(8) << setprecision(2) << fixed << yearTotalInterest;
		cout << "\t" << right << setw(10) << setprecision(2) << fixed << yearTotalPrincipal;
		cout << "\nRemaining balance at year end:\t\t" << right << setw(10) << setprecision(2) << fixed << loanAmount;
		cout << endl << endl;
	}

	return 0;
}
