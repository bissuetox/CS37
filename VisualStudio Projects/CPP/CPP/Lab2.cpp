#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//program that calculates the average of 3 grades

float gradeAverage(float num1, float num2, float num3);

int main() {
	string name;
	float grade1, grade2, grade3, average;

	cout << "Enter your full name: ";
	getline(cin, name);
	cout << "Enter 3 grades separated by spaces: ";
	cin >> grade1 >> grade2 >> grade3;
	average = gradeAverage(grade1, grade2, grade3);
	cout << name << ": " << setprecision(1) << fixed << average;
}

// calculates grade average and returns a float
float gradeAverage(float num1, float num2, float num3) {
	float average = (num1 + num2 + num3) / 3;
	return average;
}