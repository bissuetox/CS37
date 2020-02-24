#include <iostream>
using namespace std;

void selectionSort(int arr[], int size);
void swap(int& num1, int& num2);
void printArray(int arr[], int size);

int main() {
	int arr[] = { 5, 3, 9, 7, 6, 10, 12, 1, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Array before sort: " << endl;
	printArray(arr, n);
	selectionSort(arr, n);
	cout << endl << "Array after sort: " << endl;
	printArray(arr, n);

	
}

void selectionSort(int arr[], int size) {
	int i, j, min_idx;

	for (i = 0; i < size; i++) {				// Loop through whole array
		min_idx = i;							// Set min index to i - edge of sorted area - starts at very left
		for (j = i + 1; j < size; j++) {		// Loop through elem after i till the end
			if (arr[j] < arr[min_idx]) {		// If looped element is smaller than the current min
				min_idx = j;					// then set the min to it
			}
		}
		swap(arr[min_idx], arr[i]);				// After sorting through to find min idx, swap ith array elem and the min idx elem
	}
}

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}