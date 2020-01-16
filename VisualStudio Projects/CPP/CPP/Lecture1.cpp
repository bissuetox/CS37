#include <iostream>

// Bubble Sort
/*
int main() { // Suppose array size = n
	for (int i = 0; i < array.size; i++) { // Executes n times
		for (int j = 0; j < array.size - i, j++) { // Executes n times

		} // Exucutes n^2 times - O(n^2)
		
	}
}
*/

// Recursion

int sum(int n) {
	if (n == 1) {
		return(1);
	}
	return (n + sum(n - 1));
}