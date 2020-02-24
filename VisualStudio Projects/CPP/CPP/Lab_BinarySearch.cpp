#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);
void printArray(int arr[], int size);

int main() {
	int arr[] = {1, 4, 7, 9, 12, 15, 16, 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	int search = 9;
	cout << "Array:" << endl;
	printArray(arr, n);

	cout << "Searh index for 9: " << binarySearch(arr, 0, n, search);
}

int binarySearch(int arr[], int l, int r, int x) {
	if (l <= r) {						// If array has atleast 2 elements, otherwise array would be x
		int mid = l + ((r - l) / 2);	// Middle index is left + half of right index (right index is r - 1 since index starts at 0 and r is passed as # of elements)

		if (arr[mid] == x) {
			return mid;
		}
		
		if (arr[mid] > x) {				// If middle element < x, Search the portion to the left of mid
			return binarySearch(arr, l, mid - 1, x);
		}

		return binarySearch(arr, mid + 1, r, x);

	}
	return -1;							// This will be reached if element is not present in array
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}