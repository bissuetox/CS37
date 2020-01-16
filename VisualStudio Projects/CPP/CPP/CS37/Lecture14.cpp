#include <iostream>
#include <stdexcept>
using namespace std;

/*
// generic representation of some random functions - 
int f1(int in, int& out);
int f2(int in, int& out);
int f3(int in, int& out);

int main() {
	// old style of handling exceptions
	int i = 0, j = 0, errcode;
	errcode = f1(i, j);
	if (errcode == 0) {
		errcode = f2(i, j);
		if (errcode == 0) {
			errcode = f3(i, j);
		}
	}
	}
}
*/

/*
// Simple exception handling example
int main() {
	int x = -1;
	try {
		cout << "In Try block" << endl;
		if (x < 0) {
			throw x; // Simulation that exception was thrown - couldn't be handled
			// throws an int - must be caught by a catch (int)
			cout << "After throw - line is never executed" << endl; // This will never be execute
			// because execution stops after the throw and the compiler searches for a catch clause
		}
	}
	catch (int ecode) { // must catch the same type as what was thrown - int in this case
		// ecode - name of the int doesn't matter - just used in case we want to use that exception object
		cout << "Exception caught/ handled" << endl;
	}
	
	cout << "Continue exeuction after exception caught." << endl;
}
*/


// Exception Handling

class DivideByZeroException : public runtime_error { // Derived class of runtime_error
	// runtime_error is a derived class of exception
public:
	DivideByZeroException() : runtime_error("Divide by zero attempted") {} // runtime_error constructor that sets the description
	// of the exception
};

double quotient(int num, int denom) {
	if (denom == 0)
		throw DivideByZeroException(); // Technically a constructor call to instantiate an unanamed exception object 
	// After this is thrown, execution stops and starts looking for the catch block
	// Starts in the try scope, then searches after
	throw 1;
	return static_cast<double>(num) / denom; // Casts num to a double - compiler implicitly converts denom to a double as well
}

int main() {
	int num1, num2;
	cout << "Enter 2 integers: ";
	cin >> num1 >> num2;

	try {
		double result; // result is only visible inside of the try block - not visible in main
		result = quotient(num1, num2);
		cout << "The quotient is: " << result << endl; // Therefore, any statement that relies on things above them
		// should be placed inside of the try block and below the potential error throwing statement
		// This prevents the above cout statement from throwing bogus "result" data
	} // When the try block comes to the end - any variables or objects instantiated will be destructed

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