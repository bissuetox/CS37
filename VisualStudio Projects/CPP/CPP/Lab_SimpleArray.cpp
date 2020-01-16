#include <iostream>
#define SIZE 5
using namespace std;

int main() {
	int ints[SIZE];

	for (int i = 0; i < SIZE; i++) { // Loop through to get typed ints into array
		cout << "Enter an integer: ";
		cin >> ints[i];
	}

	cout << "Ints: ";
	for (int j = 0; j < SIZE; j++) { // Loop to print ints
		cout << ints[j] << " ";
	}
}