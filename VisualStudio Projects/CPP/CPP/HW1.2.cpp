#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Program that retrieves name, age, address and salary from the user, then prints it in a specified format

int main() {
	string name;
	int age;
	string address;
	float salary; // declare all variables


	cout << "Enter your full name: ";
	getline(cin, name);
	cout << "Enter your age: ";
	cin >> age; // get age 
	cin.ignore(); // delete the newline after age is inputted, otherwise getline will not read, since it hits a newline.
	cout << "Enter your address: ";
	getline(cin, address); // get full line of address 
	cout << "Enter your Salary: ";
	cin >> salary; // get salary

	cout << left << setw(20) << name; // print name left justified in field of 20
	cout << left << setw(20) << address; // print address left justified in field of 20
	cout << setw(5) << right << age; // print age right justified in field of 5
	cout << setw(10) << setprecision(2) << fixed << salary; // print salary right justified in field of 10, fixed and precision of 2

}