//--------------------------------------------------------//
// Name:  Chris Kruki                                     //
// Assignment: #2                                         //
//--------------------------------------------------------//

#define COUNT_BOXES 1
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// class definition
class Box
{
public:
	Box();
	Box(float imaxX, float imaxY, float imaxZ);
	void setMaxX(float x1, float x2, float x3, float x4);
	void setMaxY(float y1, float y2, float y3, float y4);
	void setMinX(float x1, float x2, float x3, float x4);
	void setMinY(float y1, float y2, float y3, float y4);

	float getMaxX();
	float getMaxY();
	float getMaxZ();
	float getMinX();
	float getMinY();

	float getHeight()const;
	float getLength()const;
	float getWidth()const;
	float getVolume()const;		// must be used

	string getDescription()const;

	void setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height);

private:
	string description;
	float maxX, maxY, maxZ, minX, minY, volume;
};

Box::Box() {
	description = "";
	maxX = 0;
	maxY = 0;
	maxZ = 0;
	minX = 0;
}

Box::Box(float imaxX, float imaxY, float imaxZ) {
	description = "";
	maxX = imaxX;
	maxY = imaxY;
	maxZ = imaxZ;
}

void Box::setMaxX(float x1, float x2, float x3, float x4) {
	float max1, max2;
	if (x1 > x2) {
		max1 = x1;
	}
	else
		max1 = x2;
	if (x3 > x4) {
		max2 = x3;
	}
	else
		max2 = x4;
	if (max1 > max2) {
		maxX = max1;
	}
	else
		maxX = max2;
}

void Box::setMaxY(float y1, float y2, float y3, float y4) {
	float max1, max2;
	if (y1 > y2) {
		max1 = y1;
	}
	else
		max1 = y2;
	if (y3 > y4) {
		max2 = y3;
	}
	else
		max2 = y4;
	if (max1 > max2) {
		maxY = max1;
	}
	else
		maxX = max2;
}

void Box::setMinX(float x1, float x2, float x3, float x4) {
	float min1, min2;
	if (x1 > x2) {
		min1 = x2;
	}
	else
		min1 = x1;
	if (x3 > x4) {
		min2 = x4;
	}
	else
		min2 = x3;
	if (min1 > min2) {
		maxX = min2;
	}
	else
		maxX = min2;
}

void Box::setMinY(float y1, float y2, float y3, float y4) {
	float min1, min2;
	if (y1 > y2) {
		min1 = y2;
	}
	else
		min1 = y1;
	if (y3 > y4) {
		min2 = y4;
	}
	else
		min2 = y3;
	if (min1 > min2) {
		maxY = min2;
	}
	else
		maxX = min1;
}

float Box::getMaxX() {
	return maxX;
}

float Box::getMaxY() {
	return maxY;
}

float Box::getMaxZ() {
	return maxZ;
}

float Box::getMinX() {
	return minX;
}

float Box::getMinY() {
	return minY;
}

float Box::getHeight()const {
	return maxZ;
}

float Box::getLength()const {
	return maxX - minX;
}

float Box::getWidth()const {
	return maxY - minY;
}

string Box::getDescription()const {
	return description;
}

float Box::getVolume()const {
	return getHeight() * getLength() * getWidth();
}

void Box::setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height) {
	description = func_description;
	maxZ = func_height;
	setMaxX(func_x1, func_x2, func_x3, func_x4);
	setMaxY(func_y1, func_y2, func_y3, func_y4);
	setMinY(func_x1, func_x2, func_x3, func_x4);
	setMinY(func_y1, func_y2, func_y3, func_y4);
	
}

Box getMinContainer(Box funcBox[]) {
	float allMaxX = 0, allMaxY = 0, allMaxZ = 0;
	for (int i = 0; i < COUNT_BOXES; i++) {
		if (i == 0)
			allMaxX = funcBox[i].getMaxX();

		else if (funcBox[i].getMaxX() > allMaxX)
			allMaxX = funcBox[i].getMaxX();
	}

	for (int j = 0; j < COUNT_BOXES; j++) {
		if (j == 0)
			allMaxY = funcBox[j].getMaxY();

		else if (funcBox[j].getMaxY() > allMaxY)
			allMaxY = funcBox[j].getMaxY();
	}

	for (int h = 0; h < COUNT_BOXES; h++) {
		if (h == 0)
			allMaxZ = funcBox[h].getMaxZ();

		else if (funcBox[h].getMaxZ() > allMaxZ)
			allMaxX = funcBox[h].getMaxZ();
	}

	return Box(allMaxX, allMaxY, allMaxZ);
}

istream& operator>>(istream& input, Box& funcBox); // insertion operator overloaded function prototype
ostream& operator<<(ostream& output, Box& funcBox); // extraction operator overloaded function prototype

void loadBoxes(Box funcBox[]) {
	for (int i = 0; i < COUNT_BOXES; i++) {
		cout << "Enter Box " << i + 1 << ": " << endl;
		cin >> funcBox[i];
		cin.ignore();
		cout << endl;
	}
}

void printBoxes(Box funcBox[], float &totalVolume) {
	cout << left << setw(10) << "Box#" << left << setw(17) << "Description" << left << setw(17) << "Volume(cu/units)" << endl;
	for (int j = 0; j < COUNT_BOXES; j++) {
		cout << left << setw(10) << j + 1 << left << setw(17) << funcBox[j].getDescription() << left << setw(17) << funcBox[j].getVolume() << endl;
		totalVolume += funcBox[j].getVolume();
	}
	cout << "Total Volume of the boxes is: " << fixed << setprecision(1) << totalVolume << endl;
}

void printResults(Box funcBox[], Box smallest) {
	cout << endl << "Minimum container specifications: " << endl;

	cout << smallest;
}


int main()
{
	//declare an array to hold objects of type Box
	Box boxArray[10];
	float totalVolume = 0;

	//call a global function to load the user input floato each object -- use overloaded stream extraction operator
	loadBoxes(boxArray);

	//call a global function to prfloat results for part #1 and #2
	printBoxes(boxArray, totalVolume);
	Box smallestContainer = getMinContainer(boxArray);
	//call a global function to prfloat results for part #3 -- use overloaded stream insertion operator
	printResults(boxArray, smallestContainer);
	//print the results for part #4
}

// extraction operator overloaded function definition
istream& operator>>(istream& input, Box& funcBox) {
	string description;
	float x1, x2, x3, x4, y1, y2, y3, y4, height;
	getline(input, description);
	input >> x1; // input floato first x
	input >> y1; // input floato first y
	input >> x2; // etc
	input >> y2;
	input >> x3;
	input >> y3;
	input >> x4;
	input >> y4;
	input >> height;
	funcBox.setData(description, x1, y1, x2, y2, x3, y3, x4, y4, height);
	return input;
}
// insertion operator overloaded function definition - print Box contents in prompt format
ostream& operator<<(ostream& output, Box& funcBox) {
	output << "Length: " << funcBox.getMaxX() << "Width: " << funcBox.getMaxY() << "Height: " << funcBox.getMaxZ() << "Volume: " << funcBox.getVolume() << endl;
	return output;
}

/*

Results go here!

*/