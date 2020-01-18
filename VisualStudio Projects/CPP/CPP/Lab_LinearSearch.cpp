#include <iostream>
using namespace std;

int arraySearch(int iArray[], int iArraySize, int Search) {
	int match = -1;
	for(int i = 0; i < iArraySize; i++) {
		if (iArray[i] == Search) {
			match = i;
		}
	}
	return match;
}

int main() {
	int numArray[5] = { 1,5,2,3,78 };
	cout << "Array: ";
	for (int j = 0; j < 5; j++) {
		cout << numArray[j] << " ";
	}
	cout << endl;

	cout << "Searching array for 6: Index = " << arraySearch(numArray, 5, 6) << endl;
	cout << "Searching array for 1: Index = " << arraySearch(numArray, 5, 1) << endl;
	cout << "Searching array for 3: Index = " << arraySearch(numArray, 5, 3) << endl;
}