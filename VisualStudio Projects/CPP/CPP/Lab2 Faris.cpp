#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float gradeAverage(float g1, float g2, float g3) {
	float avg = (g1 + g2 + g3) / 3;
	return avg;
}

int main() {
	string name;
	float num1, num2, num3, avg;

	cout << "Enter your full name: ";
	getline(cin, name);

	cout << "Enter 3 grades separated by spaces: ";
	cin >> num1 >> num2 >> num3;

	avg = gradeAverage(num1, num2, num3);
	cout << name << ": " << setprecision(1) << fixed << avg;
}

