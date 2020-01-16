#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	/*
	int var1 = 5;
	int* iPtr = &var1;
	int mArray[1000] = { 0 };

	for (int i = 100; i > 0; i--)
		cout << "shit" << right << setw(25);

	*/
	/*
	int totalTimes = 0;
	for (int i = 1; i < 3; i++) {
		for (int j = 1; j < 3; j++) {
			for (int k = 1; k < 3; k++) {
				cout << "Outer: " << i << endl;
				cout << "Mid: " << j << endl;
				cout << "Inner: " << k << endl;
				cout << "-----------------" << endl;
			}
		}
	}
	*/

	int iVal = 1024;
	int* ptrVal = &iVal;

	int &refVal = iVal // &refVal is a reference type value
	}
}