/*
 * Filename: program6.cpp 
 * Name: George Shaw
 * WSUID: G829G576
 * HW#: 6
 * Description: Caesar Shift (EC: Rail-fence cipher)
 */

#include <iostream>
#include <ctype.h>

using namespace std;

const int SIZE = 200;
const int SHIFT = 4;

void encode(char (&message)[SIZE], char delimeter, int cShift, int arrSize);
void decode(char (&message)[SIZE], char delimeter, int cShift, int arrSize);
void printArray(char array[], char delimeter, int arrSize);

int main() {
	char message[SIZE];

	cout << "Please enter a message (" << SIZE << " character limit): ";
	cin.get(message, SIZE);
	cout << endl;

	// Uppercase the character array
	for(int i = 0; i < SIZE; i++) {
		if(message[i] == '\0') break;
		else message[i] = toupper(message[i]);
	}

	printArray(message, '\0', SIZE);
	cout << endl;

	encode(message, '\0', SHIFT, SIZE);
	printArray(message, '\0', SIZE);
	cout << endl;

	decode(message, '\0', SHIFT, SIZE);
	printArray(message, '\0', SIZE);
	cout << endl;

	return 0;
}

/*
	A function used to encode messages using caesar shift

	@param char message[200]
		The message to encode, passes by reference
	@param char delimeter
		The delimeter denoting the end of written data to the array
	@param int cShift
		The shift value used to encode the message
	@param int arrSize
		The size of the input array
	
	@return void
 */
void encode(char (&message)[SIZE], char delimeter, int cShift, int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		if(message[i] == delimeter) {
			break;
		}
		else {
			int int_val = message[i];

			if(int_val < 65 || int_val > 90) {
				continue;
			}
			else {
				int_val += cShift;
				while(int_val > 90) {
					int_val -= 26;
				}

				message[i] = int_val;
			}
		}
	}
}

/*
	A function to decode messages encoded in caesar shift

	@param char message[200]
		The message to decode, passes by reference
	@param char delimeter
		The delimeter denoting the end of written data to the array
	@param int cShift
		The shift value used to decode the message
	@param int arrSize
		The size of the input array
	
	@return
 */
void decode(char (&message)[SIZE], char delimeter, int cShift, int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		if(message[i] == delimeter) {
			break;
		}
		else {
			int int_val = message[i];

			if(int_val < 65 || int_val > 90) {
				continue;
			}
			else {
				int_val -= cShift;
				while(int_val < 65) {
					int_val += 26;
				}

				message[i] = int_val;
			}
		}
	}
}

/*
	A function used to print a character array

	@param char array[]
		The array to be printed
	@param char delimeter
		The delimeter denoting the end of written data to the array
	@param int arrSize
		The size of the input array

	@return
		void
 */
void printArray(char array[], char delimeter, int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		if(array[i] == delimeter) break;
		else cout << array[i];
	}
}
