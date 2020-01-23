#include <iostream>
using namespace std;

int main() {
	int arraySize;									// Array size int
	int arrayPop = 0;								// Array population int

	cout << "Enter an initial array size: ";		// Get initial array size
	cin >> arraySize;
	int* array1 = new int[arraySize] {};			// Initialize array from initial array size
	for (int i = 0; i < arraySize; i++){
		if (i == arraySize - 1) {					// If the for loop iteration reaches 1 before the array size
			int* tempArray = new int[arraySize];	// Declare a temp array
			int oldSize = arraySize;				// Init the current size into var
			for (int j = 0; j < arraySize; j++) {
				tempArray[j] = array1[j];			// Loop to copy array into a temp array;
			}
			arraySize = arraySize + 5;				// Expand array size by 5
			array1 = new int[arraySize] {};			// Reallocate array of bigger size under same var

			for (int k = 0; k < oldSize; k++) {
				array1[k] = tempArray[k];			// Copy temp array into new array
			}

			cout << "\nNew Array assigned" << endl;
		}

		cout << "Enter int: ";		// Call to populate array with int
		cin >> array1[i];			
		arrayPop++;					// Increase arrayPop by 1 to keep track of # of inputted ints (exclusive of loop)
	
		if (array1[i] == (-1)) {	// If input is -1
			arrayPop--;				// Decrease array pop by 1 so the output doesn't include -1
			break;					// Break the loop
		}
	}

	cout << "Array contents: " << endl;		// Print array contents
	for (int i = 0; i < arrayPop; i++) {	// For loop to loop through array population, not array size
		cout << array1[i] << " ";			// This excludes the unfilled array spots
	}
}