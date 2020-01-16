#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function prototypes
int add(int num1, int num2);
float add(float num1, float num2);
string add(string str1, string str2);

// asks for two integers and print addition of them, asks for two floats and prints the addition
// asks fro two strings and prints the addition of them
int main() {
	int i1, i2;
	cout << "Enter two integers: ";
	cin >> i1 >> i2;
	cout << "Add: " << add(i1, i2) << endl;

	float f1, f2;
	cout << "Enter two floats: ";
	cin >> f1 >> f2;
	cout << "Add: " << add(f1, f2) << endl;

	string str1, str2;
	cout << "Enter two strings:";
	cin >> str1 >> str2;
	cout << "Add: " << add(str1, str2) << endl;

	system("pause");
}
// int addition
int add(int num1, int num2) {
	return num1 + num2;
}
// float addition
float add(float num1, float num2) {
	return num1 + num2;
}
// string add
string add(string str1, string str2) {
	return str1 + str2;
}