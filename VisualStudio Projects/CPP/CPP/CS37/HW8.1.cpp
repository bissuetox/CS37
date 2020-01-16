#include <iostream>
#include <string>
using namespace std;
// program that prompts user for first and last name, and address, zip, city and state, then prints it back. 
// the catch is that the zipcode is a separate class that is instantiated inside of the person class

// zipcode class definition
class Zipcode {
private:
	int zip;
	string city, state;
public:
	Zipcode();
	Zipcode(int izip, string icity, string istate);
	int getZip();
	string getCity();
	string getState();
	void setZip(int izip);
	void setCity(string icity);
	void setState(string istate);
};

// default constructor
Zipcode::Zipcode() {
	zip = 0;
	city = "";
	state = "";
}

// parameterized constructor
Zipcode::Zipcode(int izip, string icity, string istate) {
	zip = izip;
	city = icity;
	state = istate;
}

// standard getters
int Zipcode::getZip() {
	return zip;
}

string Zipcode::getCity() {
	return city;
}

string Zipcode::getState() {
	return state;
}

// standard setters
void Zipcode::setZip(int izip) {
	zip = izip;
}

void Zipcode::setCity(string icity) {
	city = icity;
}

void Zipcode::setState(string istate) {
	state = istate;
}

// person class definition
class Person {
private:
	string first, last, address;
	Zipcode classZipcode; // instantiates classZipcode object - we can now call zipcode class member functions
public:
	Person(string ifirst, string ilast, string iaddress, int izip, string icity, string istate);
	string getFirst();
	string getLast();
	string getAddress();
	int getZip();
	string getCity();
	string getState();
	
	void setFirst(string ifirst);
	void setLast(string ilast);
	void setAddress(string iaddress);
	void setZip(int izip);
	void setCity(string icity);
	void setState(string istate);
};

// person constructor with all fields including zip code fields
Person::Person(string ifirst, string ilast, string iaddress, int izip, string icity, string istate) {
	first = ifirst;
	last = ilast;
	address = iaddress;
	classZipcode.setZip(izip); // uses zipcode class member function calls to set zip, city and state
	classZipcode.setCity(icity);
	classZipcode.setState(istate);
}

// standard getters 
string Person::getFirst() {
	return first;
}

string Person::getLast() {
	return last;
}

string Person::getAddress() {
	return address;
}

// getters that call zipcode getter member functions
int Person::getZip() {
	return classZipcode.getZip();
}

string Person::getCity() {
	return classZipcode.getCity();
}

string Person::getState() {
	return classZipcode.getState();
}

// standard setters
void Person::setFirst(string ifirst) {
	first = ifirst;
}

void Person::setLast(string ilast) {
	last = ilast;
}

void Person::setAddress(string iaddress) {
	address = iaddress;
}

// setters that call zipcode setter member functions
void Person::setZip(int izip) {
	classZipcode.setZip(izip);
}

void Person::setCity(string icity) {
	classZipcode.setCity(icity);
}

void Person::setState(string istate) {
	classZipcode.setState(istate);
}

// main function
int main() {
	string ifirst, ilast, iaddress, icity, istate;
	int izip;

	// prompt for all info and store in temporary variables
	cout << "Enter First Name: ";
	getline(cin, ifirst);
	cout << "Enter Last Name: ";
	getline(cin, ilast);
	cout << "Enter Address: ";
	getline(cin, iaddress);
	cout << "Enter Zip Code: ";
	cin >> izip;
	cin.ignore();
	cout << "Enter City: ";
	getline(cin, icity);
	cout << "Enter State: ";
	getline(cin, istate);

	Person p1(ifirst, ilast, iaddress, izip, icity, istate); // calls person constructor with user inputted values

	// print all the info inputted
	cout << "First Name: " << p1.getFirst() << endl;
	cout << "Last Name: " << p1.getLast() << endl;
	cout << "Address: " << p1.getAddress() << endl;
	cout << "Zip Code: " << p1.getZip() << endl;
	cout << "City: " << p1.getCity() << endl;
	cout << "State: " << p1.getState() << endl;
}