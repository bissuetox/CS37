#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void reduce(float &height, float &length, float &depth);
float volume(float &height, float &length, float &depth);

/* program that retrieves the height length and depth of a cuboid, halves the values
then prints the halved values */
void main() {
	float height, length, depth, vol;
	cout << "Enter a height, length, and depth of a cuboid: ";
	cin >> height >> length >> depth;
	reduce(height, length, depth);
	vol = volume(height, length, depth);
	cout << "Height: " << setprecision(1) << fixed << height << endl;
	cout << "Length: " << setprecision(1) << fixed << length << endl;
	cout << "Depth: " << setprecision(1) << fixed << depth << endl;
	cout << "Volume: " << setprecision(1) << fixed << vol << endl;

	system("pause");
}

// function that halves all of the parameters given
void reduce(float &height, float &length, float &depth) {
	height = height / 2;
	length = length / 2;
	depth = depth / 2;
}

// function that returns the volume of the 3 parameters given
float volume(float &height, float &length, float &depth) {
	return height * length * depth;
}
