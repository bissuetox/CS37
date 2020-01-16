#include <iostream>
#include <stdexcept>
using namespace std;

class DivideByZeroException : public runtime_error { // Derived class of runtime_error
	// runtime_error is a derived class of exception
public:
	DivideByZeroException() : runtime_error("Divide by zero attempted") {} // runtime_error constructor that sets the description
	// of the exception
};

double quotient(int num, int denom) {
	if (denom == 0)
		throw DivideByZeroException(); // Technically a constructor call to instantiate an unanamed exception object 
	return static_cast<double>(num) / denom; // Casts num to a double - compiler implicitly converts denom to a double as well
}

int main() {
	int num1, num2, good = 0;

	while (good == 0) {
		try {
			cout << "Enter 2 integers: ";
			cin >> num1 >> num2;
			double result; // result is only visible inside of the try block - not visible in main
			result = quotient(num1, num2);
			cout << "The quotient is: " << result << endl;
			good = 1;
		}
		catch (DivideByZeroException& error) { // Most specific catch clause - specific for DivideByZeroException
			cout << "Divide by zero exception caught" << endl;
		}

		catch (exception& error) { // This is a polymorphism call - this catches the DivideByZeroException class which is
			// a derived class of exception - nifty!
			cout << "Exception: " << error.what() << endl; // what() is a member function of exception that returns
			// a description of the exception
		}

		catch (...) { // Catch Anything
			cout << "Default catch clause caught. " << endl;
		}
	}



}