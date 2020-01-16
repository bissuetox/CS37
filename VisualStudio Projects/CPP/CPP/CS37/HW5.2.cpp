#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


class Cuboid {
public:
	Cuboid();
	Cuboid(int iheight, int ilength, int iwidth);
	void setHeight(int iheight);
	void setLength(int ilength);
	void setWidth(int iwidth);
	int getHeight();
	int getLength();
	int getWidth();
	int getVolume();
	float getSurfaceArea();
	void incDims(int increase);
private:
	int height, length, width;
};

Cuboid::Cuboid() {
	height = 0;
	length = 0;
	width = 0;
}

Cuboid::Cuboid(int iheight, int ilength, int iwidth) {
	height = iheight;
	length = ilength;
	width = iwidth;
}

// functions that set the dimensions as the passed value
void Cuboid::setHeight(int iheight){
	height = iheight;
}

void Cuboid::setLength(int ilength) {
	length = ilength;
}

void Cuboid::setWidth(int iwidth) {
	width = iwidth;
}

// functions that return the dimensions
int Cuboid::getHeight(){
return height;
}

int Cuboid::getLength() {
	return length;
}

int Cuboid::getWidth() {
	return width;
}

// function that returns the volume
int Cuboid::getVolume() {
	return float(height * width * length);
}

// function that returns the surface area
float Cuboid::getSurfaceArea() {
	return 2 * (width * length) + 2 * (width * height) + 2 * (length * height);
}

// function taht increases all of the cuboid dimensions by the passed value
void Cuboid::incDims(int increase) {
	height = height + increase;
	length = length + increase;
	width = width + increase;
}

// global function that calls the passed cuboid class's increase dimension function with the passed increase integer
void globalIncDims(Cuboid &cube, int &increase) {
	cube.incDims(increase);
}


// main function that declares a cube and initializes it when called, declares an array of 2 cuboids, prompts for values for the dimensions,
// then prints the dimensions, volume, and surface area of all 3 cuboid objects
int main() {
	Cuboid cube1(5, 10, 10);
	Cuboid cubeArray[2];

	for (int i = 0; i < 2; i++) {
		int tempHeight, tempLength, tempWidth, tempIncrease;
		cout << "Enter height: ";
		cin >> tempHeight;
		cubeArray[i].setHeight(tempHeight);

		cout << "Enter length: ";
		cin >> tempLength;
		cubeArray[i].setLength(tempLength);

		cout << "Enter Width: ";
		cin >> tempWidth;
		cubeArray[i].setWidth(tempWidth);
		
		cout << "How much to increase dimensions by: ";
		cin >> tempIncrease;
		globalIncDims(cubeArray[i], tempIncrease);
	}

	cout << "\nCuboid default dimensions (H,L,W): " << cube1.getHeight() << " " << cube1.getLength() << " " << cube1.getWidth() << endl;
	cout << "Cuboid default Volume: " << cube1.getVolume() << endl;
	cout << "Cuboid default Surface Area: " << cube1.getSurfaceArea() << endl << endl;

	cout << "Cuboid array 1 dimensions (H,L,W): " << cubeArray[0].getHeight() << " " << cubeArray[0].getLength() << " " << cubeArray[0].getWidth() << endl;
	cout << "Cuboid array 1 Volume: " << cubeArray[0].getVolume() << endl;
	cout << "Cuboid array 1 Surface Area: " << cubeArray[0].getSurfaceArea() << endl << endl;

	cout << "Cuboid array 2 dimensions (H,L,W) : " << cubeArray[1].getHeight() << " " << cubeArray[1].getLength() << " " << cubeArray[1].getWidth() << endl;
	cout << "Cuboid array 2 Volume: " << cubeArray[1].getVolume() << endl;
	cout << "Cuboid array 2 Surface Area: " << cubeArray[1].getSurfaceArea() << endl;
}