#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//inline function example
/*
inline int doubleIt(int num) {
	return num + num;
}

int main() {
	
	int myNum;
	cout << "Enter an integer: ";
	cin >> myNum;
	cout << "New myNum: " << doubleIt(myNum) << endl;
	system("Pause");
}
*/

//default parameter example
/*
int perimeter(int side1 = 1, int side2 = 1, int side3 = 1, int side4 = 1);

int main() {
	int mside1 = 5;
	int mside2 = 10;
	int mside3 = 7;
	
	cout << "Perimeter default: " << perimeter() << endl;
	cout << "Perimeter - 1 side : " << perimeter(mside1) << endl;
	cout << "Perimeter - 2 sides : " << perimeter(mside1, mside2) << endl;
	cout << "Perimeter - 3 side : " << perimeter(mside1, mside2, mside3) << endl;
	system("pause");
}

// calculate the perimeter of a shape
int perimeter(int side1, int side2, int side3, int side4) {
	return side1 + side2 + side3 + side4;
}
*/

/*
//overloaded functions illustrated
int doubleIt(int num1);
double doubleIt(double num1);
int doubleIt(int num1, int num2);
double doubleit(double num1, double num2);

int main() {
	cout << doubleIt(5) << endl;
	cout << doubleIt(10, 20) << endl;
	cout << doubleIt(2.5) << endl;
	cout << doubleIt(7.2, 13.9) << endl;
	system("pause");
}

int doubleIt(int num1) {
	return num1 * 2;
}

double doubleIt(double num1) {
	return num1 * 2;
}

int doubleIt(int num1, int num2) {
	return num1 * 2 + num2 * 2;
}

double doubleIt(double num1, double num2) {
	return num1 * 2 + num2 * 2;
}

*/

/*
//template example

template <typename T>
T getSmaller(T val1, T valt2) { // the variable types passed will be assigned to the type of T
	return (val1 < val2) ? val1 : val2;
}

int main() {
	int i1, i2 = 10;
	cout << "getSmaller with 10 and 10: " << getSmaller(i1, i2) << endl;
	double d1 = 2.3, d2 = 2.29;
	cout << "getSmaller with 2.3 and 2.29: " << getSmaller(d1, d2) << endl;
	char a1 = 'A', a2 = 'a';
	cout << "getSmaller with A and a: " << getSmaller(a1, a2) << endl;

}
*/

//another template example
template <typename T, typename U>
int compare(const T& val1, const T& val2) {
	if (val1 < val2) return -1;
	if (val1 > val2) return 1;
	return 0;
}