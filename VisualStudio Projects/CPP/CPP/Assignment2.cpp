//--------------------------------------------------------//
// Name:  Chris Kruki                                     //
// Assignment: #2                                         //
//--------------------------------------------------------//

#define COUNT_BOXES 10
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
	void setLength();
	void setWidth();
	void setLength(float ilength);
	void setWidth(float iwidth);
	void setHeight(float iheight);

	float getMaxX()const;
	float getMaxY()const;
	float getMinX()const;
	float getMinY()const;
	float getHeight()const;
	float getLength()const;
	float getWidth()const;
	float getVolume()const;		// must be used
	string getDescription()const;
	void setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height);
private:
	string description;
	float maxX, maxY, minX, minY, maxZ, length, width, height;
};

Box::Box() {
	description = "";
	length = 0;
	width = 0;
	height = 0;
	maxX = 0;
	maxY = 0;
	minX = 0;
	minY = 0;
}

Box::Box(float imaxX, float imaxY, float imaxZ) {
	description = "";
	length = imaxX;
	width = imaxY;
	height = imaxZ;
	maxX = length;
	maxY = width;
}

void Box::setLength() {
	length = maxX - minX;
}

void Box::setLength(float ilength) {
	length = ilength;
}

void Box::setWidth() {
	width = maxY - minY;
}

void Box::setWidth(float iwidth) {
	width = iwidth;
}

void Box::setHeight(float iheight) {
	height = iheight;
}


void Box::setMaxX(float x1, float x2, float x3, float x4) {
	float max1, max2;
	if (x1 >= x2) {
		max1 = x1;
	}
	else {
		max1 = x2;
	}
	if (x3 >= x4) {
		max2 = x3;
	}
	else {
	max2 = x4;
	}
	if (max1 >= max2) {
		maxX = max1;
	}
	else {
		maxX = max2;
	}
}

void Box::setMaxY(float y1, float y2, float y3, float y4) {
	float max1, max2;
	if (y1 >= y2) {
		max1 = y1;
	}
	else {
		max1 = y2;
	}
	if (y3 >= y4) {
		max2 = y3;
	}
	else {
		max2 = y4;
	}
	if (max1 >= max2) {
		maxY = max1;
	}
	else {
	maxY = max2;
	}
}

void Box::setMinX(float x1, float x2, float x3, float x4) {
	float min1, min2;
	if (x1 >= x2) {
		min1 = x2;
	}
	else
		min1 = x1;
	if (x3 >= x4) {
		min2 = x4;
	}
	else
		min2 = x3;
	if (min1 >= min2) {
		minX = min2;
	}
	else
		minX = min1;
}

void Box::setMinY(float y1, float y2, float y3, float y4) {
	float min1, min2;
	if (y1 >= y2) {
		min1 = y2;
	}
	else
		min1 = y1;
	if (y3 >= y4) {
		min2 = y4;
	}
	else
		min2 = y3;
	if (min1 >= min2) {
		minY = min2;
	}
	else
		minY = min1;
}


float Box::getMaxX()const {
	return maxX;
}

float Box::getMaxY()const {
	return maxY;
}

float Box::getMinX()const {
	return minX;
}

float Box::getMinY()const {
	return minY;
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
	return getHeight() * getLength() * getWidth();
}

void getMinContainer(Box funcBox[], Box &allBox) {
	float allMaxX = 0, allMaxY = 0, allMaxZ = 0;
	for (int i = 0; i < COUNT_BOXES; i++) {
		if (funcBox[i].getMaxX() >= allMaxX) {
			allMaxX = funcBox[i].getMaxX();
		}
	}

	for (int j = 0; j < COUNT_BOXES; j++) {
		if (funcBox[j].getMaxY() >= allMaxY) {
			allMaxY = funcBox[j].getMaxY();
		}
	}

	for (int h = 0; h < COUNT_BOXES; h++) {
		if (funcBox[h].getHeight() >= allMaxZ) {
			allMaxZ = funcBox[h].getHeight();
		}
	
	}
	
	allBox.setLength(allMaxX);
	allBox.setWidth(allMaxY);
	allBox.setHeight(allMaxZ); // why do these not work???
}

