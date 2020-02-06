#include <iostream>
#include <string>
#define SIZE 100
using namespace std;


int main() {
	char sentence[SIZE];							// Initial load char array
	cout << "Enter a sentence: " << endl;
	cin.get(sentence, SIZE);						// Get whole line into sentence array

	size_t floatSize = 0;							// Keep track of amount of digits after first digit
	for (int i = 0; sentence[i] != '\0'; i++) {		// While end of array is not hit
		if (sentence[i] == ' ') {					// Check if hit delimiter
			cout << endl;							// Print endline
			continue;
		}

		else if (sentence[i] >= '0' && sentence[i] <= '9' || sentence[i] == '.') { // Check if it is a digit
			char* fAddy = &sentence[i];				// Set pointer to address of first digit for reference
			do {
				i++;								// Increase i to continue iterating through the sentence
				floatSize++;						// Add 1 to float size
			} while (sentence[i] >= '0' && sentence[i] <= '9' || sentence[i] == '.');
			i--;									// Take into account the for loop i++
			cout << stof(fAddy, &floatSize) * 2;	 // Print converted float from: first digit to # floatSize of characters after
		}
		else {
			cout << sentence[i]; // Print letter normally
		}

	}
}
