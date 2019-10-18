//--------------------------------------------------------//
// Name:  Chris Kruki                                     //
// Assignment: #2                                         //
//--------------------------------------------------------//

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

class Box
{
	
public:
	Box();
	static float totalVolume, minLength, minWidth, minHeight, minVolume;

	float getHeight()const;
	float getLength()const;
	float getWidth()const;
	float getVolume()const;		// must be used

	string getDescription()const;

	void setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height);

private:
	string description;
	float height, length, width, volume; 
	float maxX, maxY, maxZ, minX, minY, minZ;
};

Box::Box() {
	volume = 0;
	description = "";
	height = 0;
	length = 0;
	width = 0;
}

float Box::getHeight()const {
	return height;
}

float Box::getLength()const {
	return length;
}

float Box::getWidth()const {
	return width;
}

string Box::getDescription()const {
	return description;
}

float Box::getVolume()const {
	return volume;
}

void Box::setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height) {
	description = func_description;
	height = func_height;
	if (func_x1 == func_x3 && func_x2 == func_x4) {
		if (func_y1 == func_y2 && func_y3 == func_y4) {
			cout << "Is Square." << endl;
			length = abs(func_x2 - func_x1);
			width = abs(func_y3 - func_y1);
			volume = length * width * height;
			cout << "1: " << length << " " << width << " " << height << endl;

		}
		else if (func_y1 == func_y4 && func_y3 == func_y2) {
			cout << "Is Square." << endl;
			length = abs(func_x4 - func_x1);
			width = abs(func_y1 - func_y3);
			volume = length * width * height;
			cout << "2: " << length << " " << width << " " << height << endl;
		}
	}
	else if (func_x1 == func_x4 && func_x2 == func_x3) {
		if (func_y1 == func_y2 && func_y3 == func_y4) {
			cout << "Is Square." << endl;
			length = abs(func_x2 - func_x1);
			width = abs(func_y1 - func_y4);
			volume = length * width * height;
			cout << "3: " << length << " " << width << " " << height << endl;
		}
		else if (func_y1 == func_y3 && func_y2 == func_y4) {
			cout << "Is Square." << endl;
			length = abs(func_x1 - func_x3);
			width = abs(func_y1 - func_y4);
			volume = length * width * height;
			cout << "4: " << length << " " << width << " " << height << endl;
		}
	}
	else if (func_x1 == func_x2 && func_x3 == func_x4) {
		if (func_y2 == func_y3 && func_y1 == func_y4) {
			cout << "Is Square." << endl;
			length = abs(func_x3 - func_x2);
			width = abs(func_y2 - func_y1);
			volume = length * width * height;
			cout << "5: " << length << " " << width << " " << height << endl;
		}
		else if (func_y1 == func_y3 && func_y2 == func_y4) {
			cout << "Is Square." << endl;
			length = abs(func_x4 - func_x2);
			width = abs(func_y2 - func_y1);
			volume = length * width * height;
			cout << "6: " << length << " " << width << " " << height << endl;
		}
	}
	else {
		cout << "Not a square!" << endl;
		length = 0;
		width = 0;
		volume = 0;
	}

	totalVolume += volume;
}

void positionCheck(const Box funcBox[], int i) {
	if (i == 0) {
		Box::minWidth = funcBox[i].getWidth();
		Box::minLength = funcBox[i].getLength();
		Box::minHeight = funcBox[i].getHeight();
	}
	else if (funcBox[i].getHeight() <= funcBox[i - 1].getHeight()) {
		if (abs(funcBox[i].getLength() - funcBox[i - 1].getLength()) > abs(funcBox[i].getWidth() - funcBox[i - 1].getWidth())) {
			Box::minWidth += funcBox[i].getWidth();
		}
		else
			Box::minLength += funcBox[i].getLength();
	}
	else
		Box::minHeight += funcBox[i].getHeight();
}

istream& operator>>(istream& input, Box &funcBox); // insertion operator overloaded function prototype
ostream& operator<<(ostream& output, Box funcBox); // extraction operator overloaded function prototype

void loadBoxes(Box funcBox[]) {
	for (int i = 0; i < 10; i++) {
		cout << "Enter Box " << i + 1 << " info in format" << endl << "Name" << endl << "a,b  c,d  e,f  g,h  height" << endl;
		cin >> funcBox[i];
		cout << endl;
		positionCheck(funcBox, i);
	}
	Box::minVolume = Box::minHeight * Box::minLength * Box::minWidth;
}

void printBoxes(Box funcBox[]) {
	cout << left << setw(10) << "Box#" << left << setw(17) << "Description" << left << setw(17) << "Volume(cu/units)" << endl;
	for (int j = 0; j < 10; j++) {
		cout << left << setw(10) << j << left << setw(17) << funcBox[j].getDescription() << left << setw(17) << funcBox[j].getVolume() << endl;
	}
	cout << "Total Volume of the boxes is: " << fixed << setprecision(1) << Box::totalVolume << endl;
}

void printResults(Box funcBox[]) {
	cout << endl << "Minimum container specifications: " << endl;
	cout << fixed << "Length: " << setprecision(1) << Box::minLength << " Width: " << Box::minWidth << " Height: " << Box::minHeight << " Volume: " << Box::minVolume << endl;
}

float Box::totalVolume = 0;
float Box::minLength = 0;
float Box::minWidth = 0;
float Box::minHeight = 0;
float Box::minVolume = 0;

int main()
{
	//declare an array to hold objects of type Box
	Box boxArray[10];

	//call a global function to load the user input into each object -- use overloaded stream extraction operator
	loadBoxes(boxArray);

	//call a global function to print results for part #1 and #2
	printBoxes(boxArray);
	//call a global function to print results for part #3 -- use overloaded stream insertion operator
	printResults(boxArray);
	//print the results for part #4
	float efficiency = Box::totalVolume / Box::minVolume;
}

// insertion operator overloaded function definition
// extracts input in the format x,y x,y x,y x,y height
istream& operator>>(istream& input, Box &funcBox) {
	string description;
	float x1, x2, x3, x4, y1, y2, y3, y4, height;
	input.ignore();
	getline(input, description);
	input >> x1; // input into first x
	//input.ignore(); // ignore comma
	input >> y1; // input into first y
	input >> x2; // etc
	//input.ignore();
	input >> y2;
	input >> x3;
	//input.ignore();
	input >> y3;
	input >> x4;
	//input.ignore();
	input >> y4;
	input >> height;
	funcBox.setData(description, x1, y1, x2, y2, x3, y3, x4, y4, height);
	return input;
}
ostream& operator<<(ostream& output, Box funcBox) {
	output << "Minimum container specifications: " << endl;
	output << "Length: " << funcBox.getLength() << "Width: " << funcBox.getWidth() << "Height: " << funcBox.getHeight() << "Volume: " << funcBox.getVolume() << endl;
	return output;
}

/*

Results go here!

*/