void Box::setData(string func_description, float func_x1, float func_y1, float func_x2, float func_y2, float func_x3, float func_y3, float func_x4, float func_y4, float func_height) {
	description = func_description;
	setMaxX(func_x1, func_x2, func_x3, func_x4);
	setMaxY(func_y1, func_y2, func_y3, func_y4);
	setMinY(func_x1, func_x2, func_x3, func_x4);
	setMinY(func_y1, func_y2, func_y3, func_y4);;
	setLength();
	setWidth();
	height = func_height;
}

// operator<< and >> overloaded function prototypes
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

// prints the box# description and volume of each of the boxes
void printBoxes(Box funcBox[], float &totalVolume) {
	cout << left << setw(10) << "Box#" << left << setw(17) << "Description" << left << setw(17) << "Volume(cu/units)" << endl;
	for (int j = 0; j < COUNT_BOXES; j++) {
		cout << left << setw(10) << j + 1 << left << setw(17) << funcBox[j].getDescription() << left << setw(17) << funcBox[j].getVolume() << endl;
		totalVolume += funcBox[j].getVolume();
	}
	cout << "Total Volume of the boxes is: " << fixed << setprecision(1) << totalVolume << endl;
}

// prints minimum container specs
void printResults(Box allBox) {
	cout << endl << "Minimum container specifications: " << endl;
	cout << allBox; 
}

int main()
{
	//declare an array to hold objects of type Box
	Box boxArray[10];
	Box allBox;
	float totalVolume = 0;

	//call a global function to load the user input floato each object -- use overloaded stream extraction operator
	loadBoxes(boxArray);

	//call a global function to prfloat results for part #1 and #2

	printBoxes(boxArray, totalVolume);

	//call a global function to prfloat results for part #3 -- use overloaded stream insertion operator
	getMinContainer(boxArray, allBox);
	printResults(allBox);

	//print the results for part #4
	float efficiency = allBox.getVolume() / totalVolume * 100;
	
	if (efficiency >= 90)
		cout << "The layout is efficient, it uses " << fixed << setprecision(1) << efficiency << "% of the space.";
	else
		cout << "The layout is not efficient, it wastes " << fixed << setprecision(1) << 100 - efficiency << "% of the space.";
}

// extraction operator overloaded function definition
istream& operator>>(istream& input, Box& funcBox) {
	string description;
	float x1, x2, x3, x4, y1, y2, y3, y4, height;
	getline(input, description);
	input >> x1; // input into first x
	input >> y1; // input into first y
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
ostream& operator<<(ostream& output, Box &funcBox) {
	output << "Length: " << funcBox.getLength() << "  Width: " << funcBox.getWidth() << "  Height: " << funcBox.getHeight() << "  Volume: " << funcBox.getVolume() << endl << endl;
	return output;
}

/*
Enter Box 1:
Standard tools
0 0 0 5 14 5 14 0 5

Enter Box 2:
Metric tools
0 10 5 10 5 5 0 5 5

Enter Box 3:
Plastic parts
10 10 10 5 5 5 5 10 5

Enter Box 4:
Steel parts
13 7 10 7 10 8 13 8 3.8

Enter Box 5:
Aluminum parts
10 5 10 7 15 7 15 5 4.5

Enter Box 6:
Rubber gaskets
0 14 4 10 0 10 4 14 4

Enter Box 7:
Large bags
4 10 8 10 8 14 4 14 4

Enter Box 8:
Small bags
8 10 8 14 12 14 12 10 4.5

Enter Box 9:
Sealant
14 8 14 9 10 8 10 9 5

Enter Box 10:
Liquid nitrogen
10 9 10 10 11 10 11 9 5

Box#      Description      Volume(cu/units)
1         Standard tools   350
2         Metric tools     125
3         Plastic parts    250
4         Steel parts      49.4
5         Aluminum parts   135
6         Rubber gaskets   64
7         Large bags       128
8         Small bags       216
9         Sealant          70
10        Liquid nitrogen  55
Total Volume of the boxes is: 1442.4

Minimum container specifications:
Length: 15.0  Width: 14.0  Height: 5.0  Volume: 1050.0
The layout is not efficient, it wastes 72.8% of the space.
*/