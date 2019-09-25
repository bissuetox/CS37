#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void doubleHL(float *num1, float *num2);
float calcRect(float num1, float num2);

// main function that gets height and length, doubles it, then prints the enlarged height and length and the area
void main() {
	float height, length, area;
	cout << "Enter a height and length of a rectangle: ";
	cin >> height >> length;

	doubleHL(&height, &length);
	area = calcRect(height, length);
	cout << "Height: " << height << endl;
	cout << "Length: " << length << endl;
	cout << "Area: " << area << endl;
}

// function that takes pointers and doubles those values
void doubleHL(float *num1, float *num2) {
	*num1 = *num1 * 2;
	*num2 = *num2 * 2;
}

// function that takes two floats and returns the area of them
float calcRect(float num1, float num2) {
	float area = num1 * num2;
	return area;
}