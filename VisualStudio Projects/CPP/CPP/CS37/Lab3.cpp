#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int calculate_volume(int length, int height = 5, int depth = 4 );

int main() {
	int length, depth, height;

	cout << "Enter the length of a rectangular prism: ";
	cin >> length;
	cout << "Volume: " << calculate_volume(length) << endl;

	cout << "Enter the length and height of a rectangular prism: ";
	cin >> length >> height;
	cout << "Volume: " << calculate_volume(length, height) << endl;

	cout << "Enter the length, height, and depth of a rectangular prism: ";
	cin >> length >> height >> depth;
	cout << "Volume: " << calculate_volume(length, height, depth) << endl;
	system("pause");
}

int calculate_volume(int length, int height, int depth) {
	return length * height * depth;
}