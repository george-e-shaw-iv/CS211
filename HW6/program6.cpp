/*
 * Filename: program6.cpp 
 * Name: George Shaw
 * WSUID: G829G576
 * HW#: 6
 * Description: Caesar Shift (EC: Rail-fence cipher)
 */

#include <iostream>

using namespace std;

const int SIZE = 200;
const int SHIFT = 4;

void encode(char &message[], int shift);
void decode(char &message[], int shift);
void printArray(char array[], char delimeter);

int main() {
	char message[SIZE];

	cout << "Please enter a message (200 character limit): ";
	cin.get(message, SIZE);
	cout << endl;

	printArray(message, '\0');
	cout << endl;

	return 0;
}

/*
	A function used to encode messages using caesar shift

	@param char message[]
		The message to encode, passes by reference
	@param int shift
		The shift value used to encode the message
	
	@return void
 */
void encode(char &message[], int shift) {

}

/*
	A function to decode messages encoded in caesar shift

	@param char message[]
		The message to decode, passes by reference
	@param int shift
		The shift value used to decode the message
	
	@return
 */
void decode(char &message[], int shift) {

}

/*
	A function used to print a character array

	@param char array[]
		The array to be printed
	@param char delimeter
		The delimeter denoting the end of written data to the array

	@return
		void
 */
void printArray(char array[], char delimeter) {
	for(unsigned int i = 0; i < (sizeof(array)/sizeof(*array)); i++) {
		if(array[i] == delimeter) break;
		else cout << array[i];
	}
}
