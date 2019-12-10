/*Program that exercises exception handling - Retrieves two ints from the user and attempts to return the sum - 
if the sum is > 1024, throws a user defined sumException. Else, prints the sum */
#include <iostream>
#include <stdexcept>
using namespace std;

// sumException class definition - is a runtime_error
class sumException : public runtime_error {
public:
	sumException() : runtime_error("Sum was over 1024 - sumException") {}
};

void loadNums(int& num1, int& num2);
int getSum(const int& num1, const int& num2);

int main() {
	int num1, num2;
	loadNums(num1, num2);
	// Try getting the sum - if exception thrown refer to following catch clauses
	try {
		cout << "Sum: " << getSum(num1, num2) << endl;
	}
	// sumException catch clause - most specific first
	catch (sumException sumEx) {
		cout << sumEx.what() << endl;
	}
	// Default/general catch clause in case any other exception is thrown.
	catch (...) {
		cout << "Default exception caught." << endl;
	}
}

// Load nums function - gets two ints from the user and loads them into reference parameters
void loadNums(int& num1, int& num2) {
	cout << "Enter 2 integers: ";
	cin >> num1 >> num2;
}

// get Sum function - returns the sum of the numbers if < 1024, and throws a sumException if over 1024
int getSum(const int& num1, const int& num2) {
	int sum = num1 + num2;
	if (sum > 1024) {
		throw sumException();
	}
	else {
		return sum;
	}
}