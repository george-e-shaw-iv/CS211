/*
 * Filename: program5.cpp 
 * Name: George Shaw
 * WSUID: G829G576
 * HW#: 5
 * Description: A program that prints the lyrics to the song B-I-N-G-O.
 */

#include <iostream>

using namespace std;

void printArray(const char arr[]);

const int SIZE = 5;
const char dog[SIZE] = {'B', 'I', 'N', 'G', 'O'};

int main() {
	//Loop for main 6 verse blocks
	for(int i = 0; i <= SIZE; i++) {
		cout << "There was a farmer had a dog\nand ";
		printArray(dog);
		cout << "was his name-o\n";

		//Loop for the 3 occurences of B-I-N-G-O per verse
		for(int count = 0; count < 3; count++) {
			for(int star = 0; star < i; star++) {
				cout << "* ";
			}
			for(int letter = i; letter < SIZE; letter++) {
				cout << dog[letter] << " ";
			}
			cout << "\n";
		}

		cout << "And ";
		printArray(dog);
		cout << "was his name-o\n\n";
	}

	return 0;
}

//Function to print array
void printArray(const char arr[]) {
	for(unsigned int i = 0; i <= (sizeof(arr)/sizeof(*arr)); i++) {
		cout << arr[i] << " ";
	}
}
