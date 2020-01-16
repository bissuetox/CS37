#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
class Point {
private:
	const int x; // if you have const data members, then a regular constructor cannot modify these values as soon as an obj is instantiated
	const int y; // to work around this, you can use a constructor initializer list
public:
	Point(int nx, int ny);
	void setX(int nx);
	int getX(const int x);
};

Point::Point(int nx, int ny) : x(nx), y(ny) {}

Point::setX(const int& nx) { // translates to setX(const Point *this, const int& nx) in the eyes of the compiler
//const to honor principle of least privilege, and use ampersand so the function doesnt
// create a new copy of the nx variable, it references to the origianlly passed x address
	x = nx; // this is illegal because x is a const variable
}
*/

int main() {
	ofstream fileOut("C:\\Users\\jovin\\Documents\\School\\CPP\\CS37\\myFile.txt");
	if (fileOut.is_open()) {
		fileOut << "Output line1. " << endl;
		fileOut << "Output line2. " << endl;
		cout << "written." << endl;
	}
	else {
		cerr << "File is not open!" << endl; // cerr acts pretty much like cout 
		exit(1); // exit with 1 means failure, exit with 0 is success
	}
	fileOut.close();

	string tempstring;

	ifstream fileIn("C:\\Users\\jovin\\Documents\\School\\CPP\\CS37\\myFile.txt");
	if (fileIn.is_open()) {
		//fileIn >> tempstring; // >> extraction operator stops at whitespace, and if file is separated by only white space,
		//cout << tempstring << endl; // we want to use getline(fileIn, tempstring);
		getline(fileIn, tempstring);
		cout << tempstring << endl;
		getline(fileIn, tempstring);
		cout << tempstring << endl;
	}
}

