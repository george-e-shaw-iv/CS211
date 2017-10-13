/*
 * Filename: program6.cpp 
 * Name: George Shaw
 * WSUID: G829G576
 * HW#: 6
 * Description: Caesar Shift (EC: Rail-fence cipher)
 */

#include <iostream>
#include <ctype.h>
#include <cstring>

using namespace std;

const int SIZE = 200;
const int SHIFT = 4;

void caesarEncode(char (&message)[SIZE], char delimeter, int cShift, int arrSize);
void caesarDecode(char (&message)[SIZE], char delimeter, int cShift, int arrSize);
void railFenceEncode(char (&message)[SIZE], char delimeter, int layers, int arrSize);
void railFenceDecode(char (&message)[SIZE], char delimeter, int layers, int arrSize);
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

	caesarEncode(message, '\0', SHIFT, SIZE);
	railFenceEncode(message, '\0', 2, SIZE);
	printArray(message, '\0', SIZE);
	cout << endl;

	railFenceDecode(message, '\0', 2, SIZE);
	caesarDecode(message, '\0', SHIFT, SIZE);
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
void caesarEncode(char (&message)[SIZE], char delimeter, int cShift, int arrSize) {
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
void caesarDecode(char (&message)[SIZE], char delimeter, int cShift, int arrSize) {
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

/**/
void railFenceEncode(char (&message)[SIZE], char delimeter, int layers, int arrSize) {
	char msgCopy[SIZE];
	int curPos = 0;
	int delimeterPos;

	for(int i = 0; i < arrSize; i++) {
		if(message[i] == delimeter) {
			delimeterPos = i;
			break;
		}
		else {
			msgCopy[i] = message[i];
		}
	}

	for(int i = 0; i < layers; i++) {
		for(int j = i; j < delimeterPos; j = j + layers) {
			message[curPos] = msgCopy[j];
			curPos++;
		}
	}
}

/**/
void railFenceDecode(char (&message)[SIZE], char delimeter, int layers, int arrSize) {
	char msgCopy[SIZE];
	int delimeterPos;

	for(int i = 0; i < arrSize; i++) {
		if(message[i] == delimeter) {
			delimeterPos = i;
			break;
		}
		else {
			msgCopy[i] = message[i];
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
