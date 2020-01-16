#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// program that prompts user for 2 integers, then displays the sum, product, and quotient

int main() {
	int num1, num2; // declare two number variables
	cout << "Enter 2 integers on the same line : ";
	cin >> num1 >> num2; // get 2 integers and put into num1 and num2

	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl; // print arithmetic equations
}