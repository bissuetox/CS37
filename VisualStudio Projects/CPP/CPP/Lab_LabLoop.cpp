#include <iostream>
using namespace std;

int sum(int n) {
	int sum = 0;
	for (n; n >= 1; n--) { // Start at n, keep looping until hits zero, decrease n by one each loop
		sum += n; // add n to the sum
	}
	return sum; // return the sum
}

int main() {
	cout << "Sum of 6: " << sum(6) << endl; // Test print statement
}