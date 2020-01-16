#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//template add function, takes type T parameters, returns type T given
template <typename T>
T add(T n1, T n2) {
	return n1 + n2;
}

// asks for input of two integers, two floats, and two strings and prints the addition of them
int main() {
	int i1 = 5, i2 = 15;
	cout << "Add: " << add(i1, i2) << endl;

	float f1 = 22.5, f2 = 11.255;
	cout << "Add: " << add(f1, f2) << endl;

	string str1 = "apple", str2 = "banana";
	cout << "Add: " << add(str1, str2) << endl;

	system("pause");
}

