#include <iostream>

// Bubble Sort
/*
int main() { // Suppose array size = n
	int secondloop = 0;
	for (int i = 0; i < array.size; i++) { // Executes n times
		for (int j = 0; j < array.size - i, j++) { // Executes n times

		} // Inner for loop - Exucutes n^2 times - O(n^2) // n^2 operations
		secondloop++;
		// Outer for loop - executes n times - O(n) // n operations
	}
	Total = sum + secondloop; // this is 1 operation


	Functional Notation of this function = n^2 + n + 1 
}
*/

// Recursion

int sum(int n) {
	if (n == 1) {
		return(1);
	}
	return (n + sum(n - 1));
}